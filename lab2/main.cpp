#include "string.hpp"
#include <iostream>


//8.	��������� ����� � ������ � �����
std::ostream& operator<<(std::ostream& out, const String& text)
{
	for (int i = 0; i < text.m_size; i++)
	{
		out << text.m_text[i];
	}
	out << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, String& text)
{
	char* intermediate = new char[10000];
	in >> intermediate;
	size_t C = -1;
	for (int i = 0; i < 10000; i++)
	{
		if (intermediate[i] == '\0')
		{
			C = i;
			break;
		}
	}
	delete text.m_text;
	text.m_size = C;
	text.m_text = new char[text.m_size + 1];
	std::copy(intermediate, intermediate + text.m_size, text.m_text);
	delete[] intermediate;
	return in;
}

int main()
{
	setlocale(LC_ALL, "rus");
	String str1("012ooo3456"); std::cout << "���������� #1 str1: " << str1;
	String str2('o',3);  std::cout << "����������� #2 str2: " << str2;
	String str3(str1); std::cout << "����������� ����������� str3: " << str3;
	str3 = str2; std::cout << "����������� ������������ ������������ str3: " << str3;
	str3 = str2 + str1; std::cout << "�������� + str3: " << str3;
	str3 += str2; std::cout << "�������� += str3: " << str3;
	std::cout << "�������� [] str1[1]= " << str1[1]; str1[1] = '7'; std::cout << " str1[1]= " << str1[1] << "\n";

	String str4("12345");
	String str5("125456");
	std::cout << "��������� <, >, ==:\n" << "str4: " << str4 << "str5: " << str5;
	if (str5 < str4)
	{
		std::cout << "str5<str4\n";
	}
	else if (str5 == str4)
	{
		std::cout << "str5=str4\n";
	}
	else std::cout << "str5>str4\n";

	String str6;
	std::cout << "������� ������\n";
	std::cin >> str6;
	std::cout << "���� ������: " << str6;
	std::cout << "����� ����� ������ (����� length): " << str6.length() << "\n";

	std::cout << "����� find: " << str1.find(str2) << "\n";
	std::cout << "����� at: " << str1.at(2);

	return 0;
}