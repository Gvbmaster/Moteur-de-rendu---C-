#include "GameObject.h"
#include "SDL.h"

GameObject::GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : renderer(renderer) {
    // Chargez l'image depuis le chemin spécifié
    SDL_Surface* surface = SDL_LoadBMP(imagePath);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
    }
}

GameObject::~GameObject() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void GameObject::render() {
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}