#include "Grid.h"
#include <iostream>

//std::cout << object << std::endl; for debuggind

Grid::Grid(const int& rows, const int& cols) 
	: m_rowCols(rows,cols), m_sqrSize(40, 40),
	  m_totalGrid(1100,840)
{
	setVariables();
	createGridSquares();
}
//------------------------------------------
void Grid::setVariables() {

	m_lengthHeight.x = m_sqrSize.x * m_rowCols.x;
	m_lengthHeight.y = m_sqrSize.y * m_rowCols.y;

	m_startLocation.x = (m_totalGrid.x - m_lengthHeight.x) / 2.0f + 200;
	m_startLocation.y = (m_totalGrid.y - m_lengthHeight.y) / 2.0f;
}
//------------------------------------------
void Grid::createGridSquares() {

	for (int row = 0; row < m_rowCols.y; row++) {
		std::vector< sf::RectangleShape> rectangleVect;
		for (int col = 0; col < m_rowCols.x; col++) {
			addSquaresToVect(row, col, rectangleVect);
		}
		
		m_rectangles.push_back(rectangleVect);
	}			
}
//------------------------------------------
void Grid::addSquaresToVect(int row, int col, std::vector<sf::RectangleShape>& vector) {

	sf::Vector2f location;
	location.x = m_startLocation.x + col * m_sqrSize.x;
	location.y = m_startLocation.y + row * m_sqrSize.y;

	sf::RectangleShape rectangle(m_sqrSize);
	rectangle.setPosition(location);
	rectangle.setFillColor(sf::Color(255, 255, 255, 128));
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	vector.push_back(rectangle);
}
//------------------------------------------
bool Grid::isOnGrid(sf::Vector2f position) {

	if (position.x >= m_startLocation.x &&
		position.x <= m_startLocation.x + m_lengthHeight.x) {
		if (position.y >= m_startLocation.y &&
			position.y <= m_startLocation.y + m_lengthHeight.y) {
			return true;
		}
	}
	
	return false;
}
//------------------------------------------
void Grid::updateRow(sf::Vector2f location, int object) {
	
	int row = 0;
	sf::Vector2f gridLocation = getGridLocation(location, row);
	Tile tile(gridLocation, object);
	for (int r = 0; r < m_rows.size(); r++) {
		if (m_rows[r].getRow() == row) {
			m_rows[r].push_back(tile);
			return;
		}
	}

	//didnt deal with the case that the row doesnt exist!
}
//------------------------------------------
sf::Vector2f Grid::getGridLocation(sf::Vector2f location, int& row) {

	for (int r = 0; r < m_rowCols.y; r++) {
		for (int c = 0; c < m_rowCols.x; c++) {
			sf::Vector2f sqrPos = m_rectangles[r][c].getPosition();
			if (checkPosInSquare(sqrPos, location)) {
				row = r;
				return sqrPos;
			}
		}
	}
}				
//------------------------------------------
bool Grid::checkPosInSquare(sf::Vector2f square, sf::Vector2f pos) {
	
	if (square.x <= pos.x && (square.x + m_sqrSize.x >= pos.x)) 
		if (square.y <= pos.y && square.y + m_sqrSize.y >= pos.y)
			return true;
	
	return false;
}

//------------------------------------------
void Grid::drawGrid(sf::RenderWindow &m_window) {

	for (int r = 0; r < m_rectangles.size(); r++) {
		for (int c = 0; c < m_rectangles[r].size(); c++) {
			m_window.draw(m_rectangles[r][c]);
		}
	}

	for (int i = 0; i < m_rows.size(); i++)
		std::cout << i << std::endl;
	
}