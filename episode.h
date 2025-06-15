#include "video.h"

class Episode : public Video {
public:
   Episode();
   Episode(int id, const std::string& epid, const std::string& name, const std::string& genre, const std::string& length, float rating, int season)
       : Video(id, name, genre, rating), season(season), length(length), epid(epid) {}
   ~Episode();

   std::string getLength() { return length; }
   int getSeason() { return season; }

   void StartPage(Page* page, TTF_Font* font, SDL_Color, Window* window) override;

private:
   int season;
   std::string length;
   std::string epid;
};
