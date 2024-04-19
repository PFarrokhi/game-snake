#ifndef __SNAKE__
#define __SNAKE__

#include <SDL.h>
#include "Body.hpp"

class Snake
{
public:
	Snake(void);
	~Snake(void);
	void start(void);
	void update(void);
	void draw(void);
private:
	SDL_Window *window;
	SDL_Surface *windowSurface;
	SDL_Event windowEvent;
	Body body;
};

#endif
