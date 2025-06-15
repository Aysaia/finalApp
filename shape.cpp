#include "shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
    : width(100), height(100), x(0), y(0), color({ 255, 255, 255, 255 }) {
}
Shape::Shape(int xPos, int yPos, int w, int h)
    : width(w), height(h), x(xPos), y(yPos), color({ 255, 255, 255, 255 }) {
}
Shape::Shape(int xPos, int yPos, int w, int h, SDL_Color color)
	: width(w), height(h), x(xPos), y(yPos), color(color) {
}
Shape::~Shape() {
}

bool Shape::Render(SDL_Renderer* renderer) {
    if (!renderer) return false;

    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    return true;
}

SDL_Rect Shape::GetRect(){
    return { x, y, width, height };
}

bool Shape::Hover(int x, int y) {
    SDL_Rect rect = GetRect();

    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
        return true;
    }
    return false;
}

void Shape::Move(int dx, int dy) {
    std::cout << "Move(dx, dy) llamado" << std::endl;
    x += dx;
    y += dy;
}

void Shape::Move(const SDL_Point& p) {
    std::cout << "Move(SDL_Point) llamado" << std::endl;
    x += p.x;
    y += p.y;
}

bool Shape::operator==(const Shape& other) const {
    return x == other.x && y == other.y && width == other.width && height == other.height;
}