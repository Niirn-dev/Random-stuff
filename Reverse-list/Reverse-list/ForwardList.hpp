#include <memory>
#include <iostream>

namespace custom_list {

	class ForwardList
	{
		struct ForwardNode;

		using NodePtr = std::shared_ptr<ForwardNode>;

		struct ForwardNode
		{
			inline ForwardNode(int d) { data = d; };

			int data{ NULL };
			NodePtr nextNode{ nullptr };
		};

		NodePtr head{ nullptr };

	public:
		ForwardList();
		explicit ForwardList(std::initializer_list<int> il);

		// Disable copy ctor/assignment 'cause unique_ptr
		ForwardList(const ForwardList&) = delete;
		ForwardList& operator=(const ForwardList&) = delete;

		// Generate default move ctor/assignment
		ForwardList(ForwardList&&) = default;
		ForwardList& operator=(ForwardList&&) = default;

		friend std::ostream& operator<<(std::ostream& os, const ForwardList& l);

		void push_back(int data);

	private:
		NodePtr getLast(NodePtr currentNode);

		inline bool isEmpty();
		
	};
}