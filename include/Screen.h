#pragma once

#include <SFML/Graphics.hpp>
#include "vector"
#include "Bar.h"
#include "Grid.h"
#include "Row.h"
#include "tile.h"
#include "File.h"
#include "Images.h"

class Screen {

public:
	Screen();
	void screenMain();

private:
	Bar m_bar;
	Grid m_grid;
	File m_file;
	Images m_images;
	int m_object;
	sf::RenderWindow m_window;

	void printBackground();
	void checkEvents();
	void handleClick(const sf::Event::MouseButtonEvent&);
	void setGrid();
};