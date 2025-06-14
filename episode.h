#pragma once
#include "video.h"
#include <string>

class Episode : public Video {
public:
    Episode();
    Episode(int id, const std::string& name, float rating,
        int season, const std::string& length, const std::string& epid);
    Episode(int id, const std::string& name, const std::string& genre, float rating,
        int season, const std::string& length, const std::string& epid)
        : Video(id, name, genre, rating), season(season), length(length), epid(epid) {}
    ~Episode();

private:
    int season;
    std::string length;
    std::string epid;
};
