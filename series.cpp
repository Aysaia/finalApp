#include "series.h"


Series::Series()
    : Video(), seasons(0) {}
Series::Series(int id, const std::string& name, const std::string& genre, float rating, int seasons)
    : Video(id, name, genre, rating), seasons(seasons) {
    Seasons.resize(seasons);
}

Series::~Series() {
}

void Series::AddEpisode(Episode ep) {
    episodes.push_back(ep);
    Seasons[ep.getSeason() - 1].push_back(ep);
}
float Series::getRating() {
    if (episodes.empty()) return 0.0f;

    float total = 0.0f;
    for (int i = 0; i < episodes.size(); i++) {
        total += episodes[i].getRating();
    }

    return total / episodes.size();
}
void Series::StartPage(Page* page, TTF_Font* font, SDL_Color color) {
    int s = 0;
    for (std::vector<Episode> season : Seasons) {
        std::string tag = "Season.- " + std::to_string(s + 1);
        Textbox* seasonText = new Textbox(500, 400 + 35 * s, 140, 30, tag, font, color, color);
        page->AddShape(seasonText);
        s++;
    }
}


const std::vector<Episode>& Series::GetEpisodes() const {
    return episodes;
}

std::string Series::GetGenre() const {
    return genre;
}
