#include "episode.h"

Episode::Episode() : Video(), season(0), length("00:00"), epid("0-0") {}

Episode::Episode(int id, const std::string& epid, const std::string& name, const std::string& genre, const std::string& length, float rating, int season)
    : Video(id, name, genre, rating), season(season), length(length), epid(epid) {}

Episode::~Episode() {}

void Episode::StartPage(Page* page, TTF_Font* font, SDL_Color color, Window* window) {

}