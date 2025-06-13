#pragma once
#include "image.h"
#include "textbox.h"
#include "button.h"
#include "page.h"

#include <vector>
using namespace std;


class VideoPoster
{
public:
	VideoPoster(string, int, int, TTF_Font*, SDL_Color, SDL_Color, Page*);
	~VideoPoster();

	vector<Shape*> GetShapes();

private:
	Shape* shapes[2];
	int x; int y;
};

class VideoPage : public Page
{

};


