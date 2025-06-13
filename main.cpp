#include <SDL.h>
#include <SDL_ttf.h>
#include "window.h"
#include "image.h"
#include "textbox.h"
#include<iostream>

int main(int argc, char* argv[]) {
	if (TTF_Init() == -1) {
		std::cerr << "TTF_Init error: " << TTF_GetError() << "\n";
		return false;
	}

	TTF_Font* font = TTF_OpenFont("/assets/fonts/Sans.ttf", 24);
	if (font == nullptr) {
		std::cerr << "Font load error: " << TTF_GetError() << "\n";
		return false;
	}

	SDL_Color textColor = { 255, 255, 255 };
	SDL_Color bgColor = { 0, 18, 18 };

	std::string text = "Welcome to Turlte!";

	Window *window = new Window(1000, 800, "Turtle", 60, bgColor);
	
	Image* shape1 = new Image("default.png", 450, 200);
	Textbox* textbox1 = new Textbox(40, 80, 500, 500, text, font, bgColor, textColor);


	Page *page1 = new Page();

	page1->SetBackgroundColor(bgColor);

	page1->AddShape(textbox1);
	page1->AddShape(shape1);

	window->AddPage(page1);

	window->Start();
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}