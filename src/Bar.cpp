#include "Bar.h"

Bar::Bar()
	:m_barWidth(300), m_objectSize(60), m_rowSpace(30)
{
	setLocations();
}
//-----------------------------------
void Bar::setLocations() {

	int row = 20, col = 20;
	
	for (int i = 0; i < 7; i++) {
		auto vector2i = sf::Vector2i(row, col);
		m_objectLocations.push_back(vector2i);
		row += (m_objectSize + m_rowSpace);
	}
}
//-----------------------------------
void Bar::printToScreen(sf::RenderWindow& window, std::vector<sf::Texture>& texture) {

	for (int i = 0; i < 7; i++) {
		auto sprite = sf::Sprite(texture[i]);
		sprite = scaleImage(m_objectSize, m_objectSize, sprite);
		sprite.setPosition(m_objectLocations[i].y, m_objectLocations[i].x);
		window.draw(sprite);
	}
}
//-----------------------------------
sf::Sprite Bar::scaleImage(int width, int height, sf::Sprite sprite){

	float xScale = width / sprite.getLocalBounds().width;
	float yScale = height / sprite.getLocalBounds().height;
	sprite.setScale(xScale, yScale);
	return sprite;
}
