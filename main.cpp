#include <SDL.h>
#include <SDL_ttf.h>
#include "videoposter.h"
#include "Scroll.h"
#include "window.h"
#include<iostream>
#include "genre.h"

int TestFunction(int i) {
	std::cout << "Test function called!" << i << std::endl;
	return i;
}

int main(int argc, char* argv[]) {
	if (TTF_Init() == -1) {
		std::cerr << "TTF_Init error: " << TTF_GetError() << "/n";
		return false;
	}

	SDL_Init(SDL_INIT_VIDEO);

	char* base = SDL_GetBasePath();
	std::string basePath = base ? base : ""; 
	SDL_free(base);

	std::string fontPath = basePath + "assets/fonts/Maax.ttf";

	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 100);
	if (font == nullptr) {
		std::cerr << "Font load error: " << TTF_GetError() << "/n";
		return false;
	}

	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = {250, 50, 10};
	SDL_Color black = { 0, 0, 0 };

	Window *window = new Window(1000, 750, "Rotten Apples", 60, white);

	Image* logo = new Image("logo.png", 500-322/2, 25);
	Shape* background = new Shape(0, 20, 1000, 120, red);


	Page* page1 = new Page();

	page1->SetBackgroundColor(white);

	Genre* actionGenre = new Genre("Action", { "superman", "superman", "superman" }, 150, font, black, red, page1);

	page1->AddShape(background);
	page1->AddShape(logo);
	window->AddPage(page1);
	window->Start();

	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
