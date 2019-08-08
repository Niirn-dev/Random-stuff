#include <memory>
#include <iostream>
#include <initializer_list>
#include <mutex>
#include <exception>

namespace custom_list {

	template <class T>
	class ForwardList
	{
		struct Node;
		using NodePtr = std::shared_ptr<Node>;

		struct Node
		{
			inline explicit Node(T d) { data = d; };

			T data{ T(0) };
			NodePtr nextNode{ nullptr };
		};

		NodePtr head{ nullptr };

		mutable std::mutex m;
		mutable std::size_t size{ 0 };
		mutable bool isSizeValid{ false };

	public:
		ForwardList() {};
		explicit ForwardList(T d) : 
			head(std::make_shared<Node>(d)) {};
		explicit ForwardList(std::initializer_list<T> il)
		{
			for (auto& item : il)
			{
				this->push_back(item);
			}
		};

		// Disable copy ctor/assignment 'cause unique_ptr
		ForwardList(const ForwardList&) = delete;
		ForwardList& operator=(const ForwardList&) = delete;

		// Generate default move ctor/assignment
		ForwardList(ForwardList&&) = default;
		ForwardList& operator=(ForwardList&&) = default;

		friend std::ostream& operator<<(std::ostream& os, const ForwardList& l)
		{
			auto currentNode{ l.head };

			while (currentNode != nullptr)
			{
				os << ' ' << currentNode->data;
				currentNode = currentNode->nextNode;
			}

			return os;
		};

		void push_back(T data)
		{
			if (isEmpty())
			{
				this->head = std::make_shared<Node>(data);
			}
			else
			{
				getLast(this->head)->nextNode = std::make_shared<Node>(data);
			}

			this->isSizeValid = false;
		};

		std::size_t getSize() const
		{
			std::lock_guard<std::mutex> guard(this->m);

			if (!this->isSizeValid)
			{
				this->size = 0;
				auto currentNode{ this->head };

				while (currentNode != nullptr)
				{
					++this->size;
					currentNode = currentNode->nextNode;
				}

				this->isSizeValid = true;
			}

			return this->size;
		}

		// Get a pointer to the data, that is stored in the node
		std::unique_ptr<T> at(std::size_t index) const
		{
			if (index < this->getSize()) {
				auto currentNode{ this->head };

				for (std::size_t i = 0; i < index; ++i)
				{
					currentNode = currentNode->nextNode;
				}

				return std::make_unique<T>(currentNode->data);
			}

			throw std::out_of_range("ForwardList.at(): specified index is out of range.\n");
		}

		void reverse()
		{
			NodePtr previousNode{ nullptr };
			NodePtr currentNode{ this->head };
			NodePtr nextNode{ nullptr };

			while (currentNode != nullptr)
			{
				nextNode = currentNode->nextNode;
				currentNode->nextNode = previousNode;
				previousNode = currentNode;
				currentNode = nextNode;
			}

			this->head = previousNode;
		}

	private:
		NodePtr getLast(NodePtr currentNode)
		{
			if (currentNode->nextNode == nullptr)
			{
				return currentNode;
			}
			else
			{
				return getLast(currentNode->nextNode);
			}
		};

		inline bool isEmpty() noexcept
		{
			return this->head == nullptr;
		};
	};

} // namespace custom_list