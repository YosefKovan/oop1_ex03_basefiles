#include "Screen.h"
#include "Consts.h"
#include <iostream>

Screen::Screen() 
	: m_window(sf::VideoMode(1400, 840), "Game")
	  
{}
//-------------------------------------
void Screen::screenMain() {

	addImagesToVector();
	Bar bar;
	
	while (m_window.isOpen()) {
       
		m_window.clear();
		printBackground();
		bar.printToScreen(m_window, m_texture);
		m_window.display();
	}
}
//---------------------------------
void Screen::addImagesToVector() {
	
	for (int i = 0; i < 8; i++) {
		sf::Texture texture;
		texture.loadFromFile(m_imgNamesArr[i]);
		m_texture.push_back(texture);
	}
}
//---------------------------------
void Screen::printBackground() {

	sf::Sprite sprite(m_texture[Background]);
	m_window.draw(sprite);
}





