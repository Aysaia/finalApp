#include "pelicula.h"

Pelicula::Pelicula(int id, const std::string& name, const std::string& genre, float rating, const std::string& length) : Video(id, name, genre, rating), length("") {
	this->length = length;
}
void Pelicula::StartPage(Page* page, TTF_Font *font) {

}
Pelicula::~Pelicula() {
}