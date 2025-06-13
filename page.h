#pragma once
#include <SDL.h>
#include <vector>

#include "shape.h"
#include "button.h"
#include "scroll.h"

class Page {
public:
	Page();
	~Page();
	bool Render(SDL_Renderer*);
	void CheckButtons(int x, int y);

	void SetBackgroundColor(SDL_Color);
	SDL_Color GetBackgroundColor();

	int AddShape(Shape* shape);
	int AddButton(Button* button);
	int AddScroll(Scroll* scroll);

	void Scrollin(int x, int y, int dx, int dy);


	Shape* RemoveShape(int index);

private:
	std::vector<Scroll*> scrolls;
	std::vector<Shape*> shapes;
	std::vector<Button*> buttons;
	SDL_Color backgroundColor;
};