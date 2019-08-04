#include "ForwardList.hpp"

#include <initializer_list>
#include <iostream>

namespace custom_list {

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
			this->head = std::make_shared<ForwardList::ForwardNode>(data);
		}
		else
		{
			getLast(this->head)->nextNode = std::make_shared<ForwardList::ForwardNode>(data);
		}
	}

	ForwardList::NodePtr ForwardList::getLast(NodePtr currentNode)
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
	}
	
}