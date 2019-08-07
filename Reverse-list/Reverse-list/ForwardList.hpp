#include <memory>
#include <iostream>
#include <initializer_list>

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
		};

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