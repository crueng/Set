#pragma once
#include <queue>
class setElement
{
public:
	//Default constructor for a Element in the set
	setElement() = default;

	//Constructor which takes a value as an argument
	setElement(int Value);

	//stores the Data
	int m_data = 0;

	//The left node of the binary tree
	setElement* m_leftNode = nullptr;

	//The right node of the binary tree
	setElement* m_rightNode = nullptr;
};

class set : public setElement
{
public:
	//Default constructor for the set
	set() = default;

	//Deletes the whole set
	~set();
	
	//Checks whether the set is empty or not
	bool empty();

	//Returns the size of the set
	size_t size();

	//Puts the value in the set
	void emplace(int value);

	//Deletes the value in the set
	void erase(int value);

	//Finds a value in the set
	bool find(int number);

	//Clears the whole set
	void clear();

	//Prints the binary tree
	void printTree();
private:
	
	void printTree(setElement* root, std::queue<setElement*> queue = {});

	//The first value in the set
	setElement* m_root = nullptr;

	//Stores the size of the set
	size_t m_size = 0;
};