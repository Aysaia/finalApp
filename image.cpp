#include "image.h"
#include <SDL_image.h>

#pragma region Constructors and Destructor
Image::Image() : Shape() {
    fileName = "default.png";
    Load();
}

Image::Image(const std::string& fileName, int x, int y)
    : Shape(0, 0, x, y), fileName(fileName) {
    Load();
}

Image::~Image() {
    if (surface) {
        SDL_FreeSurface(surface);
    }
}
#pragma endregion

#pragma region Functions
void Image::Load() {
    char* sdlBasePath = SDL_GetBasePath();
    std::string fullPath = std::string(sdlBasePath) + basePath + "/" + fileName;
    SDL_free(sdlBasePath);

    surface = IMG_Load(fullPath.c_str());
    if (!surface) {
        SDL_Log("Failed to load image: %s, SDL_image Error: %s", fullPath.c_str(), IMG_GetError());
        return;
    }

    width = surface->w;
    height = surface->h;
}

bool Image::Render(SDL_Renderer* renderer) {
    if (!surface || !renderer) {
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return false;
    }

    SDL_Rect rect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);

    return true;
}
#pragma endregion
