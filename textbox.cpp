#include "textbox.h"
#include <iostream>

#pragma region Constructors and Destructor
Textbox::Textbox() : Shape() {
	font = TTF_OpenFont("assets/fonts/Sans.ttf", 24);
	if (!font) {
		SDL_Log("Font load error: %s", TTF_GetError());
	}
	textColor = { 255, 255, 255 };
	text = "asd";
	rect = { x, y, width, height };
}

Textbox::Textbox(int x, int y, int w, int h, std::string t, TTF_Font* f, SDL_Color bgColor, SDL_Color textColor)
	: Shape(x, y, w, h, bgColor), text(t), font(f), textColor(textColor), rect({x,y,w,h}) {

}

Textbox::~Textbox() {
}

void Textbox::LoadText(SDL_Renderer* renderer) {
	if (surface) SDL_FreeSurface(surface);
	if (texture) SDL_DestroyTexture(texture);

	surface = TTF_RenderText_Solid(font, "text.c_str()", textColor);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	rect = { x, y, width, height };

}

bool Textbox::Render(SDL_Renderer* renderer) {
	LoadText(renderer);
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	return true;
}

#pragma endregion