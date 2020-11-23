#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height, bool confirmed)
{
	if(!confirmed)
		mainMenu(width, height);
	else
		otherMenu(width, height);
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color(60,177,255));
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 <= MAX_ITEMS)
	{
		std::cout << "JElo down" << std::endl;
		
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Green);
		
	}
}

void Menu::mainMenu(float width, float height)
{
	if (!font.loadFromFile("dogicapixel.ttf"))
	{
		//(failed to create font face) error
	}
	//
	menu[0].setFont(font);
	menu[0].setCharacterSize(30);
	menu[0].setFillColor(sf::Color(60, 177, 255));
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));
	//
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("idk");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));
	//
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));
}

void Menu::otherMenu(float width, float height)
{
	if (!font.loadFromFile("dogicapixel.ttf"))
	{
		//(failed to create font face) error
	}
	//
	roomMenu[0].setFont(font);
	roomMenu[0].setCharacterSize(30);
	roomMenu[0].setFillColor(sf::Color::White);
	roomMenu[0].setString("Room Name");
	roomMenu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	roomMenu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));
	//
	roomMenu[1].setFont(font);
	roomMenu[1].setFillColor(sf::Color::White);
	roomMenu[1].setString("Room Description");
	roomMenu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	roomMenu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));
}