#include "genre.h"

Genre::Genre(std::string title, std::vector<std::string> videoNames, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page) {
	this->videoNames = videoNames;
	this->title = new Textbox(50, y, 100, 100, title, font, fg, bg);

	page->AddShape(this->title);

	this->scroll = new Scroll(0, 0, 1000, 5000, 5, 5);
	page->AddScroll(scroll);
	this->scroll->AddShape(this->title);
	int count = 0;
	for (std::string name:videoNames)
	{
		VideoPoster* poster = new VideoPoster(name, 50 + 250*count, y + 50, font, fg, bg, page);
		posters.push_back(poster);

		scroll->AddShape(poster->GetShapes()[0]);
		scroll->AddShape(poster->GetShapes()[1]);
		
		count++;
	}

}

Genre::~Genre() {
	delete title;
	delete scroll;
	for (VideoPoster* poster : posters) {
		delete poster;
	}
}