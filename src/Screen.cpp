#include "Screen.h"
#include "Consts.h"
#include <iostream>
#include <fstream>


Screen::Screen() 
	: m_window(sf::VideoMode(1400, 840), "Game"), m_object(None)
	  
{
	addImagesToVector();

	if (!readFromFile())
		setGrid();
}
//-------------------------------------
void Screen::screenMain() {

	while (m_window.isOpen()) {
       
		m_window.clear();
		printBackground();
		m_bar.printBarToScreen(m_window, m_sprites);
		m_grid.drawGrid(m_window);
		checkEvents();
		m_grid.drawImagesOnGrid(m_window, m_sprites);
		m_window.display();
	}
}
//---------------------------------
void Screen::addImagesToVector() {
	
	for (int i = 0; i < 11; i++){
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

	m_window.draw(m_sprites[Background]);
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
		
		 if (m_object == Save)
			 saveToFile();
		 else if (m_object == Reset) { //this will reset the screen
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
	 
	 std::vector<Row> rowsVect(rows);
	 m_grid = Grid(rows, cols, rowsVect);
 } 
 //--------------------------------------------------
 void Screen::saveToFile() {

	 std::vector<Row> m_rows = m_grid.getAllRows();
	 std::string fileName = "Board.txt";
     auto file = std::ofstream(fileName);
	 for (int i = 0; i < m_rows.size(); i++) {
		
		 if (m_rows[i].size() == 0) {
			 file << WHITESPACE << '\n';
			 continue;
		 }

		 for (int j = 0; j < m_rows[i].size(); j++) {
			 fillRow(m_rows[i].at(j), file);
		 }
		 
		 file << '\n';
	 }

	 file.close();
 }
 //--------------------------------------------------
 void Screen::fillRow(Tile tile, std::ofstream &file) {

	 for (int i = 0; i < tile.getLocation().x; i++)
		 file << WHITESPACE;
	 
	 file << charArr[tile.getObject()];
 }
 
 // //this part needs to be finished and dealt with.
 //---------------------------------
 bool Screen::readFromFile() {

	 std::string fileName = "Board.txt";
	 auto file = std::ifstream(fileName);
	 int rows, cols;
	 std::string line;

	 if (file.is_open()) {
		 file >> rows >> cols;
		 std::vector<Row> rowsArr;
		 int row = 0;
		 
		 while (std::getline(file, line)) {
			 updateRow(rowsArr, line, row);
			 row += 1;
		 }

		 m_grid = Grid(rows, cols, rowsArr);
		 return true;
	 }
	 
	 return false;
 }
 //---------------------------------
 void Screen::updateRow(std::vector<Row>& rowsArr, std::string line, int row) {
	 
	auto objectRow = Row();

	 for (int i = 0; i < line.size(); i++) {
		 if (line[i] != WHITESPACE) {
			 int object = Mouse;
			 auto tile = Tile(sf::Vector2f(i * 40, row * 40), object);
			 objectRow.push_back(tile);
		 }
	 }
	  
	rowsArr.push_back(objectRow);
 }



