#include <SDL2/SDL.h>

#include "block.h"

block::block(int x, int y)
{
	drect = {x, y, 32, 32};
	/* logic to select the texture */
}
SDL_Rect *block::get_drect()
{
	return &drect;
}
