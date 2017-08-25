#include <SDL2/SDL.h>

#include "player.h"

using namespace std;

player::player()
{
	drect = {10, 800/2, 32, 32};
	cstat = stand_still;
	grav = 0;
	falling = true;
}

SDL_Rect *player::get_drect()
{
	return &drect;
}

void player::move()
{
	switch(cstat)
	{
		case move_left:
			drect.x-=5;
			break;
		case move_right:
			drect.x+=5;
			break;
	}
	drect.y += grav;
	if(falling) grav+=1;
	else grav=0;
}
void player::set_status(player::status s1)
{
	cstat = s1;
}

void player::jump()
{
	grav = -20;
	falling = true;
}

void player::set_falling(bool flag)
{
	falling = flag;
}
bool player::on_block(block b)
{
	if(((drect.x + drect.w) >= b.get_drect()->x) && (drect.x <= (b.get_drect()->x + b.get_drect()->w)))
		if((drect.y + drect.h + grav) >= b.get_drect()->y)
			return true;
	return false;
}
