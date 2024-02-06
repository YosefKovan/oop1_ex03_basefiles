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

		sf::Sprite sprite;
		sprite.setTexture(m_textures[i]);
		m_sprites[i] = sprite;
	}
}
//-------------------------------------
void Images::scaleImages(int width, int height) {

	for (int i = 0; i < 10; i++) {
		float xScale = width / m_sprites[i].getLocalBounds().width;
		float yScale = height / m_sprites[i].getLocalBounds().height;
		m_sprites[i].setScale(xScale, yScale);
	}
}
//-------------------------------------
sf::Sprite& Images::getSprite(int index) {

	return m_sprites[index];
}