#pragma once
#include <vector>
#include "Shape.h"
using namespace std;

class Scroll :public Shape
{
public:

	Scroll(int x, int y, int w, int h);
	Scroll(int x, int y, int w, int h, std::vector<Shape*> shapes);
	~Scroll();

	void Move(int dx, int dy);
	void AddShape(Shape* shape);
private:
	vector<Shape*> shapes;
};