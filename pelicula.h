#pragma once
#include "video.h"

class Pelicula :public Video
{
public:
	Pelicula(int id, const std::string& name, const std::string& genre, float rating, const std::string& length);
	~Pelicula();

private:
	std::string length;
};
