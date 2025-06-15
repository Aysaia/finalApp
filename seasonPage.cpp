#include "seasonPage.h"

SeasonPage::SeasonPage(std::vector<Episode> season, TTF_Font* font) : Page() {
   SDL_Color white = { 255, 255, 255 };
   SDL_Color red = { 250, 50, 10 };
   SDL_Color black = { 0, 0, 0 };

   std::string title = season[0].GetName() + " Season " + std::to_string(season[0].getSeason());
   Textbox* Title = new Textbox(125, 30, 750, 120, title, font, white, white);

   std::string eps = "# of Episodes: " + std::to_string(season.size());
   Textbox* episodeNum = new Textbox(125, 115, 200, 120, eps, font, white, white);

   float total = 0.0f;
   int count = 0;
   for (Episode ep : season) {
       total += ep.getRating();

       std::ostringstream oss;
       oss << std::fixed << std::setprecision(1) << ep.getRating();
       std::string rat = oss.str();

       
       std::string tag = "Episode #" + std::to_string(count + 1);
       Textbox* EpisodeSeason = new Textbox(15, 235 + 120 * count, 200, 100, tag, font, white, white);

       std::string rating = "Rating: " + rat;
       Textbox* Rating = new Textbox(600, 235 + 120 * count, 130, 100, rating, font, white, white);

       std::string length = "Length: " + ep.getLength();
       Textbox* Length = new Textbox(750, 235 + 120 * count, 150, 100, length, font, white, white);


       this->AddShape(Length);
       this->AddShape(Rating);
       this->AddShape(EpisodeSeason);

       count++;
   }
   total = total / season.size();

   std::ostringstream oss;
   oss << std::fixed << std::setprecision(1) << total;
   std::string rat = "Season Rating: " + oss.str();

   Textbox* seasonRat = new Textbox(125, 145, 200, 120, rat, font, white, white);
   this->AddShape(Title);
   this->AddShape(episodeNum);
   this->AddShape(seasonRat);
   this->SetBackgroundColor(white);

}

SeasonPage::~SeasonPage() {}