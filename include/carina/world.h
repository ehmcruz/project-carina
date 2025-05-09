#ifndef __PROJECT_CARINA_WORLD_HEADER_H__
#define __PROJECT_CARINA_WORLD_HEADER_H__

#include <my-lib/macros.h>
#include <my-lib/std.h>

#include <my-game-lib/game/game.h>
#include <my-game-lib/game/components-2d.h>

#include <carina/types.h>
#include <carina/entities.h>


namespace Game
{

// ---------------------------------------------------

class World : public Scene2D
{
protected:
	Character *player;

public:
	World ();
	void setup_render () override final;
};

// ---------------------------------------------------

} // end namespace Game

#endif