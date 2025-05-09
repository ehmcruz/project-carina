#include <my-game-lib/my-game-lib.h>
#include <my-game-lib/game/game.h>
#include <my-game-lib/game/components-2d.h>
#include <my-game-lib/debug.h>

#include <carina/types.h>
#include <carina/globals.h>
#include <carina/lib.h>
#include <carina/world.h>


// ---------------------------------------------------

namespace Game
{

// ---------------------------------------------------

Player::Player (World *world_, const Point& position_)
	: Character(world_, 0, position_, Vector::zero())
{
	unique_ptr<Rect2DRenderer> rect = make_unique<Rect2DRenderer>(this, position_, Vector(1.0f, 1.0f), Colors::green);
	this->add_child(std::move(rect));
}

// ---------------------------------------------------

} // end namespace Game