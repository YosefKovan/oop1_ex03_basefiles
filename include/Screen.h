#include <SFML/Graphics.hpp>
#include "vector"
#include "Bar.h"

class Screen {
public:
	Screen();
	void screenMain();

private:
	void addImagesToVector();
	sf::RenderWindow m_window;
	std::vector<sf::Texture> m_texture;
	void printBackground();
};