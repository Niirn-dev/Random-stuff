#include <iostream>
#include <conio.h>
#include <memory>

#include "ForwardList.hpp"


int main(int argc, char** argv)
{
	auto il = { 1, 2, 3 };
	auto fwdList{ std::make_unique<custom_list::ForwardList<int>>(il) };
	
	std::cout << "List values:" << *fwdList << std::endl;

	fwdList->push_back(10);

	std::cout << "List values after push_back:" << *fwdList << std::endl;


	/*auto test{ custom_list::MyClass<int>(10) };
	std::cout << test.getData();*/

	auto tmp = _getch();
	return 0;
}