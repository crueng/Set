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
	system("cls");
	s.emplace(11);
	system("cls");
	s.emplace(4);
	system("cls");
	s.emplace(6);
	system("cls");
	s.emplace(3);
 	system("cls");
	s.erase(4);
	system("cls");
	s.erase(6);
	if (s.find(6) == true)
	{
		print("Successful");
		return 0;
	}
	print("Not Successful");
}