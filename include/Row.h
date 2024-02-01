#include "Tile.h"

class Row {

public:
	explicit Row(int size = 0, int row = 0);
	Row(const Row& other);
	Row& operator=(const Row& other);
	~Row();

	const Tile& at(int index) const;
	Tile& at(int index);
	void push_back(const Tile& val);
	int size() const;
	bool empty() const;

	int getRow() const;

private:
	Tile* m_tiles;
	int m_size;
	int m_row;
};
