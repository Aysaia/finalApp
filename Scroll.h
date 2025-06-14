#pragma once
#include <vector>
#include "Shape.h"

class Scroll :public Shape
{
public:

	Scroll(int x, int y, int w, int h, int xS = 5, int yS = 5);
	Scroll(int x, int y, int w, int h, std::vector<Shape*> shapes, int xS = 5, int yS = 5);
	~Scroll();

	void Move(int dx, int dy);
	void AddShape(Shape* shape);
private:
	std::vector<Shape*> shapes;
	int yS, xS;
};