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
			auto vector2i = sf::Vector2i(col1, row);
			m_objectLocations.push_back(vector2i);
			continue;
		}

		auto vector2i = sf::Vector2i(col2, row);
		m_objectLocations.push_back(vector2i);
		row += (m_objectSize + m_rowSpace);
	}
}
//----------------------------------------------------
void Bar::DrawBarToScreen(sf::RenderWindow& window, Images &images){
	
	images.scaleImages(m_objectSize, m_objectSize);

	for (int i = 0; i < BAR_OBJ_AMOUNT; i++) {
	    images.getSprite(i).setPosition(m_objectLocations[i].x, m_objectLocations[i].y);
		window.draw(images.getSprite(i));	
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
		int x = m_objectLocations[i].x;
		int y = m_objectLocations[i].y;
		if (location.x >= x && location.x <= x + m_objectSize) {
			if (location.y >= y && location.y <= y + m_objectSize) {
				object = i;
				break;
			}
		}	
	}   
}
//----------------------------------------------------
