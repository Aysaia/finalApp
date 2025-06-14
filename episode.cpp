#include "episode.h"

Episode::Episode() : Video(), season(0), length("00:00"), epid("0-0") {}

Episode::Episode(int id, const std::string& name, float rating,
    int season, const std::string& length, const std::string& epid)
    : Video(id, name, "", rating), season(season), length(length), epid(epid) {
}

Episode::~Episode() {}