#include "videoposter.h"

#pragma region VideoPoster
VideoPoster::VideoPoster(string name, int x, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page){
	string imagePath = name + ".png";
	
	this->x = x;
	this->y = y;

	for (char& c : name) {
		c = std::toupper(c);
	}

	shapes[0] = new Image(imagePath, x, y, 200);
	shapes[1] = new Textbox(x, y + 310, 200, 50, name, font, bg, fg);

	page->AddShape(shapes[0]);
	page->AddShape(shapes[1]);
	
}

VideoPoster::~VideoPoster(){
	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
}

std::vector<Shape*> VideoPoster::GetShapes() {
	std::vector<Shape*> result;
	for (int i = 0; i < 2; i++) {
		result.push_back(shapes[i]);
	}
	return result;
}
#pragma endregion