#include <iostream>
#include "AnimatedText.hpp"
#include <string>
#include <iomanip>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Введите текст\n"; 
	std::string text;
	/*std::cin >> text;*/
	std::getline(std::cin >> std::ws, text);
	std::cout << "Введите количество секунд\n";
	int sec;
	std::cin >> sec;
	AnimatedText text1(text, sec);

	sf::RenderWindow window(sf::VideoMode(1200, 900), "ok");

	int count = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		sf::Font font;
		sf::Text textOUTPUT;
		if (!font.loadFromFile("ofont.ru_Sa No Rules.ttf"))
		{
			std::cout << "Ошибка при назначении шрифта";
		}
		else
		{
			textOUTPUT.setFont(font); textOUTPUT.setFillColor(sf::Color::Green); textOUTPUT.setCharacterSize(120);
			if (count < text1.textlength())
			{
				textOUTPUT.setString(text1.Output(count));
			}
			else
			{
				textOUTPUT.setString(text1.Output(text1.textlength()));
			}
			window.draw(textOUTPUT);
			window.display();
			count += 1;
		}
	}
}