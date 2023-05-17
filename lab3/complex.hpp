#pragma once
#include <iostream>

class Complex
{
private:
	double m_a;
	double m_b;
public:
	Complex(const double& a = 0.0, const double& b = 0.0) : m_a(a), m_b(b) {}
	Complex(const Complex& other) : Complex(other.m_a, other.m_b){}
	Complex& operator= (const Complex& other)
	{
		Complex intermediate = other;
		std::swap(m_a, intermediate.m_a);
		std::swap(m_b, intermediate.m_b);
		return *this;
	}
	~Complex() {}

	Complex& operator+= (const Complex& other)
	{
		m_a += other.m_a;
		m_b += other.m_b;
		return *this;
	}
	Complex operator+ (const Complex& other)
	{
		Complex intermediate = *this;
		intermediate += other;
		return intermediate;
	}

	Complex& operator*= (const Complex& other)
	{
		double a = (m_a * other.m_a) - (m_b * other.m_b);
		double b = (m_a * other.m_b) + (m_b * other.m_a);
		m_a = a; m_b = b;
		return *this;
	}
	Complex operator* (const Complex& other)
	{
		Complex intermediate = *this;
		intermediate *= other;
		return intermediate;
	}

	Complex& operator++()
	{
		this->m_a += 1;
		return *this;
	}
	Complex operator++(int)
	{
		Complex intermediate = *this;
		this->m_a += 1;
		return intermediate;
	}

	friend std::ostream& operator<< (std::ostream& out, const Complex& comp);
	friend std::istream& operator>> (std::istream& in, Complex& comp);
};