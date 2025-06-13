#include "page.h"

#pragma region Constructor and Destructor
Page::Page() {
	backgroundColor = { 0, 0, 0, 255 };
}
Page::~Page() {
	for (Shape* shape : shapes) {
		delete shape;
	}
}
#pragma endregion

#pragma region Functions
void Page::SetBackgroundColor(SDL_Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}
SDL_Color Page::GetBackgroundColor() {
	return backgroundColor;
}
bool Page::Render(SDL_Renderer* renderer) {
	if (renderer == nullptr) {
		return false;
	}
	for (Shape* shape : shapes) {
		if (!shape->Render(renderer)) {
			return false;
		}
	}
	return true;
}
int Page::AddShape(Shape* shape) {
	if (shape == nullptr) {
		return -1;
	}
	shapes.push_back(shape);
	return shapes.size() - 1; 
}
Shape* Page::RemoveShape(int index) {
	if (index < 0 || index >= shapes.size()) {
		return nullptr; 
	}
	Shape* shape = shapes[index];
	shapes.erase(shapes.begin() + index);
	return shape;
}
#pragma endregion