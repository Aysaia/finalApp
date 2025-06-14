#include "video.h"


Video::Video()
{
	id = 0;
	name = "";
	genre = "";
	rating = 0.0f;
}

Video::Video(int id, const std::string& name, const std::string& genre, float rating)
	: id(id), name(name), genre(genre), rating(rating) {
}

float Video::getRating() { return rating; }

Video::~Video()
{
}
