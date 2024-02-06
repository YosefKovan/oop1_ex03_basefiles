
#pragma once 

#include <vector>
#include <string>
#include "Grid.h"
#include "Images.h"
#include <SFML/Graphics.hpp>

class File {

public:
	File();
	void saveToFile(const Grid&);
	bool readFromFile(Grid&);

private:
	void updateRow(std::string, int, Grid&);
	void fillRow(Tile, std::ofstream&, int, int&);
	int getObjectInt(char object);
	std::string m_fileName;
	int m_rows, m_cols;
	std::vector<Row> m_rowsArr;

};
