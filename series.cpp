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
void Series::StartPage(Page* page, TTF_Font* font, SDL_Color color, Window* window) {
    int s = 0;

    SDL_Color white = { 255,255,255 };
    Textbox* goBack = new Textbox(650, 125, 150, 30, "Go Back", font, white, white);
    Button* buttonBack = new Button([window](int i) {window->SetPage(i);}, window->GetPageNum()-1, goBack);
    for (std::vector<Episode> season : Seasons) {
        std::string tag = "Season.- " + std::to_string(s + 1);
        Textbox* seasonText = new Textbox(500, 400 + 35 * s, 140, 30, tag, font, color, color);
        Button* button = new Button([window](int i) { window->SetPage(i); }, window->GetPageNum(), seasonText);

        SeasonPage* seasonPage = new SeasonPage(season, font);

        seasonPage->AddShape(goBack);
        seasonPage->AddButton(buttonBack);

        window->AddPage(seasonPage);


        page->AddShape(seasonText);
        page->AddButton(button);
        //window->AddPage(seasonPage);
        s++;
    }
}


const std::vector<Episode>& Series::GetEpisodes() const {
    return episodes;
}

std::string Series::GetGenre() const {
    return genre;
}
