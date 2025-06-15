#pragma once
#include <SDL.h>

class Shape {
public:
    Shape();
    Shape(int x, int y, int w, int h);
    Shape(int x, int y, int w, int h, SDL_Color color);
    ~Shape();

    void Move(int dx, int dy);
    void Move(const SDL_Point& p); // Sobrecarga
    bool Render(SDL_Renderer* renderer); // Método puro virtual
	SDL_Rect GetRect();
	bool Hover(int x, int y);
    bool operator==(const Shape& other) const;

protected:
    int x, y;
    int width, height;
    SDL_Color color;
};
