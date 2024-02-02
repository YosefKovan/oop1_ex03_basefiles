#include "Tile.h"

class Row {

public:
	explicit Row(int row = 0, int size = 0, const Tile& value = Tile());
	Row(const Row& other);
	Row& operator=(const Row& other);
	~Row();

	const Tile& at(int index) const;
	Tile& at(int index);
	void push_back(const Tile& val);
	int size() const;
	bool empty() const;
	int getRow() const;
	void remove(int);

private:
	Tile* m_tiles = nullptr;
	int m_size;
	int m_row;
};
