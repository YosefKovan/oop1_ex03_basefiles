#include "Images.h"
#include "Bar.h"
#include <iostream>

Images::Images() {

	addImagesToVector();
}
//-------------------------------------
void Images::addImagesToVector() {

	for (int i = 0; i < TOTLA_IMG_AMOUNT; i++) {
		sf::Texture texture;
		texture.loadFromFile(m_imgNamesArr[i]);
		m_textures[i] = texture;
	}
}
//-------------------------------------
sf::Sprite& Images::getSprite(int index, sf::Vector2f size, bool transparency) {

	sf::Sprite sprite;
	sprite.setTexture(m_textures[index]);
	scaleImages(size, &sprite);
	
	if(transparency)
	   sprite.setColor(sf::Color(255, 255, 255, 128));
	
	return sprite;	
}
//-------------------------------------
sf::Sprite& Images::getSprite(int index) {

	sf::Sprite sprite;
	sprite.setTexture(m_textures[index]);
	return sprite;
}
//-------------------------------------
void Images::scaleImages(sf::Vector2f size, sf::Sprite* sprite) {

	for (int i = 0; i < 10; i++) {
		float xScale = size.x / sprite->getLocalBounds().width;
		float yScale = size.y / sprite->getLocalBounds().height;
		sprite->setScale(xScale, yScale);
	}
}
