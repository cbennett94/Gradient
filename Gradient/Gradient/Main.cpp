#define SDL_MAIN_HANDLED
#include "Grid.h"
#include "SDL.h"
const int XSCALE = 2;
const int YSCALE = 2;
void clearScreen(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void setPixels(SDL_Renderer* renderer, Grid* grid)
{
	clearScreen(renderer);
	for (int i = 0; i < grid->getRows(); i++)
	{
		for (int j = 0; j < grid->getCols(i); j++)
		{
				SDL_SetRenderDrawColor(renderer, grid->getVal(i, j), grid->getVal(i, j), grid->getVal(i, j), 255);
				SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	SDL_RenderPresent(renderer);
}


int main() {
	Grid* world1 = new Grid(250, 250);
	//world1->printGrid();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(XSCALE * world1->getCols(0), YSCALE * world1->getRows(), 0, &window, &renderer);
	SDL_RenderSetScale(renderer, XSCALE, YSCALE);
	surface = SDL_GetWindowSurface(window);

	clearScreen(renderer);
	setPixels(renderer, world1);

	SDL_Event e;
	bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}
	}
	return 0;
}