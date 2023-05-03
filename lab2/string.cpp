#include "string.hpp"
#include <iostream>


int String::find(const String& other)
{
	int count = 0;
	for (int i = 0; i < (*this).m_size; i++)
	{
		if ((*this).m_text[i] == other.m_text[count])
		{
			count++;
		}
		else count = 0;

		if (count == other.m_size)
		{
			return (i-other.m_size+1);
		}
	}
	return size_t(-1);
}

int String::length()
{
	return m_size;
}

char* String::с_str()
{
	return m_text;
}

char& String::at(const int& index)
{
	if (0 <= index and index < m_size)
	{
		return m_text[index];
	}
	else { std::cout << "Недопустимое значение!!!"; std::abort(); } //разобраться с выходом из функции
}