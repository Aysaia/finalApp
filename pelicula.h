#pragma once
#include "video.h"

class Pelicula :public Video
{
public:
	Pelicula(int id, const std::string& name, const std::string& genre, float rating, const std::string& length);
	~Pelicula();

	void StartPage(Page *page, TTF_Font* font) override;

private:
	std::string length;
};
