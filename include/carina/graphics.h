#ifndef __PROJECT_CARINA_GRAPHICS_HEADER_H__
#define __PROJECT_CARINA_GRAPHICS_HEADER_H__

#ifdef __MINGW32__
	#define SDL_MAIN_HANDLED
#endif

#include <SDL.h>

#include <my-game-lib/graphics.h>

#include <carina/types.h>


namespace Game
{

// ---------------------------------------------------

namespace Texture
{
	inline TextureDescriptor grass;
	inline TextureDescriptor water;
	inline TextureDescriptor tree_00;
}

// ---------------------------------------------------

void load_graphics ();

// ---------------------------------------------------

} // end namespace Game

#endif