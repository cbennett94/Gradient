#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Grid {
public:
	Grid(int x, int y);
	void printGrid();
	int getRows();
	int getCols(int r);
	int getVal(int x, int y);
	const int MOE = 10;
private:
	std::vector<std::vector<int>> terrain;
	int getNeighborAverage(int x, int y);
	void generateGrid();
};