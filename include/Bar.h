#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Consts.h"

class Bar {
public:
	Bar();
	void printBarToScreen(sf::RenderWindow&, sf::Sprite[8]);
	bool isOnBar(sf::Vector2f) const;
	void checkAndChangeCurObj(sf::Vector2f, int&);
	
private:
	int m_barWidth;
	int m_barHeight;
	int m_objectSize;
	int m_rowSpace;
	std::vector<sf::Vector2i> m_objectLocations;
	void scaleImage(int, int, sf::Sprite&);
	void setLocations();	
};