#pragma once
#include <iostream>

class String
{
private:
	size_t m_size;
	char* m_text = nullptr;
public:

	//1.	Базовый конструктор
	String() = default;
	String(int sym, size_t size) = delete;

	String(const char* text) : m_size(strlen(text)), m_text(new char[m_size + 1])
	{
		std::copy(text, text + m_size + 1, m_text);
	}
	String(char sym, size_t size = 1) : m_size(size), m_text(new char[m_size + 1])
	{
		for (int i = 0; i < m_size + 1; i++)
		{
			m_text[i] = sym;
		}
		m_text[m_size] = '\0';
	}

	//2.	Конструктор копирования(правило 3 - х)
	String(const String& other) : String(other.m_text) {}

	//3.	Оператор присваивания копированием(правило 3 - х)
	String& operator=(const String& other)
	{
		String intermediate = other;
		std::swap(m_size, intermediate.m_size);
		std::swap(m_text, intermediate.m_text);
		return*this;
	}

	//4.	Деструктор(правило 3 - х)
	~String() { if (m_text != nullptr) delete[] m_text; }

	//5	Оператор +=
	String operator+(const String& other)
	{
		String intermediate = *this;
		intermediate += other;
		return intermediate;
	}
	String& operator+= (const String& other)
	{
		String intermediate;
		intermediate.m_size = (*this).m_size + other.m_size;
		intermediate.m_text = new char[intermediate.m_size + 1];
		std::copy((*this).m_text, (*this).m_text + (*this).m_size, intermediate.m_text);
		std::copy(other.m_text, other.m_text + other.m_size, intermediate.m_text + (*this).m_size);
		intermediate.m_text[intermediate.m_size] = '\0';
		(*this) = intermediate;
		return *this;
	}

	//6.	Оператор[] – чтение и изменение элемента
	char& operator[] (const int& index)
	{
		return m_text[index];
	}

	//7.	Операторы <, >, ==
	bool operator==(const String& other)
	{
		if ((*this).m_size == other.m_size)
		{
			for (int i = 0; i < (*this).m_size; i++)
			{
				if ((*this).m_text[i] != other.m_text[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
	bool operator> (const String& other)
	{
		if (!((*this)==other))
		{
			for (int i = 0; i < std::min((*this).m_size, other.m_size); i++)
			{
				if ((*this).m_text[i] == other.m_text[i]) continue;
				else if ((*this).m_text[i] > other.m_text[i]) return true;
				else return false;
			}
			if ((*this).m_size > other.m_size)
			{
				return true;
			}
			else return false;
		}
	}
	bool operator< (const String& other)
	{
		if (!((*this) == other) and !((*this) > other))
		{
			return true;
		}
		else return false;
	}

	friend std::ostream& operator<<(std::ostream& out, const String& text);
	friend std::istream& operator>>(std::istream& in, String& text);

	//9.	Метод find – поиск первого вхождения символа в строку слева
	int find(const String& other);

	//10.	 Метод length – длина строки
	int length();

	//11.	 Метод c_str – получить массив char
	char* с_str();

	//12.	 Метод at для получения доступа(чтение и изменение) к элементу строки с проверкой на выход за пределы строки
	char& at(const int& index);
};