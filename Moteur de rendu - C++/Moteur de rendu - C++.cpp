// Moteur de rendu - C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Window.h"
#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char* argv[]) {
    Window window("Ma fenêtre SDL", 800, 600);

    GameObject object(window.getRenderer(), "panda.bmp", 100, 100, 50, 50);

    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        window.clear();

        // Affichez l'objet
        object.render();

        window.render();
    }

    return 0;
}


