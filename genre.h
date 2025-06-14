#pragma once
#include <string>
#include "Scroll.h"
#include "Shape.h"
#include "videoposter.h"
#include "textbox.h"

class Genre
{
public:
	Genre(std::string title, std::vector<std::string> videoNames, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page);
	~Genre();

private:
	Textbox* title;
	Scroll* scroll;
	std::vector<VideoPoster*> posters;
	std::vector<std::string> videoNames;
};