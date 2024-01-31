#include "Grid.h"
#include <iostream>

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
		std::vector<sf::Vector2f> tempVector;
		for (int col = 0; col < m_rowCols.x; col++) {
			addToVector(row, col, tempVector);
		}
		
		m_squarePositions.push_back(tempVector);
	}			
}
//------------------------------------------
void Grid::addToVector(int row, int col, std::vector<sf::Vector2f>& vector) {

	sf::Vector2f location;
	location.x = m_startLocation.x + col * m_sqrSize.x;
	location.y = m_startLocation.y + row * m_sqrSize.y;
	vector.push_back(location);
	
}
//------------------------------------------
void Grid::drawGrid(sf::RenderWindow& window){

	for (int row = 0; row < m_rowCols.y; row++) {
		for (int col = 0; col < m_rowCols.x; col++) {
			sf::RectangleShape rectangle(m_sqrSize);
			rectangle.setPosition(m_squarePositions[row][col]);
			rectangle.setFillColor(sf::Color(255, 255, 255, 128));
			rectangle.setOutlineColor(sf::Color::Black);
			rectangle.setOutlineThickness(2);
			window.draw(rectangle);
		}
	}
}
//------------------------------------------
bool Grid::isOnGrid(sf::Vector2f position) {

	if (position.x >= m_startLocation.x &&
		position.x <= m_startLocation.x + m_lengthHeight.x) {
		if (position.y >= m_startLocation.y &&
			position.y <= m_startLocation.y + m_lengthHeight.y) {
			std::cout << "on the grid" << std::endl;
			return true;
		}
	}
	return false;
}
//------------------------------------------
