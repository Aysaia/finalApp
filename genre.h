#pragma once
#include <string>
#include "Scroll.h"
#include "Shape.h"
#include "videoposter.h"
#include "textbox.h"
#include "videoPage.h"
#include "window.h"

class Genre
{
public:
	Genre(std::string title, std::vector<std::string> videoNames, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page, Window *window);
	~Genre();

private:
	void Scrollin(int i);
	Scroll* scroll;
	Window* window;
};