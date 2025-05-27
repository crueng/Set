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
	s.emplace(10);
	s.emplace(11);
	s.emplace(4);
	s.emplace(6);
	s.emplace(3);
	s.erase(4);
	s.erase(6);
	if (s.find(6) == true)
	{
		print("Successful");
		return 0;
	}
	print("Not Successful");
}