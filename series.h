#pragma once
#include "video.h"
#include "episode.h"
#include "textbox.h"
#include <vector>
#include <string>

class Series : public Video {
public:
    Series();
    Series(int id, const std::string& name, const std::string& genre, float rating, int seasons);
    ~Series();

    void AddEpisode(Episode ep);
    const std::vector<Episode>& GetEpisodes() const;
    std::string GetGenre() const;
    float getRating() override;

    void StartPage(Page* page, TTF_Font* font, SDL_Color) override;

private:
    std::vector<Episode> episodes;
    std::vector<std::vector<Episode>> Seasons;
    int seasons;
};
