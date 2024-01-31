#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum LenhHeight{rows, cols};

class Grid {

public:
	Grid(const int&, const int&);
	void drawGrid(sf::RenderWindow&);
	void addToVector(int, int, std::vector<sf::Vector2f>&);
	bool isOnGrid(sf::Vector2f position);

private:
	sf::Vector2f m_rowCols;
	sf::Vector2f m_lengthHeight;
	sf::Vector2f m_startLocation;
	sf::Vector2f m_totalGrid;
	sf::Vector2f m_sqrSize;
	
	std::vector<std::vector<sf::Vector2f>> m_squarePositions;

	void setVariables();
	void createGridSquares();
	
};