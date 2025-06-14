#pragma once
#include "Page.h"
#include "Image.h"
#include "Shape.h"
#include "Textbox.h"
#include "button.h"
#include "pelicula.h"
#include <string>

class VideoPage : public Page {
public:	
	VideoPage(std::string name, TTF_Font *font);
	VideoPage(Pelicula, TTF_Font* font);
	~VideoPage();
};