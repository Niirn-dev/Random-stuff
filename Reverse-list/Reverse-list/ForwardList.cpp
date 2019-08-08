#include "ForwardList.hpp"

// #include <initializer_list>
// #include <iostream>


namespace custom_list {

/*	Moved the implementation to header file due to making a class into a template

	ForwardList::ForwardList()
	{
		std::cout << "Called default ctor of ForwardList class\n";
	};

	ForwardList::ForwardList(std::initializer_list<int> il)
	{
		std::cout << "Called init_list ctor of ForwardList class\n";
		for (auto& item : il)
		{
			this->push_back(item);
		}
	}

	std::ostream& operator<<(std::ostream& os, const ForwardList& l)
	{
		auto currentNode{ l.head };

		while (currentNode != nullptr)
		{
			os << ' ' << currentNode->data;
			currentNode = currentNode->nextNode;
		}

		return os;
	}

	void ForwardList::push_back(int data)
	{
		if (isEmpty())
		{
			this->head = std::make_shared<ForwardList::Node>(data);
		}
		else
		{
			getLast(this->head)->nextNode = std::make_shared<ForwardList::Node>(data);
		}
	}

	std::shared_ptr<ForwardList::Node> ForwardList::getLast(std::shared_ptr<ForwardList::Node> currentNode)
	{
		if (currentNode->nextNode == nullptr)
		{
			return currentNode;
		}
		else
		{
			return getLast(currentNode->nextNode);
		}
	}

	inline bool ForwardList::isEmpty()
	{
		return this->head == nullptr;
	}*/

}