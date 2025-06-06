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
	: Character(EntitySubType::Player)
{
	this->set_translation(position_);
	unique_ptr<Rect2DRenderer> rect = make_unique<Rect2DRenderer>(Vector(1.0f, 1.0f), Colors::green);
	this->add_child(std::move(rect));

	this->event_key_down_d = event_manager->key_down().subscribe( Mylib::Event::make_callback_object<MyGlib::Event::KeyDown::Type>(*this, &Player::event_key_down_callback) );
}

// ---------------------------------------------------

Player::~Player ()
{
	event_manager->key_down().unsubscribe(this->event_key_down_d);
}

// ---------------------------------------------------

void Player::event_key_down_callback (const MyGlib::Event::KeyDown::Type& event)
{
}

// ---------------------------------------------------

void Player::process_update (const float dt)
{
	constexpr float speed = 2.0f;

	constexpr auto key_down = SDL_SCANCODE_DOWN;
	constexpr auto key_up = SDL_SCANCODE_UP;
	constexpr auto key_left = SDL_SCANCODE_LEFT;
	constexpr auto key_right = SDL_SCANCODE_RIGHT;

	bool stop = false;

	if (event_manager->is_key_down(key_down)) {
		if (event_manager->is_key_down(key_right))
			this->direction = Direction::SouthEast;
		else if (event_manager->is_key_down(key_left))
			this->direction = Direction::SouthWest;
		else
			this->direction = Direction::South;
	}
	else if (event_manager->is_key_down(key_up)) {
		if (event_manager->is_key_down(key_right))
			this->direction = Direction::NorthEast;
		else if (event_manager->is_key_down(key_left))
			this->direction = Direction::NorthWest;
		else
			this->direction = Direction::North;
	}
	else {
		if (event_manager->is_key_down(key_right))
			this->direction = Direction::East;
		else if (event_manager->is_key_down(key_left))
			this->direction = Direction::West;
		else {
			// keep last direction
			stop = true;
		}
	}

	if (!stop) {
		const Vector2 new_vel = get_direction_vector(this->direction).to_length(speed);
		this->set_velocity(new_vel);
	}
	else {
		this->set_velocity(Vector2::zero());
	}
}

// ---------------------------------------------------

} // end namespace Game