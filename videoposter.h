#pragma once
#include "image.h"
#include "textbox.h"
#include "button.h"
#include "page.h"

#include <string>
#include <vector>
using namespace std;


class VideoPoster
{
public:
	VideoPoster(std::string, int, int, TTF_Font*, SDL_Color, SDL_Color, Page*);
	~VideoPoster();

	vector<Shape*> GetShapes();

private:
	Shape* shapes[2];
	int x; int y;
};


