#pragma once
#include <SDL.h>
#include <string>
#include "shape.h"

class Image : public Shape {
public:
    Image();
    Image(const std::string& fileName, int x, int y, double scale = 1);
    Image(const std::string& fileName, int x, int y, int width);
    ~Image();

    virtual void Load();
    bool Render(SDL_Renderer* renderer) override;

protected:
    std::string basePath = "assets/images";
    std::string fileName;
    SDL_Surface* surface = nullptr;
    double scale = 1;
};

class Star : public Image {
public:
    Star(int x, int y, double scale = 1) : Image("nostar.png", x, y, scale) {};
    Star(int x, int y, int width) : Image("nostar.png", x, y, width) {};

    void Load() override;
    void Click(bool active) { 
        if(this->active != active){
            this->active = active;
            Load();
        }
    };

private:
    bool active = false;

};
