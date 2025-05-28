#include <iostream>
#include "set.h"

template<typename... Ts>
void print(Ts&&... ts)
{
	((std::cout << ts), ...);
}

int main()
{
	set s;
	s.emplace(4);
	s.emplace(5);
	s.emplace(2);
	s.emplace(7);
	s.emplace(6);
	s.emplace(3);
	
	s.printTree();

	s.clear();

	s.printTree();
}