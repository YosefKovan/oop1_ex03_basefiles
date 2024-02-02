#include <SFML/Graphics.hpp>
#include "vector"
#include "Bar.h"
#include "Grid.h"
#pragma once

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

	sf::Texture m_textures[10];
	sf::Sprite m_sprites[10];

	void addImagesToVector();
	void printBackground();
	void checkEvents();
	void handleClick(const sf::Event::MouseButtonEvent&);
	
};