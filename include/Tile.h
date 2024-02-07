#pragma once

#include <SFML/Graphics.hpp>
#include "Consts.h"

class Tile {

public:
	Tile(const sf::Vector2f&, const int&);
	Tile() = default;
	sf::Vector2f getLocation() const;
	int getObject();
	bool isOnTile(sf::Vector2f) const;
	void updateTile(int);
	

private:
	sf::Vector2f m_location;
	int m_tileSize;
	int m_object;
	int m_row;
};
