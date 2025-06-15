#pragma once
#include "Page.h"
#include "Image.h"
#include "Shape.h"
#include "Textbox.h"
#include "button.h"
#include "pelicula.h"
#include "series.h"
#include <string>

class VideoPage : public Page {
public:	
	VideoPage(std::string name, TTF_Font *font);
	VideoPage(Video, TTF_Font* font);
	~VideoPage();
};