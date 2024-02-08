#include "Bar.h"
#include <iostream>

Bar::Bar()
	:m_barWidth(200), m_objectSize(90), m_rowSpace(60), m_barHeight(840)
{
	setLocations();
}
//----------------------------------------------------
void Bar::setLocations() {

	int row = 50, col1 = 20, col2 = 130;
	
	for (int i = 0; i < BAR_OBJ_AMOUNT; i++) {
		if (i % 2 == 0) {
			auto location = sf::Vector2f(col1, row);
			auto tile = Tile(location, i);
			m_tiles.push_back(tile);
			continue;
		}

		auto location = sf::Vector2f(col2, row);
		auto tile = Tile(location, i);
		m_tiles.push_back(tile);
		row += (m_objectSize + m_rowSpace);
	}
}
//----------------------------------------------------
void Bar::DrawBarToScreen(sf::RenderWindow& window, Images &images, int object){
	
	
	auto scaleSize = sf::Vector2f(m_objectSize, m_objectSize);
	bool trans = false;

	for (int i = 0; i < m_tiles.size(); i++) {
		
		if (object == i)
			trans = true;
		
		sf::Sprite sprite = images.getSprite(i, scaleSize, trans);
		sprite.setPosition(m_tiles[i].getLocation());
		window.draw(sprite);	
		trans = false;
	}
	
}
//----------------------------------------------------
bool Bar::isOnBar(sf::Vector2f location) const{

	if (location.x >= 0 && location.x <= m_barWidth)
		if (location.y >= 0  && location.y <= m_barHeight)
			return true;
	
	return false;
}
//----------------------------------------------------
void Bar::checkAndChangeCurObj(sf::Vector2f location, int &object) {
	
	for (int i = 0; i < BAR_OBJ_AMOUNT; i++) {
		auto tileLocation = m_tiles[i].getLocation();
		if (location.x >= tileLocation.x && location.x <= tileLocation.x + m_objectSize) {
			if (location.y >= tileLocation.y && location.y <= tileLocation.y + m_objectSize) {
				object = i;
				return;
			}
		}	
	}   
}
//----------------------------------------------------
