
#pragma once 

#include <vector>
#include <string>
#include "Grid.h"
#include "Images.h"
#include <SFML/Graphics.hpp>

class File {

public:
	File();
	void saveToFile(Grid&) const;
	bool readFromFile(Grid&);

private:
	void updateRow(std::string, int, Grid&);
	int getObjectInt(char object);
	std::string m_fileName;
	int m_rows, m_cols;
	std::vector<Row> m_rowsArr;

};
