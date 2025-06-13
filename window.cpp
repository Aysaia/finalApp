#include "window.h"
#include <iostream>

#pragma region Constructors and Destructor
Window::Window()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Netflix", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	width = 800;
	height = 600;
	frameRate = 60;

	backgroundColor = { 0, 0, 0, 255 }; // Default background color: black
}
Window::Window(int w, int h, const char* title, int fps, SDL_Color bgColor)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	width = w;
	height = h;
	frameRate = fps;
	backgroundColor = bgColor;
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
#pragma endregion
#pragma region Functions
bool Window::Start()
{
	if (window == nullptr || renderer == nullptr) {
		return false;
	}
	bool quit = false;
	while (!quit) {
		Render();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "Mouse button pressed at ("
					<< event.button.x << ", " << event.button.y << ")\n";
			}
		}
		SDL_Delay(round(1000 / frameRate));
	}
	return true;
}
void Window::Render() {
	if (window == nullptr || renderer == nullptr) {
		return;
	}
	if (!pages.empty()) {
		SDL_Color backgroundColor = pages[currentPageIndex]->GetBackgroundColor();
		SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, 255);
		SDL_RenderClear(renderer);
		pages[currentPageIndex]->Render(renderer);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, 255);
		SDL_RenderClear(renderer);
	}
	SDL_RenderPresent(renderer);
}


bool Window::AddPage(Page* page)
{
	if (page == nullptr) {
		return false;
	}
	pages.push_back(page);
	return true;
}
Page* Window::GetPage(int index)
{
	if (index < 0 || index >= pages.size()) {
		return nullptr;
	}
	return pages[index];
}
#pragma endregion