#include "video.h"

class Episode : public Video {
public:
   Episode();
   Episode(int id, std::string& epid, std::string& name, std::string& length, float rating, int season)
       : Video(id, name, genre, rating), season(season), length(length), epid(epid) {}
   ~Episode();

   int getSeason() { return season; };

private:
   int season;
   std::string length;
   std::string epid;
};
