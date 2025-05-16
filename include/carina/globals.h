#ifndef __PROJECT_CARINA_GLOBALS_HEADER_H__
#define __PROJECT_CARINA_GLOBALS_HEADER_H__

#ifdef __MINGW32__
	#define SDL_MAIN_HANDLED
#endif

#include <SDL.h>

#include <my-game-lib/game/game.h>


namespace Game
{

// ---------------------------------------------------

using MyGlib::Game::game_lib;
using MyGlib::Game::event_manager;
using MyGlib::Game::audio_manager;
using MyGlib::Game::renderer;
using MyGlib::Game::memory_manager;
using MyGlib::Game::random_generator;
using MyGlib::Game::timer;
using MyGlib::Game::interpolation_manager;

// ---------------------------------------------------

} // end namespace Game

#endif