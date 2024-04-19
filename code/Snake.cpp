#include "Snake.hpp"
#include <iostream>
#include <string>
#include <SDL.h>

Snake::Snake(void) : window(nullptr), windowSurface(nullptr), windowEvent(), body(0, 0)
{
	std::cout << "Hello from tower defence game" << std::endl;

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

    if (!window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "Error: " << SDL_GetError() << "\n";
        return;
    }

    windowSurface = SDL_GetWindowSurface(window);

    if (!windowSurface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "Error: " << SDL_GetError() << "\n";
        return;
    }
}

Snake::~Snake(void)
{
    SDL_FreeSurface(windowSurface);
    SDL_DestroyWindow(window);

	std::cout << "Goodbye from tower defence game" << std::endl;
}

void Snake::start(void)
{
	std::cout << "The game is running..." << std::endl;
	std::cout << "enter \"end\" to finish the game" << std::endl;

	while (true)
	{
        update();

		std::string command;
		std::cin >> command;
		if (command == "end")
			break;
	}
}

void Snake::update(void)
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&windowEvent) > 0)
        {
            switch (windowEvent.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }
        }

        draw();
    }
}

void Snake::draw(void)
{
    SDL_UpdateWindowSurface(window);
}
