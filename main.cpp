#include <SDL.h>
#include <SDL_ttf.h>
#include "videoposter.h"
#include "Scroll.h"
#include "window.h"
#include<iostream>
#include "genre.h"
#include "videoPage.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include "pelicula.h"

int TestFunction(int i) {
	std::cout << "Test function called!" << i << std::endl;
	return i;
}

std::map<std::string, std::vector<Video>> GetMovies(std::string filepath, TTF_Font* font, Page* page) {
	std::ifstream file(filepath);
	std::map<std::string, std::vector<Video>> genres;

	std::string line;
	int lineNumber = 1;

	while (std::getline(file, line)) {
		if (line.empty()) {
			lineNumber++;
			continue;
		}

		std::stringstream ss(line);
		std::string idStr, name, length, genre, ratingStr;

		if (!std::getline(ss, idStr, ',') ||
			!std::getline(ss, name, ',') ||
			!std::getline(ss, length, ',') ||
			!std::getline(ss, genre, ',') ||
			!std::getline(ss, ratingStr, ',')) {
			std::cerr << "Malformed line at " << lineNumber << ": " << line << "\n";
			lineNumber++;
			continue;
		}

		try {
			int id = std::stoi(idStr);
			float rating = std::stof(ratingStr);

			Pelicula pelicula(id, name, genre, rating, length);
			genres[genre].push_back(pelicula);
		}
		catch (const std::exception& e) {
			std::cerr << "Conversion error at line " << lineNumber << ": " << e.what() << "\n";
		}

		lineNumber++;
	}

	file.close();

	return genres;
}

void GenerateRows(std::map<std::string, std::vector<Video>> genres, TTF_Font *font, Page *page) {

	int count = 0;

	for (const auto& pair : genres) {
		const std::string& genreName = pair.first;
		const std::vector<Video>& peliculas = pair.second;

		std::vector<std::string> videoNames;
		for (const Video& p : peliculas) {
			videoNames.push_back(p.GetName());
		}

		Genre* genre = new Genre(genreName, videoNames, 150 + 450 * count, font, { 0, 0, 0 }, { 250, 50, 10 }, page);
		count++;
	}
}


int main(int argc, char* argv[]) {
	if (TTF_Init() == -1) {
		std::cerr << "TTF_Init error: " << TTF_GetError() << "/n";
		return false;
	}

	SDL_Init(SDL_INIT_VIDEO);

	char* base = SDL_GetBasePath();
	std::string basePath = base ? base : ""; 
	SDL_free(base);

	std::string fontPath = basePath + "assets/fonts/Maax.ttf";

	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 100);
	if (font == nullptr) {
		std::cerr << "Font load error: " << TTF_GetError() << "/n";
		return false;
	}

	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = {250, 50, 10};
	SDL_Color black = { 0, 0, 0 };

	Window *window = new Window(1000, 750, "Rotten Apples", 60, white);

	Image* logo = new Image("logo.png", 500-322/2, 25);
	Shape* background = new Shape(0, 20, 1000, 120, red);

	Page* page1 = new Page();

	std::map<std::string, std::vector<Video>> genres = GetMovies(basePath + "assets/archivos/Peliculas.txt", font, page1);
	
	GenerateRows(genres, font, page1);

	page1->SetBackgroundColor(white);

	page1->AddShape(background);
	page1->AddShape(logo);

	window->AddPage(page1);
	
	window->Start();

	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
