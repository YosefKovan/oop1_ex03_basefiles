#include "Grid.h"
#include <iostream>

//std::cout << object << std::endl; for debuggind

Grid::Grid(const int& rows, const int& cols) 
	: m_rowCols(rows,cols), m_sqrSize(40, 40),
	  m_totalGrid(1100, 840)
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
		std::vector<sf::RectangleShape> rectangleVect;
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
	
	int row;
	//this function updates row by refference
	sf::Vector2f gridLocation = getGridLocation(location, row); 
	auto tile = Tile(gridLocation, object);
	
	for (int i = 0; i < m_rows.size(); i++) {
		if (m_rows[i].getRow() == row) {
			if (object != Bin && !locationExists(gridLocation, i))
				m_rows[i].push_back(tile);
			else if(object == Bin)
				deleteFromRow(gridLocation, i, row);
			return;
		}
	}
	
	if (object != Bin) {
		m_rows.push_back(Row(row));
		m_rows.back().push_back(tile);
	}
}

//------------------------------------------
bool Grid::locationExists(sf::Vector2f location, int index) {

	for (int i = 0; i < m_rows[index].size(); i++)
		if (locationsEqual(m_rows[index].at(i).getLocation(), location))
			return true;
	
	return false;
}
//------------------------------------------
bool Grid::locationsEqual(sf::Vector2f location1, sf::Vector2f location2) {

	return (location1.x == location2.x && location1.y == location2.y);
}

//------------------------------------------
void Grid::deleteFromRow(sf::Vector2f location, int index ,int row) {

	for (int i = 0; i < m_rows[index].size(); i++) {
		if (locationsEqual(location, m_rows[index].at(i).getLocation())){
			m_rows[index].remove(i);
		}
	}	
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
}
//------------------------------------------
void Grid::drawImagesOnGrid(sf::RenderWindow& window, sf::Sprite sprite[8]) {

	for (int i = 0; i < m_rows.size(); i++) {
		for (int j = 0; j < m_rows[i].size(); j++) {
			sf::Vector2f location = m_rows[i].at(j).getLocation();
			int object = m_rows[i].at(j).getObject();
			scaleImage(m_sqrSize.x, m_sqrSize.y, sprite[object]);
			sprite[object].setPosition(location);
			window.draw(sprite[object]);
		}
	}
}
//------------------------------------------
void Grid::scaleImage(int width, int height, sf::Sprite& sprite) {

	float xScale = width / sprite.getLocalBounds().width;
	float yScale = height / sprite.getLocalBounds().height;
	sprite.setScale(xScale, yScale);

}
