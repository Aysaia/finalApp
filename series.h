#pragma once
#include "video.h"
#include "episode.h"
#include <vector>
#include <string>

class Series : public Video {
public:
    Series();
    Series(int id, const std::string& name, const std::string& genre, float rating, int seasons);
    ~Series();

    void AddEpisode(Episode* ep);
    const std::vector<Episode*>& GetEpisodes() const;
    std::string GetGenre() const;

private:
    std::vector<Episode*> episodes;
    int seasons;
};
