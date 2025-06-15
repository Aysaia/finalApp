#include "genre.h"


void Genre::Scrollin(int i) {
	scroll->Move(i, 0);
}

Genre::Genre(const std::string& name, const std::vector<Video*>& videos, int y, TTF_Font* font, SDL_Color color, SDL_Color accent, Page* page, Window* window)
	: name(name), videos(videos) // Copia directa, respeta el orden
{
	this->window = window;
	//std::sort(this->videos.begin(), this->videos.end(), [](Video* a, Video* b) { return a->GetName() < b->GetName(); });

	Textbox *title = new Textbox(150, y, 100, 100, name, font, color, accent);

	page->AddShape(title);

	
	Image* RightArrow = new Image("right.png", 900, y+150);
	Image* leftArrow = new Image("left.png", 50, y + 150);
	
	Button* rightButton = new Button([this](int i) { this->Scrollin(i); }, -1, RightArrow);
	Button* leftButton = new Button([this](int i) { this->Scrollin(i); }, 1, leftArrow);
	

	page->AddScroll(scroll);

	page->AddButton(rightButton);

	page->AddButton(leftButton);

	int count = 0;
	
	Image* back = new Image("left.png", 900, 150);
	Button* backbutton = new Button([window](int i) { window->SetPage(i); }, 0, back);

	for (Video *video: videos)
	{

		VideoPoster* poster = new VideoPoster(video->GetName(), 150 + 250 * count, y + 50, font, color, accent, page);
		Shape* post = poster->GetShapes()[0];
		Button* button = new Button([window, video](int i) { 
			std::cout << "Pelicula ID: " << video->GetID() << std::endl; 
			window->SetPage(i); 
		}, window->GetPageNum(), post);
		VideoPage* videoPage = new VideoPage(video, font);

		window->AddPage(videoPage);
		video->StartPage(videoPage, font, accent, window);

		page->AddButton(button);
		videoPage->AddButton(backbutton);
		videoPage->AddShape(back);

		scroll->AddShape(poster->GetShapes()[0]);
		scroll->AddShape(poster->GetShapes()[1]);
		
		count++;
	}

	page->AddShape(leftArrow);
	page->AddShape(RightArrow);
}

Genre::~Genre() {
}