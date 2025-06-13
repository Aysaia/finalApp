#include "button.h"
Button::Button(std::function<void(int)> onClick, int i, Shape* shape) {
	this->onClick = onClick;
	this->id = i;
	this->shape = shape;
}
Button::~Button() {

}
bool Button::Hover(int x, int y) {
	SDL_Rect rect = shape->GetRect();

	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
		return true;
	}
	return false;
}
void Button::Click() {
	if (onClick) {
		onClick(id);
	}
}