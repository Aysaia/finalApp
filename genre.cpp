#include "genre.h"

void Genre::Scrollin(int i) {
	scroll->Move(i, 0);
}

Genre::Genre(std::string titleName, std::vector<std::string> videoNames, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg, Page* page) {
	videoNames;
	Textbox *title = new Textbox(150, y, 100, 100, titleName, font, fg, bg);

	page->AddShape(title);

	scroll = new Scroll(0, 0, 1000, 5000, 50, 25);
	Scroll* buttonScroll = new Scroll(0, 0, 1000, 5000, 0, 25);
	
	Image* RightArrow = new Image("right.png", 900, y+150);
	Image* leftArrow = new Image("left.png", 50, y + 150);
	
	Button* rightButton = new Button([this](int i) { this->Scrollin(i); }, -1, RightArrow);
	Button* leftButton = new Button([this](int i) { this->Scrollin(i); }, 1, leftArrow);
	
	buttonScroll->AddShape(RightArrow);
	buttonScroll->AddShape(leftArrow);

	page->AddScroll(scroll);
	page->AddScroll(buttonScroll);

	page->AddButton(rightButton);

	page->AddButton(leftButton);

	buttonScroll->AddShape(title);
	int count = 0;
	for (std::string name:videoNames)
	{
		
		VideoPoster* poster = new VideoPoster(name, 150 + 250*count, y + 50, font, fg, bg, page);

		scroll->AddShape(poster->GetShapes()[0]);
		scroll->AddShape(poster->GetShapes()[1]);
		
		count++;
	}

	page->AddShape(leftArrow);
	page->AddShape(RightArrow);
}

Genre::~Genre() {
}