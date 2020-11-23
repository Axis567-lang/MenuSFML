#pragma once
#include <sfml\Graphics.hpp>
#define MAX_ITEMS 3 //start leaderboatd exit

class Menu
{
public:
	Menu(float width, float height, bool confirmed = false);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void mainMenu(float width, float height);
	void otherMenu(float width, float height);
	int GetPressedItem() { return selectedItem; }

private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEMS], roomMenu[MAX_ITEMS];
};

