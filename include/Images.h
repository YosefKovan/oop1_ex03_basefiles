#pragma once

#include <SFML/Graphics.hpp>
#include "Consts.h"

class Images {
public: 
	Images();
	sf::Sprite& getSprite(int, sf::Vector2f, bool = false);
	sf::Sprite& getSprite(int);

private:
	sf::Texture m_textures[TOTLA_IMG_AMOUNT];
	void addImagesToVector();
	void scaleImages(sf::Vector2f, sf::Sprite*);
};


