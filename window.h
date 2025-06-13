#pragma once
#include <SDL.h>
#include "page.h"
#include <vector>

class Window
{
public:
	Window();
	Window(int, int, const char*, int, SDL_Color);
	~Window();

	bool Start();
	void Render();

	bool AddPage(Page*);
	Page* GetPage(int);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<Page*> pages;
	int currentPageIndex = 0;

	int width;
	int height;

	SDL_Color backgroundColor;

	int frameRate;
};
