#pragma once

#include <SFML/Graphics.hpp>
#include "Consts.h"

class Images {
public: 
	Images();
	void scaleImages(int, int);
	sf::Sprite& getSprite(int);

private:
	sf::Texture m_textures[TOTLA_IMG_AMOUNT];
	sf::Sprite m_sprites[TOTLA_IMG_AMOUNT];
	void addImagesToVector();
};


