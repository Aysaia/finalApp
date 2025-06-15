#pragma once
#include "shape.h"
#include <SDL_ttf.h>
#include <string>
#include <algorithm>

class Textbox : public Shape {
public:
	Textbox();
	Textbox(int x, int y, int w, int h, std::string t, TTF_Font* f, SDL_Color bg, SDL_Color textColor);
	~Textbox();

	bool Render(SDL_Renderer* renderer);

private:
	void LoadText(SDL_Renderer* renderer);

	TTF_Font* font;
	SDL_Color textColor;
	std::string text;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
};
