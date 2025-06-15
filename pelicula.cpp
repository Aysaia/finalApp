#include "pelicula.h"

Pelicula::Pelicula(int id, const std::string& name, const std::string& genre, float rating, const std::string& length) : Video(id, name, genre, rating), length("") {
	this->length = length;
	
}
void Pelicula::StartPage(Page* page, TTF_Font *font, SDL_Color color, Window* window) {
   std::string durationText = "Duration: " + length;  
   Textbox *lengthTextbox = new Textbox(500, 400, 200, 200, durationText, font, color, color);  
   page->AddShape(lengthTextbox);

}
Pelicula::~Pelicula() {
}