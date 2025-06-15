#pragma once
#include <string>
#include "page.h"
#include <SDL_TTF.h>
#include <iostream>

class Video
{
public:
	Video();
	Video(int id, const std::string& name, const std::string& genre, float rating);
	~Video();
	virtual void StartPage(Page* page, TTF_Font* font, SDL_Color) { std::cout << "FUCK" << std::endl;};
	std::string GetName() const { return name; }
	int GetID() { return id; };
	virtual float getRating();
	std::string GetGenre() { return genre; };

protected:
	int id;
	std::string name;
	std::string genre;
	float rating;
};
