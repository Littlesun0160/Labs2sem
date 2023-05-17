#include <iostream>
#include "complex.hpp"

std::ostream& operator<< (std::ostream& out, const Complex& comp)
{
	if (comp.m_a != 0)
	{
		out << comp.m_a;
		if (comp.m_b != 0.0)
		{
			out << " + ";
		}
	}
	if (comp.m_b != 0.0)
	{
		out << comp.m_b << "i";
	}
	if (comp.m_a == 0 and comp.m_b == 0)
	{
		out << 0;
	}
	out << "\n";
	return out;
}
std::istream& operator>> (std::istream& in, Complex& comp)
{
	in >> comp.m_a >> comp.m_b;
	return in;
}



int main()
{
	setlocale(LC_ALL, "rus");
	Complex z1(8);
	std::cout << z1;
	Complex z2(z1);
	std::cout << z2;
	Complex z3(0, 0);
	std::cout << z3;
	z3 = z2;
	std::cout << z3;
	Complex z4(4, 5);
	Complex z5(8, 1);
	std::cout << z4 << z5;
	z5 *= z4;
	std::cout << z5;
	Complex z6 = z2 * z5;
	std::cout << z6;
	z6++;
	std::cout << z6;
	++z6;
	std::cout << z6;
	Complex z7(0,0);
	std::cin >> z7;
	std::cout << "Ваше число: " << z7;
}