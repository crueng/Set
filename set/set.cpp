#include "set.h"
#include <iostream>

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
	if (m_root == nullptr)
	{
		setElement* newElement = new setElement(value);
		m_root = newElement;
		return;
	}
	setElement* newElement = new setElement(value);
	setElement* tempNext = m_root;
	while (true)
	{
		if (tempNext == nullptr)
		{
			break;
		}
		if (tempNext->m_data == value)
		{
			break;
		}
		if (tempNext->m_data < value)
		{
			if (tempNext->m_rightNode == nullptr)
			{
				tempNext->m_rightNode = newElement;
				return;
			}
			tempNext = tempNext->m_rightNode;
		}
		else
		{
			if (tempNext->m_leftNode == nullptr)
			{
				tempNext->m_leftNode = newElement;
				return;
			}
			tempNext = tempNext->m_leftNode;
		}
	}
	tempNext = newElement;
	m_size++;
}

void set::erase(int value)
{
	if (!find(value))
	{
		return;
	}
	setElement* tempParent = nullptr;
	setElement* temp = m_root;
	while (true)
	{
		if (temp->m_data == value)
		{
			break;
		}
		if (temp->m_data < value)
		{
			if (temp->m_rightNode == nullptr)
			{
				return;
			}
			tempParent = temp;
			temp = temp->m_rightNode;
			continue;
		}
		if (temp->m_data > value)
		{
			if (temp->m_leftNode == nullptr)
			{
				return;
			}
			tempParent = temp;
			temp = temp->m_leftNode;
			continue;
		}
	}
	setElement* elementToFind = nullptr;
	if (temp->m_rightNode == nullptr)
	{
		tempParent->m_rightNode = elementToFind;
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
		return;
	}
	elementToFind->m_leftNode = temp->m_leftNode;
	tempParent->m_leftNode = elementToFind;
	delete temp;
	m_size--;
}

bool set::find(int number)
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
	setElement* temp = m_root;
	while (m_size != 0)
	{
		if (temp == nullptr)
		{
			temp = m_root;
		}
		if (temp->m_leftNode != nullptr)
		{
			temp = temp->m_leftNode;
			continue;
		}
		if (temp->m_rightNode != nullptr)
		{
			temp = temp->m_rightNode;
		}
		delete temp;
	}
}