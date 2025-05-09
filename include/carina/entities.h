#ifndef __PROJECT_CARINA_ENTITIES_HEADER_H__
#define __PROJECT_CARINA_ENTITIES_HEADER_H__

#include <my-lib/macros.h>
#include <my-lib/std.h>

#include <my-game-lib/game/game.h>
#include <my-game-lib/game/components-2d.h>

#include <carina/types.h>


namespace Game
{

// ---------------------------------------------------

class World;

// ---------------------------------------------------

class Character : public DynamicEntity2D
{
public:
	using DynamicEntity2D::DynamicEntity2D;
};

// ---------------------------------------------------

class Player : public Character
{
public:
	Player (World *world_, const Point& position_);
};

// ---------------------------------------------------

} // end namespace Game

#endif