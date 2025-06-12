#include "Grid.h"

Grid::Grid(int x, int y) {
	for (int i = 0; i < x; i++) {
		std::vector<int> temp = std::vector<int>();
		for (int j = 0; j < y; j++) {
			temp.push_back(-1);
		}
		terrain.push_back(temp);
	}
	srand(time(0));
	terrain[0][0] = rand() % 256;
	generateGrid();
}

int Grid::getNeighborAverage(int x, int y) {
	int sum = 0;
	int count = 0;
	for (int i = x - 1; i <= x+1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i >= 0 && i < terrain.size() && j >= 0 && j < terrain[i].size() && terrain[i][j] >= 0)
			{
				sum += terrain[i][j];
				count++;
			}
		}
	}
	return sum / count;
}

void Grid::generateGrid() {
	srand(time(NULL));
	for (int i = 0; i < terrain.size(); i++) {
		for (int j = 0; j < terrain[i].size(); j++) {
			if (terrain[i][j] < 0) {
				int val = getNeighborAverage(i, j);
				int newVal = (rand() % (MOE*2+1) - MOE) + val;
				terrain[i][j] = newVal > 0 && newVal < 256 ? newVal : val;
			}
		}
	}
}

void Grid::printGrid() {
	for (int i = 0; i < terrain.size(); i++) {
		for (int j = 0; j < terrain[i].size(); j++) {
			std::cout << terrain[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int Grid::getRows() {
	return terrain.size();
}

int Grid::getCols(int r) {
	return terrain[r].size();
}

int Grid::getVal(int x, int y) {
	return terrain[x][y];
}