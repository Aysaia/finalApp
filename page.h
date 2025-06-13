#pragma once
#include "shape.h"
#include <SDL.h>
#include <vector>

class Page {
public:
	Page();
	~Page();
	bool Render(SDL_Renderer*);

	void SetBackgroundColor(SDL_Color);
	SDL_Color GetBackgroundColor();

	int AddShape(Shape* shape);
	Shape* RemoveShape(int index);

private:
	std::vector<Shape*> shapes;
	SDL_Color backgroundColor;
};