#pragma once
#include "video.h"
#include "textbox.h"

class Pelicula :public Video
{
public:
	Pelicula(int id, const std::string& name, const std::string& genre, float rating, const std::string& length);
	~Pelicula();

	void StartPage(Page* page, TTF_Font* font, SDL_Color, Window* window) override;

private:
	std::string length;
};
