#include "Row.h"

Row::Row(int row ,int size, const Tile& value )
   :m_size(size), m_row(row), m_tiles(nullptr)
{}
//--------------------------------------
Row::Row(const Row& other) {
	
	if (m_tiles != nullptr) {
		delete[] m_tiles;
	}
	
	m_row = other.m_row;
	m_size = other.m_size;
	m_tiles = new Tile[m_size];
	for (int i = 0; i < m_size; ++i) {
		m_tiles[i] = other.m_tiles[i];
	}

}
//--------------------------------------
const Tile& Row::at(int index) const {

	return m_tiles[index];
}
//--------------------------------------
Tile& Row::at(int index) {

	return m_tiles[index];
}
//--------------------------------------
void Row::push_back(const Tile& val) {

	Tile* tilesTemp = new Tile[m_size + 1];

	for (int i = 0; i < m_size; i++)
		tilesTemp[i] = m_tiles[i];
	
	tilesTemp[m_size] = Tile(val);
	
	if (m_tiles) {
		delete[] m_tiles;
	}
	m_tiles = tilesTemp;
	m_size += 1;
}
//--------------------------------------
int Row::size() const {
	
	return m_size;
}
//--------------------------------------
bool Row::empty() const {

	return (m_size < 1);
}
//--------------------------------------
Row& Row::operator=(const Row& other) {
	
	if (this != &other) {
		delete[] m_tiles;
		m_tiles = other.m_tiles;
		m_size = other.m_size;
	}
	return *this;
}
//--------------------------------------
Row::~Row() {
	if(m_tiles)
	   delete[] m_tiles; 
}
//--------------------------------------
int Row::getRow() const {
	return m_row;
}
//--------------------------------------
void Row::remove(int index) {

	int j = 0;
	Tile* tempTiles = new Tile[m_size-1];
	for (int i = 0; i < m_size; i++) {
		if (i != index) {
			tempTiles[j] = m_tiles[i];
			j++;
		}
	}

	delete[] m_tiles;
	m_tiles = tempTiles;
	m_size -= 1;
}
