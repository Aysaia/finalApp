#pragma once
#include "shape.h"
#include <functional>
class Button
{
public:
	Button();
	~Button();

	void OnPress();
private:
	std::function<void(int)> onClick;
};