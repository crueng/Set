#include "set.h"
#include <deque>
#include <iostream>
#include <vector>
#define CLS_ON true

#if CLS_ON
#define CLS system("cls")
#else
#define CLS //system("cls")
#endif

#define COMPILE_DATETIME __TIME__

setElement::setElement(int Value)
{
	m_data = Value;
}

set::~set()
{
	//clear();
}

bool set::empty()
{
	if (size() == 0)
	{
		return true;
	}
	return false;
}

size_t set::size()
{
	return m_size;
}

void set::emplace(int value)
{
	//If there is no element in the set, place the value at the root
	if (m_root == nullptr)
	{
		setElement* newElement = new setElement(value);
		m_root = newElement;
		m_size++;
		return;
	}
	setElement* newElement = new setElement(value);
	setElement* tempNext = m_root;
	while (true)
	{
		//If the value already exists in the list, return
		if (tempNext->m_data == value)
		{
			/*CLS();
			printTree(m_root);*/
			return;
		}
		//If the value is greater than the current data, go right and continue
		if (tempNext->m_data < value)
		{
			//If the right node is empty, place the value there
			if (tempNext->m_rightNode == nullptr)
			{
				tempNext->m_rightNode = newElement;
				m_size++;
				/*CLS;
				printTree(m_root);*/
				return;
			}
			tempNext = tempNext->m_rightNode;
			continue;
		}
		//If the left node is empty, place the value there, otherwise go left
		if (tempNext->m_leftNode == nullptr)
		{
			tempNext->m_leftNode = newElement;
			m_size++;
			/*CLS;
			printTree(m_root);*/
			return;
		}
		tempNext = tempNext->m_leftNode;
	}
}

void set::erase(int value)
{
	//Checks if the value exists
	if (!find(value))
	{
		/*CLS;
		printTree(m_root);*/
		return;
	}
	setElement* tempParent = nullptr;
	setElement* temp = m_root;
	while (true)
	{
		//Breaks if the value was found
		if (temp->m_data == value)
		{
			break;
		}

		//If the value is greater than the current data, go right and continue
		if (temp->m_data < value)
		{
			tempParent = temp;
			temp = temp->m_rightNode;
			continue;
		}
		//If the value is not greater than the current data, go left
		tempParent = temp;
		temp = temp->m_leftNode;
	}

	setElement* elementToFind = nullptr;
	if (temp->m_data > tempParent->m_data)
	{
		if (temp->m_rightNode == nullptr)
		{
			tempParent->m_rightNode = temp->m_leftNode;
			delete temp;
			/*CLS;
			printTree(m_root);*/
			return;
		}
		elementToFind = temp->m_rightNode;
		while (true)
		{
			if (elementToFind->m_leftNode != nullptr)
			{
				elementToFind = elementToFind->m_leftNode;
			}
			break;
		}
		elementToFind->m_leftNode = temp->m_leftNode;
		tempParent->m_rightNode = elementToFind;
		delete temp;
		/*CLS;
		printTree(m_root);*/
		return;
	}
	if (temp->m_rightNode == nullptr)
	{
		tempParent->m_leftNode = temp->m_leftNode;
		delete temp;
		/*CLS;
		printTree(m_root);*/
		return;
	}
	elementToFind = temp->m_rightNode;
	while (true)
	{
		if (elementToFind->m_leftNode != nullptr)
		{
			elementToFind = elementToFind->m_leftNode;
		}
		break;
	}
	elementToFind->m_leftNode = temp->m_leftNode;
	tempParent->m_leftNode = elementToFind;
	delete temp;
	/*CLS;
	printTree(m_root);*/
	return;
}

