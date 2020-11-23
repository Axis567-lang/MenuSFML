#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
/*
void NewWindow()
{
	sf::RenderWindow window2(sf::VideoMode(512, 512), "Jelo");

	Menu menuR(window2.getSize().x, window2.getSize().y, true);


	sf::Texture texture2;
	if (!texture2.loadFromFile("rocks.jpg"))
	{
		//handle error of texture
	}

	sf::Sprite background2;
	background2.setTexture(texture2);

	while (window2.isOpen())
	{
		
		window2.clear();
		window2.draw(background2);
		menuR.draw(window2);
		window2.display();
	}
}
*/
int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Jelo");

	Menu menu(window.getSize().x, window.getSize().y, false);

	sf::Texture texture;
	if (!texture.loadFromFile("black.jpg"))
	{
		//handle error of texture
	}

	sf::Sprite background;
	background.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play has been pressed" << std::endl;
						//NewWindow();
						//window.close();
						break;

					case 1:
						std::cout << "Idk has been pressed" << std::endl;
						break;

					case 2:
						std::cout << "Exit has been pressed" << std::endl;
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(background);
		menu.draw(window);
		window.display();
	}
	return 0;
}