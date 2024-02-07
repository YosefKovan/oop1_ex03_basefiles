#include "Tile.h"

Tile::Tile(const sf::Vector2f& location, const int& object)
	:m_location(location), m_object(object), m_tileSize(40)
{}
//-----------------------------------
sf::Vector2f Tile::getLocation() const {

	return m_location;
}
//-----------------------------------
int Tile::getObject() {
	return m_object;
}
//-----------------------------------
bool Tile::isOnTile(sf::Vector2f mouseLocation) const{

	if (mouseLocation.x >= m_location.x && mouseLocation.x < m_location.x + m_tileSize)
		if (mouseLocation.y >= m_location.y && mouseLocation.y < m_location.y + m_tileSize)
			return true;
	
	return false;
}
//-----------------------------------
void Tile::updateTile(int object) {

	m_object = object;
}