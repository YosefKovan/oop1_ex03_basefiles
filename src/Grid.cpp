#include "Grid.h"
#include <iostream>

Grid::Grid(const int& rows, const int& cols)
{
	setVariables(rows, cols, 1100, 840);
	createTiles(rows, cols, None);
}
//------------------------------------------
void Grid::setVariables(int rows, int cols, int screenLen, int screenHeight) {

	m_gridLenHeight.x = GRID_SQR * cols;
	m_gridLenHeight.y = GRID_SQR * rows;

	m_start.x = (screenLen - m_gridLenHeight.x) / 2 + BAR_WIDTH;
	m_start.y = (screenHeight - m_gridLenHeight.y) / 2;
}
//------------------------------------------
void Grid::createTiles(int rows, int cols, int object) {

	for (int r = 0; r < rows; r++) {
		Row newRow;
		for (int c = 0; c < cols; c++) {
			sf::Vector2f location(m_start.x + GRID_SQR * c, m_start.y + GRID_SQR * r);
			Tile tile(location, object);
			newRow.push_back(tile);
		}
		m_rows.push_back(newRow);
	}
}

//------------------------------------------
void Grid::updateTile(int row, int col, int object){
	
	m_rows[row].at(col).updateTile(object);
}
//------------------------------------------
sf::RectangleShape Grid::createSquare(sf::Vector2f location, sf::Color color) {

	sf::RectangleShape rectangle(sf::Vector2f(GRID_SQR, GRID_SQR));
	rectangle.setPosition(location);
	rectangle.setFillColor(color);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(2);
	return rectangle;
}
//------------------------------------------
void Grid::drawGrid(sf::RenderWindow& window) {

	for (int r = 0; r < m_rows.size(); r++) {
		for (int c = 0; c < m_rows[r].size(); c++) {
			auto location = sf::Vector2f(m_rows[r].at(c).getLocation());
			sf::RectangleShape rectangle = createSquare(location, sf::Color(255, 255, 255, 128));
			window.draw(rectangle);
		}
	}
}
//------------------------------------------
bool Grid::isOnGrid(sf::Vector2f position) {

	if (position.x >= m_start.x && position.x <= m_start.x + m_gridLenHeight.x) {
		if (position.y >= m_start.y && position.y <= m_start.y + m_gridLenHeight.y) {
			return true;
		}
	}
	return false;
}
//------------------------------------------
void Grid::tileAvailable(sf::Vector2f location, int object, sf::RenderWindow& window) {

	if (object == None)
		return;

	for (int row = 0; row < m_rows.size(); row++) {
		for (int col = 0; col < m_rows[row].size(); col++) {
			Tile curTile = m_rows[row].at(col);
			if (curTile.isOnTile(location)){
				if ((curTile.getObject() == None && object != Bin && object != Save) || 
					(curTile.getObject() != None && object == Bin))
					drawSquare(window, row, col);
			}
		}
	}
}
//------------------------------------------
void Grid::drawSquare(sf::RenderWindow & window, int row, int col) {
	sf::Vector2f location = m_rows[row].at(col).getLocation();
	sf::RectangleShape rectangle = createSquare(location, sf::Color::White);
	window.draw(rectangle);
}
//------------------------------------------
void Grid::updateRow(sf::Vector2f location, int object) {

	for (int row = 0; row < m_rows.size(); row++) {
		for (int col = 0; col < m_rows[row].size(); col++) {
			Tile curTile = m_rows[row].at(col);
			
			if (curTile.isOnTile(location)) 
				dealWithTile(curTile, object, row, col);	
		}
	}	
}
//------------------------------------------
void Grid::dealWithTile(Tile &curTile, int object, int row, int col) {

	if (curTile.getObject() == None && object != Bin && object != Save) {
		if (object == Mouse)
			removeAllMice();
		m_rows[row].at(col).updateTile(object);
	}
	else if (object == Bin)
		m_rows[row].at(col).updateTile(None);
}
//------------------------------------------
void Grid::removeAllMice() {

	for (int r = 0; r < m_rows.size(); r++) {
		for (int c = 0; c < m_rows[r].size(); c++) {
			if (m_rows[r].at(c).getObject() == Mouse)
				m_rows[r].at(c).updateTile(None);
		}
	}
}
//------------------------------------------
void Grid::drawImagesOnGrid(sf::RenderWindow& window, Images& images) {

	auto scaleSize = sf::Vector2f(GRID_SQR, GRID_SQR);

	for (int i = 0; i < m_rows.size(); i++) {
		for (int j = 0; j < m_rows[i].size(); j++) {
			
			if (m_rows[i].at(j).getObject() != None) {
				int txtrIndex = m_rows[i].at(j).getObject();
				sf::Sprite sprite = images.getSprite(txtrIndex, scaleSize);
				sprite.setPosition(m_rows[i].at(j).getLocation());
				window.draw(sprite);
			}
		}
	}
}
//------------------------------------------
int Grid::getObjectInTile(int row, int col) {

	return m_rows[row].at(col).getObject();
}
//------------------------------------------
std::vector<Row> Grid::getTotalRows() {

	return m_rows;
}
