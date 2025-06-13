#pragma once
#include <SDL.h>

class Shape {
public:
    Shape();
    Shape(int x, int y, int w, int h);
    Shape(int x, int y, int w, int h, SDL_Color color);
    ~Shape();

    virtual bool Render(SDL_Renderer* renderer);
	SDL_Rect GetRect();


protected:
    int x, y;
    int width, height;
    SDL_Color color;
};
