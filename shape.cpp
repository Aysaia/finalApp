#include "shape.h"

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
