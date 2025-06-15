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
#include "series.h"

int TestFunction(int i) {
	std::cout << "Test function called!" << i << std::endl;
	return i;
}

std::map<std::string, std::vector<Video>> GetShows(std::string filepath, TTF_Font* font, Page* page) {
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
		std::string sidStr, sname, genre, seasonsStr, ratingStr;

		if (!std::getline(ss, sidStr, ',') ||
			!std::getline(ss, sname, ',') ||
			!std::getline(ss, genre, ',') ||
			!std::getline(ss, seasonsStr, ',') ||
			!std::getline(ss, ratingStr, ',')) {
			std::cerr << "Malformed line at " << lineNumber << ": " << line << "\n";
			lineNumber++;
			continue;
		}

		try {
			int sid = std::stoi(sidStr);
			int seasons = std::stoi(seasonsStr);
			float rating = std::stof(ratingStr);

			Series s(sid, sname, genre, rating, seasons);
			genres[genre].push_back(s);
		}
		catch (const std::exception& e) {
			std::cerr << "Conversion error at line " << lineNumber << ": " << e.what() << "\n";
		}

		lineNumber++;
	}

	file.close();
	return genres;
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

void GenerateRows(std::map<std::string, std::vector<Video>> genres, TTF_Font *font, Page *page, Window *window) {

	int count = 0;

	for (const auto& pair : genres) {
		const std::string& genreName = pair.first;
		const std::vector<Video>& peliculas = pair.second;

		std::vector<std::string> videoNames;
		for (const Video& p : peliculas) {
			videoNames.push_back(p.GetName());
		}

		Genre* genre = new Genre(genreName, videoNames, 150 + 450 * count, font, { 0, 0, 0 }, { 250, 50, 10 }, page, window);
		count++;
	}
}
std::map<std::string, std::vector<Video>> CombineGenres(
	const std::map<std::string, std::vector<Video>>& map1,
	const std::map<std::string, std::vector<Video>>& map2)
{
	std::map<std::string, std::vector<Video>> combined = map1;

	for (const auto& pair : map2) {
		const std::string& genre = pair.first;
		const std::vector<Video>& videos = pair.second;
		combined[genre].insert(combined[genre].end(), videos.begin(), videos.end());
	}

	return combined;
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
	window->AddPage(page1);

	std::map<std::string, std::vector<Video>> showgenres = GetShows(basePath + "assets/archivos/Series.txt", font, page1);
	std::map<std::string, std::vector<Video>> moviegenres = GetMovies(basePath + "assets/archivos/Peliculas.txt", font, page1);
	
	auto combinedGenres = CombineGenres(showgenres, moviegenres);

	GenerateRows(combinedGenres, font, page1, window);

	page1->SetBackgroundColor(white);

	page1->AddShape(background);
	page1->AddShape(logo);

	
	window->Start();

	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
