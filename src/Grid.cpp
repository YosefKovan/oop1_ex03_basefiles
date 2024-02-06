#include "Grid.h"
#include <iostream>

Grid::Grid(const int& rows, const int& cols, std::vector<Row> rowsVect)
	: m_gridRowsCols(cols, rows), m_totalRighScreen(1100, 840), m_rows(rowsVect)
{
	setVariables();
	createGridSquares();
}
//------------------------------------------
void Grid::setVariables() {

	m_lengthHeight.x = GRID_SQR * m_gridRowsCols.x;
	m_lengthHeight.y = GRID_SQR * m_gridRowsCols.y;

	m_startLocation.x = (m_totalRighScreen.x - m_lengthHeight.x) / 2 + BAR_WIDTH;
	m_startLocation.y = (m_totalRighScreen.y - m_lengthHeight.y) / 2;
}
//------------------------------------------
sf::Vector2f Grid::getStartLocation() const{
	
	return m_startLocation;
}
//------------------------------------------
void Grid::createGridSquares() {

	for (int row = 0; row < m_gridRowsCols.y; row++) {
		std::vector<sf::RectangleShape> rectangleVect;
		for (int col = 0; col < m_gridRowsCols.x; col++) {
			addSquaresToVect(row, col, rectangleVect);
		}
		
		m_rectangles.push_back(rectangleVect);
	}			
}
//------------------------------------------
void Grid::addSquaresToVect(int row, int col, std::vector<sf::RectangleShape>& vector) {

	sf::Vector2f location;
	location.x = m_startLocation.x + col * GRID_SQR;
	location.y = m_startLocation.y + row * GRID_SQR;

	sf::RectangleShape rectangle(sf::Vector2f(GRID_SQR, GRID_SQR));
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
		
		if (object == Mouse) //this will remove all other mice
			removeMouseFromRow(i);
		
		if (i == row) {
			if (object != Bin && !locationExists(gridLocation, i))
				m_rows[i].push_back(tile);
			else if(object == Bin)
				deleteFromRow(gridLocation, i);
		}
	}
	
}
//------------------------------------------
sf::Vector2f Grid::getGridLocation(sf::Vector2f location, int& row) {

	for (int r = 0; r < m_gridRowsCols.y; r++) {
		for (int c = 0; c < m_gridRowsCols.x; c++) {
			sf::Vector2f sqrPos = m_rectangles[r][c].getPosition();
			if (checkPosInSquare(sqrPos, location)) {
				row = r;
				return sqrPos;
			}
		}
	}
}
//------------------------------------------
void Grid::removeMouseFromRow(int index) {

	for (int i = 0; i < m_rows[index].size(); i++) {
		if (m_rows[index].at(i).getObject() == Mouse)
			m_rows[index].remove(i);
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
void Grid::deleteFromRow(sf::Vector2f location, int index) {

	for (int i = 0; i < m_rows[index].size(); i++) {
		if (locationsEqual(location, m_rows[index].at(i).getLocation())){
			m_rows[index].remove(i);
		}
	}	
}
//------------------------------------------

bool Grid::checkPosInSquare(sf::Vector2f square, sf::Vector2f pos) {
	
	if (square.x <= pos.x && (square.x + GRID_SQR > pos.x))
		if (square.y <= pos.y && square.y + GRID_SQR > pos.y)
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
void Grid::drawImagesOnGrid(sf::RenderWindow& window, Images& images) {

	images.scaleImages(GRID_SQR, GRID_SQR);
	
	for (int i = 0; i < m_rows.size(); i++) {
		if(!m_rows[i].empty()){
			for (int j = 0; j < m_rows[i].size(); j++) {
				sf::Vector2f location = m_rows[i].at(j).getLocation();
				const int object = m_rows[i].at(j).getObject();
				images.getSprite(object).setPosition(location);
				window.draw(images.getSprite(object));
			}
		}
	}
}
//------------------------------------------
std::vector<Row> Grid::getAllRows() const{
	
	return m_rows;
}
