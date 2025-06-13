#include "button.h"
Button::Button(std::function<void(int)> onClick, int i, Shape* shape) {
	this->onClick = onClick;
	this->id = i;
	this->shape = shape;
}
Button::~Button() {

}
bool Button::Hover(int x, int y) {
	return shape->Hover(x, y);
}
void Button::Click() {
	if (onClick) {
		onClick(id);
	}
}