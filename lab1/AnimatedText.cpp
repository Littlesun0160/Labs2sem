#include "AnimatedText.hpp"

#include <chrono>
#include <thread>

int AnimatedText::textlength()
{
	return m_text.length();
}

std::string AnimatedText::Output(int count)
{
	using namespace std::chrono;
	std::this_thread::sleep_for(std::chrono::milliseconds(m_symsec));

	std::string textOutput = "";
	for (int i = 0; i < count; i++)
	{
		textOutput += m_text[i];
	}
	return textOutput;
}