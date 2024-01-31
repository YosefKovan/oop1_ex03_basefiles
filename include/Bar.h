#include <SFML/Graphics.hpp>
#include <vector>

class Bar {
public:
	Bar();
	
	void printToScreen(sf::RenderWindow&, std::vector<sf::Texture>&);

private:
	int m_barWidth;
	int m_objectSize;
	int m_rowSpace;
	std::vector<sf::Vector2i> m_objectLocations;
	void setLocations();
	sf::Sprite scaleImage(int, int, sf::Sprite);
    
};