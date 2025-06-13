#include <SDL.h>
#include "window.h"
#include "image.h"
#include "textbox.h"
#include<iostream>

int main(int argc, char* argv[]) {
	std::string sdlBasePath = SDL_GetBasePath();
	std::string fullPath = std::string(sdlBasePath) + "/assets/fonts/Sans.ttf";

	TTF_Font* font = TTF_OpenFont(fullPath.c_str(), 24);

	SDL_Color textColor = { 255, 255, 255 };
	SDL_Color bgColor = { 0, 18, 18 };

	std::string text = "Welcome to NewFlix!";

	Window *window = new Window(1000, 800, "NewFlix", 60, bgColor);
	
	Image* shape1 = new Image("default.png", 350, 20);
	Textbox* textbox1 = new Textbox(40, 80, 500, 500, text, font, bgColor, textColor);


	Page *page1 = new Page();

	page1->SetBackgroundColor(bgColor);

	page1->AddShape(textbox1);
	page1->AddShape(shape1);
	window->AddPage(page1);

	window->Start();

	return 0;
}