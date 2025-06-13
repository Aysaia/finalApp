#pragma once
#include "shape.h"
#include "button.h"
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
	int AddButton(Button* button);
	
	Shape* RemoveShape(int index);

private:
	std::vector<Shape*> shapes;
	std::vector<Button*> buttons;
	SDL_Color backgroundColor;
};