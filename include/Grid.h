#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Row.h"

enum LenhHeight{rows, cols};

class Grid {

public:
	Grid(const int&, const int&);
	bool isOnGrid(sf::Vector2f position);
	void updateRow(sf::Vector2f, int);
	sf::Vector2f getGridLocation(sf::Vector2f location, int& row);
	void drawGrid(sf::RenderWindow&);
	void drawImagesOnGrid(sf::RenderWindow&, sf::Sprite sprite[8]);
	void scaleImage(int, int, sf::Sprite&);
	
private:
	sf::Vector2f m_rowCols;
	sf::Vector2f m_lengthHeight;
	sf::Vector2f m_startLocation;
	sf::Vector2f m_totalGrid;
	sf::Vector2f m_sqrSize;
	
	std::vector < std::vector<sf::RectangleShape>> m_rectangles;
	std::vector<Row> m_rows;

	void setVariables();
	void createGridSquares();
	void addSquaresToVect(int, int, std::vector<sf::RectangleShape>&);
	bool checkPosInSquare(sf::Vector2f vect1, sf::Vector2f vect2);
	void deleteFromRow(sf::Vector2f, int, int);
	bool locationExists(sf::Vector2f location1, int index);
	bool locationsEqual(sf::Vector2f, sf::Vector2f);

};