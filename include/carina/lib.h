#ifndef __PROJECT_CARINA_LIB_HEADER_H__
#define __PROJECT_CARINA_LIB_HEADER_H__

#include <my-game-lib/game/game.h>

#include <carina/types.h>
#include <carina/globals.h>

namespace Game
{

// ---------------------------------------------------

template <typename T, typename... Types>
[[nodiscard]] unique_ptr<T> make_unique (Types&&... vars)
{
	return Mylib::Memory::make_unique<T>(memory_manager, std::forward<Types>(vars)...);
}

// ---------------------------------------------------

} // end namespace Game

#endif