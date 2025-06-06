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

#define _MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUES_ \
	_MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUE_(Tree) \
	_MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUE_(Character)

enum class EntityType : uint32_t {
	#define _MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUE_(V) V,
	_MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUES_
	#undef _MYLIB_ENUM_CLASS_ENTITY_TYPE_VALUE_
};

// when add subtypes, first we specify the type, and then the subtype

#define _MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUES_ \
	_MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_(Tree, Tree_00) \
	_MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_(Character, Player)

enum class EntitySubType : uint32_t {
	#define _MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_(TYPE, V) V,
	_MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUES_
	#undef _MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_
};

inline constexpr EntityType get_type (const EntitySubType subtype) noexcept
{
	static constexpr EntityType types__[] = {
		#define _MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_(TYPE, V) EntityType::TYPE,
		_MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUES_
		#undef _MYLIB_ENUM_CLASS_ENTITY_SUBTYPE_VALUE_
	};

	return types__[std::to_underlying(subtype)];
}

// ---------------------------------------------------

#define _MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUES_ \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(South) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(SouthWest) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(West) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(NorthWest) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(North) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(NorthEast) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(East) \
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(SouthEast)

enum class Direction : uint32_t {
	#define _MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_(V) V,
	_MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUES_
	#undef _MYLIB_ENUM_CLASS_OBJECT_DIRECTION_VALUE_
};

inline constexpr Vector2 get_direction_vector (const Direction direction) noexcept
{
	static constexpr std::array<Vector2, 8> direction_vector = {
		Vector2(0, -1),      // South
		Vector2(-1, -1),     // SouthWest
		Vector2(-1, 0),     // West
		Vector2(-1, 1),    // NorthWest
		Vector2(0, 1),     // North
		Vector2(1, 1),     // NorthEast
		Vector2(1, 0),      // East
		Vector2(1, -1)       // SouthEast
	};

	return direction_vector[std::to_underlying(direction)];
}

// ---------------------------------------------------

class DynamicEntity2D : public MyGlib::Game::DynamicEntity2D
{
public:
	DynamicEntity2D (const EntitySubType subtype_)
		: MyGlib::Game::DynamicEntity2D(static_cast<MyGlib::Game::DynamicEntity2D::UserData>(subtype_))
	{
	}

	EntitySubType get_subtype () const noexcept
	{
		return static_cast<EntitySubType>(this->user_data);
	}

	EntityType get_type () const noexcept
	{
		return Game::get_type(this->get_subtype());
	}
};

// ---------------------------------------------------

class Character : public DynamicEntity2D
{
public:
	using DynamicEntity2D::DynamicEntity2D;
};

// ---------------------------------------------------

class Player : public Character, public UpdateInterface
{
private:
	MyGlib::Event::KeyDown::Descriptor event_key_down_d;
	Direction direction = Direction::South;

public:
	Player (World *world_, const Point& position_);
	~Player ();

	void event_key_down_callback (const MyGlib::Event::KeyDown::Type& event);
	void process_update (const float dt) override final;
};

// ---------------------------------------------------

} // end namespace Game

#endif