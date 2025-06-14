#include "Scroll.h"
Scroll::Scroll(int x, int y, int w, int h, int xS, int yS) :Shape(x, y, w, h, {50,50,50}) {
	this->xS = xS;
	this->yS = yS;
}
Scroll::Scroll(int x, int y, int w, int h, std::vector<Shape*> shapes, int xS, int yS) :Shape(x, y, w, h,{50,50,50,50}) {
	this->xS = xS;
	this->yS = yS;
	this->shapes = shapes;
}
Scroll::~Scroll() {
}

void Scroll::Move(int x, int y) {
	for (Shape* shape : shapes) {
		shape->Move(x*xS, y*yS);
	}
}
void Scroll::AddShape(Shape* shape) {
	shapes.push_back(shape);
}