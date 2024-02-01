#include "Row.h"

Row::Row(int size, int row) 
   :m_size(size), m_row(row), m_tiles(new Tile[m_size])
{}
//--------------------------------------
Row::Row(const Row& other) {

	delete[] m_tiles;
	m_tiles = other.m_tiles;
	m_size = other.m_size;
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
	
	tilesTemp[m_size] = val;
	
	delete [] m_tiles;
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
	delete[] m_tiles;
}
//--------------------------------------
int Row::getRow() const {
	return m_row;
}
