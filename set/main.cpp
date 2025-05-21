#include <iostream>
#include "set.h"

int main()
{
	set s;
	for (int i = 0; i < 100; i++)
	{
		s.emplace(i);
	}
	if (s.find(30))
	{
		std::cout << "found\n";
		return 0;
	}
	std::cout << "not found\n";
}