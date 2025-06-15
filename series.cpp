#include "series.h"


Series::Series()
    : Video(), seasons(0) {}
Series::Series(int id, const std::string& name, const std::string& genre, float rating, int seasons)
    : Video(id, name, genre, rating), seasons(seasons) {
}

Series::~Series() {
}

void Series::AddEpisode(Episode ep) {
    episodes.push_back(ep);
}

const std::vector<Episode>& Series::GetEpisodes() const {
    return episodes;
}

std::string Series::GetGenre() const {
    return genre;
}
