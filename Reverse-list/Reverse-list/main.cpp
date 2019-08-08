#include <iostream>
#include <conio.h>
#include <memory>

#include "ForwardList.hpp"


int main(int argc, char** argv)
{
	auto il = { 1, 2, 3 };
	auto fwdList{ std::make_unique<custom_list::ForwardList<int>>(il) };
	
	std::cout << "List values:" << *fwdList << std::endl
		<< "List size: " << fwdList->getSize() << std::endl;

	try
	{
		auto ptrNodesData{ fwdList->at(3) };

		std::cout << *ptrNodesData << std::endl;
	}
	catch (std::out_of_range e)
	{
		std::cout << e.what();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	fwdList->push_back(10);
	fwdList->reverse();

	std::cout << "List values after push_back and reverse:" << *fwdList << std::endl
		<< "List size: " << fwdList->getSize() << std::endl;

	try
	{
		auto ptrNodesData{ fwdList->at(3) };

		std::cout << *ptrNodesData << std::endl;
	}
	catch (std::out_of_range e)
	{
		std::cout << e.what();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	auto tmp = _getch();
	return argc;
}