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

void GenerateRows(
	const std::map<std::string, std::vector<Video*>>& genres,
	TTF_Font* font,
	Page* page,
	Window* window)
{
	int count = 0;

	for (const auto& pair : genres) {
		const std::string& genreName = pair.first;
		std::vector<Video*> videosPtr = pair.second;

		std::sort(videosPtr.begin(), videosPtr.end(), [](Video* a, Video* b) {
			return a->getRating() > b->getRating();
		});

		std::cout << "--- Genero: " << genreName << " ---" << std::endl;
		for (auto* v : videosPtr) {
			std::string tipo = (dynamic_cast<Series*>(v) != nullptr) ? "Serie" : "Pelicula";
			std::cout << tipo << ": " << v->GetName() << " - " << v->getRating() << std::endl;
		}
		std::cout << "--- Fin Genero: " << genreName << " ---" << std::endl;

		Genre* genre = new Genre(genreName, videosPtr, 150 + 450 * count, font, { 0,0,0 }, { 250,50,10 }, page, window);

		int y = 150 + 450 * count; // Example y-coordinate
		SDL_Color color = { 0, 0, 0 };
		SDL_Color accent = { 250, 50, 10 };

		for (auto* video : videosPtr) {
			VideoPoster* poster = new VideoPoster(video->GetName(), 150 + 250 * count, y + 50, font, color, accent, page);
			Shape* post = poster->GetShapes()[0];
			Button* button = new Button([window, video](int i) { 
				std::cout << "Pelicula ID: " << video->GetID() << std::endl; 
				window->SetPage(i); 
			}, window->GetPageNum(), post);
		}

		count++;
	}
}


std::map<std::string, std::vector<Video*>> CombineGenres(
	const std::map<std::string, std::vector<Video*>>& shows,
	const std::map<std::string, std::vector<Video*>>& movies
) {
	std::map<std::string, std::vector<Video*>> combined = shows;

	for (const auto& pair : movies) {
		const std::string& genre = pair.first;
		const std::vector<Video*>& movieList = pair.second;
		auto& combinedList = combined[genre];
		combinedList.insert(combinedList.end(), movieList.begin(), movieList.end());
	}

	return combined;
}

std::map<std::string, std::vector<Video*>> GetShows(std::string filepath, TTF_Font* font, Page* page) {
	std::ifstream file(filepath);
	std::map<std::string, std::vector<Video*>> genres;

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
			std::cout << "Serie ID leido: " << sid << std::endl;
			int seasons = std::stoi(seasonsStr);
			float rating = std::stof(ratingStr);

			Series* s = new Series(sid, sname, genre, rating, seasons);
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

std::map<std::string, std::vector<Video*>> GetMovies(std::string filepath, TTF_Font* font, Page* page) {
	std::ifstream file(filepath);
	std::map<std::string, std::vector<Video*>> genres;

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
			std::cout << "Pelicula ID leido: " << id << std::endl;
			float rating = std::stof(ratingStr);

			Pelicula* pelicula = new Pelicula(id, name, genre, rating, length);
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
	if (!font) {
		std::cerr << "Font load error: " << TTF_GetError() << "/n";
		return false;
	}

	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = { 250, 50, 10 };
	SDL_Color black = { 0, 0, 0 };

	Window* window = new Window(1000, 750, "Rotten Apples", 60, white);
	Page* page1 = new Page();
	window->AddPage(page1);

	Image* logo = new Image("logo.png", 500 - 322 / 2, 25);


	auto showgenres = GetShows(basePath + "assets/archivos/Series.txt", font, page1);
	auto moviegenres = GetMovies(basePath + "assets/archivos/Peliculas.txt", font, page1);

	std::map<int, Series*> seriesById;
	for (auto& pair : showgenres) {
		for (Video* vid : pair.second) {
			Series* s = dynamic_cast<Series*>(vid);
			if (s) {
				seriesById[s->GetID()] = s;
			}
		}
	}

	std::ifstream epfile(basePath + "assets/archivos/Episodios.txt");
	std::string line;
	int lineNumber = 1;

	while (std::getline(epfile, line)) {
		if (line.empty()) { lineNumber++; continue; }

		std::stringstream ss(line);
		std::string idStr, idEp, name, length, ratingStr, seasonStr;

		if (!std::getline(ss, idStr, ',') ||
			!std::getline(ss, idEp, ',') ||
			!std::getline(ss, name, ',') ||
			!std::getline(ss, length, ',') ||
			!std::getline(ss, ratingStr, ',') ||
			!std::getline(ss, seasonStr, ',')) {
			std::cerr << "Malformed line at " << lineNumber << ": " << line << "\n";
			lineNumber++;
			continue;
		}

		try {
			int seriesId = std::stoi(idStr);
			int season = std::stoi(seasonStr);
			float rating = std::stof(ratingStr);

			auto it = seriesById.find(seriesId);
			if (it != seriesById.end()) {
				std::string genre = it->second->GetGenre(); // <-- Solución aquí
				Episode ep(seriesId, idEp, name, genre, length, rating, season);
				it->second->AddEpisode(ep);
			} else {
				std::cerr << "No matching series found for episode on line " << lineNumber << ", ID: " << seriesId << "\n";
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Conversion error at line " << lineNumber << ": " << e.what() << "\n";
		}

		lineNumber++;
	}

	epfile.close();

	auto combinedGenres = CombineGenres(showgenres, moviegenres);

	GenerateRows(combinedGenres, font, page1, window);

	page1->SetBackgroundColor(white);

	page1->AddShape(logo);

	Shape s;
	s.Move(5, 10); // Imprime: Move(dx, dy) llamado
	SDL_Point p = {2, 3};
	s.Move(p);     // Imprime: Move(SDL_Point) llamado

	window->Start();

	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	for (auto& pair : showgenres) {
		for (Video* v : pair.second) delete v;
	}
	for (auto& pair : moviegenres) {
		for (Video* v : pair.second) delete v;
	}

	return 0;
}
