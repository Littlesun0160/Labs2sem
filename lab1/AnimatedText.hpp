#pragma once
#include <iostream>

class AnimatedText
{
private:
	std::string m_text;
	float m_duration;
	int m_symsec;   //кол-во секунд, требуемых на определенный символ
public:
	AnimatedText(const std::string& text, int duration)
	{
		m_text = text;
		m_duration = duration;
		m_symsec = (m_duration / m_text.length()) * 1000;
	}
	~AnimatedText() {}

	int AnimatedText::textlength();
	std::string AnimatedText::Output(int count);
};


