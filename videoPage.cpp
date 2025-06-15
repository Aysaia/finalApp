#include "videoPage.h"

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
VideoPage::VideoPage(Pelicula pelicula, TTF_Font* font) : Page() {
	SDL_Color black = { 0, 0, 0, 255 };
	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Color red = { 250, 50, 10, 255 };
	Image* poster = new Image(pelicula.GetName() + ".png", 50, 50, 400);
	Shape* back = new Shape(40, 0, 420, 750, red);
	std::string name = pelicula.GetName();
	for (char& c : name) {
		c = std::toupper(c);
	}
	Textbox* title = new Textbox(500, 40, 400, 50, name, font, black, black);
	this->SetBackgroundColor(white);
	this->AddShape(back);
	this->AddShape(poster);
	this->AddShape(title);
}

VideoPage::~VideoPage() {
	// Destructor logic if needed
}