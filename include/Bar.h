#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Consts.h"
#include "Images.h"
#include "Tile.h"

class Bar {
public:
	Bar();
	void DrawBarToScreen(sf::RenderWindow&, Images& images);
	bool isOnBar(sf::Vector2f) const;
	void checkAndChangeCurObj(sf::Vector2f, int&);
	
private:
	int m_barWidth;
	int m_barHeight;
	int m_objectSize;
	int m_rowSpace;
	std::vector<sf::Vector2i> m_objectLocations;
	void setLocations();	
};