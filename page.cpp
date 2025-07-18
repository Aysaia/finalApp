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
void Page::CheckButtons(int x, int y) {
	for (Button* button : buttons) {
		if (button->Hover(x, y)) {
			button->Click();
			break;
		}
	}
}
void Page::Scrollin(int x, int y, int dx, int dy) {
	for (Scroll * scroll : scrolls) {
		if (scroll->Hover(x, y)) {
			scroll->Move(dx, dy);
		}
	}
}

int Page::AddShape(Shape* shape) {
	if (shape == nullptr) {
		return -1;
	}
	shapes.push_back(shape);
	return static_cast<int>(shapes.size());
}
int Page::AddButton(Button* button) {
	if (button == nullptr) {
		return -1;
	}
	buttons.push_back(button);
	return buttons.size() - 1; 
}
int Page::AddScroll(Scroll* scroll) {
	if (scroll == nullptr) {
		return -1;
	}
	scrolls.push_back(scroll);
	return scrolls.size() - 1;
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