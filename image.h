#pragma once
#include <SDL.h>
#include <string>
#include "shape.h"

class Image : public Shape {
public:
    Image();
    Image(const std::string& fileName, int x, int y);
    ~Image();

    void Load();
    bool Render(SDL_Renderer* renderer) override;

private:
    std::string basePath = "assets/images";
    std::string fileName;
    SDL_Surface* surface = nullptr;
};
