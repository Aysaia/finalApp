#include "videoPage.h"
#include <iostream>
#include <format>
#include <sstream>

VideoPage::VideoPage(std::string name, TTF_Font *font) : Page() {
	SDL_Color black = { 0, 0, 0, 255 };
	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Color red = { 250, 50, 10, 255 };

	Image* poster = new Image("posters_peliculas/" + name + ".png", 50, 50, 400);
	Shape* back = new Shape(40, 0, 420, 750, red); 
	
	for (char& c : name) {
		c = std::toupper(c);
	}

	Textbox* title = new Textbox(500, 40, 400, 50, name, font, black, black);

	this-> SetBackgroundColor(white);

	this->AddShape(back);
	this->AddShape(poster);
	this->AddShape(title);
}

VideoPage::VideoPage(Video video, TTF_Font* font) : Page() {
	SDL_Color black = { 0, 0, 0, 255 };
	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Color red = { 250, 50, 10, 255 };
	Image* poster = new Image("posters_peliculas/" + video.GetName() + ".png", 50, 50, 400);
	Shape* back = new Shape(40, 0, 420, 750, red);
	std::string name = video.GetName();
	for (char& c : name) {
		c = std::toupper(c);
	}

	float tRating = video.getRating();
	std::ostringstream stream;
	stream.precision(1);
	stream << std::fixed << tRating;
	Textbox* audience = new Textbox(500, 200, 200, 20, "Audience Rating (" + stream.str() + ")", font, black, black);

	int rating = round(tRating/2);
	this->AddShape(audience);
	for (int i = 0; i < 5; i++) {
		Star* starI = new Star(500 + 45 * i, 225);
		this->AddShape(starI);
		if (i<rating) starI->Click(true);
		std::cout << rating << std::endl;
	}
	Textbox* user = new Textbox(500, 125, 150, 20, "User Rating", font, black, black);
	this->AddShape(user);
	for (int i = 0; i < 5; i++) {
		Star* starI = new Star(500 + 45 * i, 150);
		Button* starB = new Button([this](int i) { this->changeRating(i); }, i, starI);
		stars[i] = starI;
		this->AddButton(starB);
		this->AddShape(starI);
	}
	Textbox* title = new Textbox(500, 40, 400, 50, name, font, black, black);
	this->SetBackgroundColor(white);
	this->AddShape(back);
	this->AddShape(poster);
	this->AddShape(title);
}

void VideoPage::changeRating(int i) {
	for (int s = 0; s < 5; s++) {
		stars[s]->Click(s<i+1);
	}
}

VideoPage::~VideoPage() {
	// Destructor logic if needed
}