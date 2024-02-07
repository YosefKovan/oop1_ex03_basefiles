
#include "File.h"
#include <fstream>
#include "Consts.h"
#include <filesystem>

File::File() 
	:m_rows(MAX_ROWS), m_cols(MAX_COLS), m_fileName("C:/Users/USER/Desktop/Board.txt")
{}
//--------------------------------------------------
void File::saveToFile(Grid &grid) const{

	auto file = std::ofstream(m_fileName);
	auto rowsArr = grid.getTotalRows();
	file << rowsArr.size() << ' ' << rowsArr[0].size() << '\n';

	for (int r = 0; r < rowsArr.size(); r++) {
		for (int c = 0; c < rowsArr[r].size(); c++) {
			if (rowsArr[r].at(c).getObject() == None)
				file << WHITESPACE;
			else
				file << charArr[rowsArr[r].at(c).getObject()];
		}

		file << '\n';
	}
	
}
//---------------------------------
bool File::readFromFile(Grid& grid) {

	if (!std::filesystem::exists(m_fileName))
		return false;

	auto file = std::ifstream(m_fileName);
	std::string line;

	file >> m_rows >> m_cols;
	grid = Grid(m_rows, m_cols);

	int row = -1; //this is because it will read the '\n' character first!
	while (std::getline(file, line)) {
		updateRow(line, row, grid);
		++row;
	}

	return true;
}
//---------------------------------
void File::updateRow(std::string line, int row, Grid &grid) {

	for (int col = 0; col < line.size(); col++) {
		if (line[col] != WHITESPACE && line[col] != '\n') {
			int object = getObjectInt(line[col]);
			grid.updateTile(row, col, object);
		}
	}
}
//---------------------------------
int File::getObjectInt(char object) {

	for (int i = Mouse; i < 7; i++) {
		if (object == charArr[i]) {
			return i;
		}
	}
}

