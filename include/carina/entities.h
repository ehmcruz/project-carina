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

class Player : public Character
{
public:
	Player (World *world_, const Point& position_);
};

// ---------------------------------------------------

} // end namespace Game

#endif