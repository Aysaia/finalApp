#pragma once
#include "shape.h"
#include <functional>
class Button
{
public:
	Button(std::function<void(int)> onClick, int i, Shape* shape);
	~Button();

	bool Hover(int x, int y);
	void Click();
private:
	int id;
	Shape *shape;
	std::function<void(int)> onClick;
};