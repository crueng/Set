#pragma once
class setElement
{
public:
	setElement(int Value);
	int m_data = 0;
	setElement* m_leftNode = nullptr;
	setElement* m_rightNode = nullptr;
};

class set : public setElement
{
public:
	bool empty();
	size_t size();
	void emplace(int value);
	void erase(int value);
	bool find(int number);
private:
	setElement* m_root = nullptr;
	size_t m_size = 0;
};