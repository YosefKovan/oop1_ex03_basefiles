#include "Screen.h"
#include "Consts.h"
#include <iostream>

Screen::Screen() 
	: m_window(sf::VideoMode(1400, 840), "Game"), m_object(None),
	  m_grid(15,10)
{}
//-------------------------------------
void Screen::screenMain() {

	addImagesToVector();
	
	while (m_window.isOpen()) {
       
		m_window.clear();
		printBackground();
		m_bar.printBarToScreen(m_window, m_sprites);
		m_grid.drawGrid(m_window);
		checkEvents();
		m_window.display();
	}
}
//---------------------------------
void Screen::addImagesToVector() {
	
	for (int i = 0; i < 8; i++){
		sf::Texture texture;
	    texture.loadFromFile(m_imgNamesArr[i]);
		m_textures[i] = texture;
		
		sf::Sprite sprite;
		sprite.setTexture(m_textures[i]);
		m_sprites[i] = sprite;
	}
}
//---------------------------------
void Screen::printBackground() {

	sf::Sprite sprite(m_textures[Background]);
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
		 case sf::Event::MouseButtonReleased:
			 handleClick(event.mouseButton);
			 break;
		 }
	 }	
}
//---------------------------------
 
 void Screen::handleClick(const sf::Event::MouseButtonEvent& event) {
	 
	 sf::Vector2f eventPos = m_window.mapPixelToCoords({ event.x, event.y });
	 if (m_bar.isOnBar(eventPos)) {
		 m_bar.checkAndChangeCurObj(eventPos, m_object);
	 }
	// else if (m_grid.isOnGrid(eventPos))
			 
 }
 //---------------------------------
 