/*void set::erase(int value)
{
	//Checks if the value exists
	if (!find(value))
	{
		CLS
			printTree(m_root);
		return;
	}
	setElement* tempParent = nullptr;
	setElement* temp = m_root;
	while (true)
	{
		//Breaks if the value was found
		if (temp->m_data == value)
		{
			break;
		}

		//If the value is greater than the current data, go right and continue
		if (temp->m_data < value)
		{
			tempParent = temp;
			temp = temp->m_rightNode;
			continue;
		}
		//If the value is not greater than the current data, go left
		tempParent = temp;
		temp = temp->m_leftNode;
	}
	setElement* elementToFind = nullptr;
	if (temp->m_rightNode == nullptr)
	{
		tempParent->m_leftNode = temp->m_leftNode;
		CLS
			printTree(m_root);
		return;
	}
	elementToFind = temp->m_rightNode;
	while (true)
	{
		if (elementToFind->m_leftNode != nullptr)
		{
			elementToFind = elementToFind->m_leftNode;
			continue;
		}
		break;
	}
	if (tempParent->m_leftNode == temp)
	{
		elementToFind->m_leftNode = temp->m_leftNode;
		tempParent->m_leftNode = elementToFind;
		delete temp;
		m_size--;
		CLS
			printTree(m_root);
		return;
	}
	elementToFind->m_leftNode = temp->m_leftNode;
	tempParent->m_leftNode = elementToFind;
	delete temp;
	m_size--;
}
*/
bool set::find(int number) const
{
	setElement* temp = m_root;
	while (true)
	{
		if (temp->m_data == number)
		{
			return true;
		}
		if (temp->m_data < number)
		{
			if (temp->m_rightNode != nullptr)
			{
				temp = temp->m_rightNode;
				continue;
			}
			break;
		}
		if (temp->m_leftNode != nullptr)
		{
			temp = temp->m_leftNode;
			continue;
		}
		break;
	}
	return false;
}

void set::clear()
{
	if (m_root == nullptr)
	{
		return;
	}
	std::deque<setElement*> toDelete;
	std::queue<setElement*> it;
	it.emplace(m_root);
	while (!it.empty())
	{
		if (it.front()->m_leftNode != nullptr)
		{
			it.emplace(it.front()->m_leftNode);
			toDelete.emplace_front(it.front()->m_leftNode);
		}
		if (it.front()->m_rightNode != nullptr)
		{
			it.emplace(it.front()->m_rightNode);
			toDelete.emplace_front(it.front()->m_rightNode);
		}
		it.pop();
	}
	while (!toDelete.empty())
	{
		delete toDelete.front();
		toDelete.pop_front();
	}
	delete m_root;
	m_root = nullptr;
}

void set::printTree()
{
	printTree(m_root);
}

void set::printTree(setElement* root, std::queue<setElement*> queue) const
{
	queue.emplace(root);
	while (!queue.empty())
	{
		//Goes through the whole level and prints every value
		size_t it = queue.size();
		for (int i = 0; i < it; i++)
		{
			setElement* temp = queue.front();
			//If it does not exist, print "/"
			if (temp == nullptr)
			{
				std::cout << "/ ";
				queue.pop();
				continue;
			}
			std::cout << temp->m_data << " ";
			//deletes the element in the queue
			queue.pop();
			//Puts the children of the node in the queue
			queue.emplace(temp->m_leftNode);
			queue.emplace(temp->m_rightNode);
		}
		std::cout << "\n";
	}
}

void set::balanceTree()
{
	if (m_root == nullptr)
	{
		return;
	}
	std::vector<int> vec;
	setElement* currentElement = m_root;
	while (true)
	{
		if (currentElement->m_leftNode != nullptr)
		{
			vec.push_back(currentElement->m_leftNode->m_data);
			currentElement = currentElement->m_leftNode;
		}
	}
}

setElement* set::getSmallestElement() const
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	setElement* currentElement = m_root;
	while (true)
	{
		if (currentElement->m_leftNode != nullptr)
		{
			currentElement = currentElement->m_leftNode;
		}
		break;
	}
	return currentElement;
}

setElement* set::getGreatestElement() const
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	setElement* currentElement = m_root;
	while (true)
	{
		if (currentElement->m_rightNode != nullptr)
		{
			currentElement = currentElement->m_rightNode;
		}
		break;
	}
	return currentElement;
}