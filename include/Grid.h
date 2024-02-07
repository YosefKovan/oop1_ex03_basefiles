#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Row.h"
#include "Images.h"
#include "Tile.h"

class Grid {

public:
	Grid(const int&, const int&);
	Grid() = default;
	bool isOnGrid(sf::Vector2f position);
	void updateRow(sf::Vector2f, int);
	void drawGrid(sf::RenderWindow&);
	void drawImagesOnGrid(sf::RenderWindow&, Images &images);
	void updateTile(int, int, int);
	int getObjectInTile(int, int);
	std::vector<Row> getTotalRows();
	void tileAvailable(sf::Vector2f, int, sf::RenderWindow& window);
		
private:
	sf::Vector2f m_start;
	sf::Vector2f m_gridLenHeight;
	std::vector<Row> m_rows;

	void setVariables(int, int, int, int);
	sf::RectangleShape createSquare(sf::Vector2f, sf::Color color); //function not variable!
	void createTiles(int rows, int cols, int object = None);
	void removeAllMice();
	void dealWithTile(Tile&, int, int, int);	
	void drawSquare(sf::RenderWindow&, int, int);
};