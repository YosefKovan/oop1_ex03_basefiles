#include "File.h"
#include <fstream>
#include "Consts.h"



File::File() 
	:m_rows(MAX_ROWS), m_cols(MAX_COLS), m_fileName("Board.txt"),
	 m_rowsArr(std::vector<Row>())
{}

//--------------------------------------------------
void File::saveToFile(const Grid &grid) {

	m_rowsArr = grid.getAllRows();
	std::string fileName = "C:/Users/USER/PycharmProjects/Boardd.txt";
	auto file = std::ofstream(fileName);

	for (int i = 0; i < m_rowsArr.size(); i++) {

		if (m_rowsArr[i].size() == 0) {
			file << '\n';
			continue;
		}

		int index = grid.getStartLocation().x;
		for (int j = 0; j < m_rowsArr[i].size(); j++) {
			fillRow(m_rowsArr[i].at(j), file, j, index);
		}

		file << '\n';
	}

	file.close();
}
//--------------------------------------------------
void File::fillRow(Tile tile, std::ofstream& file, int rowIndex, int& index) {

	while (index < tile.getLocation().x) {
		file << WHITESPACE;
		index += GRID_SQR;
	}

	file << charArr[tile.getObject()];
	index += GRID_SQR;
}
//---------------------------------
bool File::readFromFile(Grid& grid) {

	auto file = std::ifstream(m_fileName);
	std::string line;

	if (file.is_open()) {
		file >> m_rows >> m_cols;
		m_rowsArr = std::vector<Row>(m_rows);
		grid = Grid(m_rows, m_cols, m_rowsArr);

		int row = -1; //this is because it will read the '\n' character first!
		while (std::getline(file, line)) {
			updateRow(line, row, grid);
			++row;
		}

		return true;
	}

	return false;
}
//---------------------------------
void File::updateRow(std::string line, int row, Grid &grid) {

	sf::Vector2f startPoint = grid.getStartLocation();

	for (int i = 0; i < line.size(); i++) {
		if (line[i] != WHITESPACE) {
			int object = getObjectInt(line[i]);
			grid.updateRow(sf::Vector2f(startPoint.x + i * GRID_SQR, 
				                        startPoint.y + row * GRID_SQR), object);
		}
	}
}
//---------------------------------
int File::getObjectInt(char object) {

	for (int i = Mouse; i < 7; i++)
		if (object == charArr[i])
			return i;
}