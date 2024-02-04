#pragma once

#include <SFML/Graphics.hpp>
#include "vector"
#include "Bar.h"
#include "Grid.h"
#include "Row.h"
#include "tile.h"

class Screen {
public:
	Screen();
	void screenMain();

private:
	Bar m_bar;
	Grid m_grid;
	int m_object;
	sf::RenderWindow m_window;
	std::vector<sf::Texture> m_texture;
	std::vector<sf::Sprite> m_sprite;

	sf::Texture m_textures[11];
	sf::Sprite m_sprites[11];

	void addImagesToVector();
	void printBackground();
	void checkEvents();
	void handleClick(const sf::Event::MouseButtonEvent&);
	void setGrid();
	bool readFromFile();
	void updateRow(std::vector<Row>&, std::string, int);
	void saveToFile();
	void fillRow(Tile, std::ofstream&);
};