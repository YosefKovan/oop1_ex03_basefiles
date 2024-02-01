#include <SFML/Graphics.hpp>
#include "Consts.h"

class Tile {

public:
	Tile(const sf::Vector2f&, const int&);
	Tile();
	sf::Vector2f getLocation() const;
private:
	sf::Vector2f m_location;
	int m_object;
};
