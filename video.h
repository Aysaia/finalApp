#pragma once
#include <string>
#include "page.h"
#include <SDL_TTF.h>
#include <iostream>
#include "window.h"

class Video
{
public:
	Video();
	Video(int id, const std::string& name, const std::string& genre, float rating);
	virtual ~Video();
	virtual void StartPage(Page* page, TTF_Font* font, SDL_Color, Window* window) = 0;
	std::string GetName() const { return name; }
	int GetID() { return id; }
	virtual float getRating();
	std::string GetGenre() { return genre; }
	bool operator==(const Video& other) const;
	bool operator<(const Video& other) const;

protected:
	int id;
	std::string name;
	std::string genre;
	float rating;
};
