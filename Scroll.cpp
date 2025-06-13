#include "Scroll.h"
Scroll::Scroll(int x, int y, int w, int h) :Shape(x, y, w, h) {
}
Scroll::Scroll(int x, int y, int w, int h, std::vector<Shape*> shapes) :Shape(x, y, w, h) {
	this->shapes = shapes;
}
Scroll::~Scroll() {
}

void Scroll::Move(int x, int y) {
	for (Shape* shape : shapes) {
		shape->Move(x, y);
	}
}
void Scroll::AddShape(Shape* shape) {
	shapes.push_back(shape);
}