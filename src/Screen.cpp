#include "Screen.h"
#include "Consts.h"
#include <iostream>
#include <fstream>


Screen::Screen()
	: m_window(sf::VideoMode(1400, 840), "Game"), m_object(None)

{
	if(!m_file.readFromFile(m_grid)) //this will intialize m_grid as well if file exists
	   setGrid();
}
//-------------------------------------
void Screen::screenMain() {

	while (m_window.isOpen()) {
       
		m_window.clear();
		printBackground();
		m_bar.DrawBarToScreen(m_window, m_images, m_object);
		m_grid.drawGrid(m_window);
		checkEvents();
		m_grid.drawImagesOnGrid(m_window, m_images);
		m_window.display();
	}
}

//---------------------------------
void Screen::printBackground(){
	
	sf::Sprite sprite = m_images.getSprite(Background);
	m_window.draw(sprite);
}
//---------------------------------
void Screen::checkEvents() {

	 if (auto event = sf::Event{}; m_window.waitEvent(event))
	 {
		 switch (event.type)
		 {
		 case sf::Event::Closed:
			 m_window.close();
			 break;
		 case sf::Event::MouseMoved:
			 handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
			 break;
		 case sf::Event::MouseButtonReleased:
			 handleClick(event.mouseButton);
			 break;
		 }
	 }	
}
//---------------------------------
void Screen::handleMouseMoved(int x, int y) {
	
	sf::Vector2f mousePosition = m_window.mapPixelToCoords({ x, y });
	if (m_grid.isOnGrid(mousePosition))
	   m_grid.tileAvailable(mousePosition, m_object, m_window);
}
//---------------------------------
 void Screen::handleClick(const sf::Event::MouseButtonEvent& event) {
	 
	 sf::Vector2f eventPos = m_window.mapPixelToCoords({ event.x, event.y });

	 if (m_bar.isOnBar(eventPos)) {
		 m_bar.checkAndChangeCurObj(eventPos, m_object);
		
		 if (m_object == Save) {
			 m_file.saveToFile(m_grid);
			 m_object = None;
		 }
		 if (m_object == Reset) { //this will reset the screen 
			 setGrid();
			 m_object = None;
		 }
	 } 
	 else if (m_grid.isOnGrid(eventPos)) {
		 if (m_object != None ) {
			 m_grid.updateRow(eventPos, m_object);
		 }
	 }		 
 }
 //---------------------------------
 void Screen::setGrid() {

	 printBackground();
	 m_window.display();
	 
	 int rows, cols;
	 std::cout << "Enter a number of Rows and a number of Cols: " << std::endl;
	 std::cin >> rows >> cols;
	 if (rows > MAX_ROWS || cols > MAX_COLS) {
		 rows = MAX_ROWS; 
		 cols = MAX_COLS;
	 }
	 
	 m_grid = Grid(rows, cols);
 } 
 



