#include "set.h"

setElement::setElement(int Value)
{
	m_data = Value;
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
	bool found = false;
	setElement* tempNext = m_root;
	while (!found)
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
			if (tempNext->m_leftNode == nullptr)
			{
				tempNext->m_leftNode = newElement;
				found = true;
			}
		}
		else
		{
			if (tempNext->m_rightNode == nullptr)
			{
				tempNext->m_rightNode = newElement;
				found = true;
			}
		}
	}
	m_size++;
}

void set::erase(int value)
{
	bool found = false;
	setElement* tempParent = nullptr;
	setElement* temp = m_root;
	while (!found)
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
	setElement* lastNode = temp;
	while (lastNode->m_leftNode != nullptr)
	{
		lastNode = lastNode->m_leftNode;
	}
	if (tempParent->m_rightNode == temp)
	{
		tempParent->m_rightNode = lastNode;
		delete temp;
		return;
	}
	tempParent->m_leftNode = lastNode;
	delete temp;
}

bool set::find(int number)
{
	setElement* temp = m_root;
	bool found = false;
	while (!found)
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