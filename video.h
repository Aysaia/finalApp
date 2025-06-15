#pragma once
#include <string>
#include "page.h"

class Video
{
public:
	Video();
	Video(int id, const std::string& name, const std::string& genre, float rating);
	~Video();
	virtual void StartPage(Page* page, TTF_Font* font) {};
	std::string GetName() const { return name; }
	virtual float getRating();

protected:
	int id;
	std::string name;
	std::string genre;
	float rating;
};
