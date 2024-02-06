#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Row.h"
#include "Images.h"


class Grid {

public:
	Grid(const int&, const int&, std::vector<Row> rowsVect = std::vector<Row>());
	Grid() = default;
	bool isOnGrid(sf::Vector2f position);
	void updateRow(sf::Vector2f, int);
	void drawGrid(sf::RenderWindow&);
	void drawImagesOnGrid(sf::RenderWindow&, Images &images);
	std::vector<Row> getAllRows() const;
	sf::Vector2f getStartLocation() const;
	sf::Vector2f getRowsAndCols() const;
	
private:
	sf::Vector2f m_gridRowsCols;
	sf::Vector2f m_lengthHeight;
	sf::Vector2f m_startLocation;
	sf::Vector2f m_totalRighScreen;

	std::vector < std::vector<sf::RectangleShape>> m_rectangles;
	std::vector<Row> m_rows;

	void setVariables();
	void createGridSquares();
	void addSquaresToVect(int, int, std::vector<sf::RectangleShape>&);
	bool checkPosInSquare(sf::Vector2f vect1, sf::Vector2f vect2);
	void deleteFromRow(sf::Vector2f, int);
	bool locationExists(sf::Vector2f location1, int index);
	bool locationsEqual(sf::Vector2f, sf::Vector2f);
	void removeMouseFromRow(int index);
	sf::Vector2f getGridLocation(sf::Vector2f location, int& row);
};