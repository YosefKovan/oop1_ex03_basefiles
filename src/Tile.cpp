#include "Tile.h"

Tile::Tile(const sf::Vector2f& location, const int& object)
	:m_location(location), m_object(object)
{}
//-----------------------------------
Tile::Tile() 
    :m_location(sf::Vector2f(0,0)), m_object(None)
{}
//-----------------------------------
sf::Vector2f Tile::getLocation() const {

	return m_location;
}