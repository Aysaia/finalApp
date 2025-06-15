#pragma once
#include <string>
#include "Scroll.h"
#include "Shape.h"
#include "videoposter.h"
#include "textbox.h"
#include "videoPage.h"
#include "pelicula.h"
#include "series.h"
#include "window.h"

class Genre
{
public:
	Genre(const std::string& name, const std::vector<Video*>& videos, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page, Window *window);
	~Genre();

private:
	void Scrollin(int i);
	Scroll* scroll;
	Window* window;
	std::vector<Video*> videos;
	std::string name;
};