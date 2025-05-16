#ifndef __PROJECT_CARINA_TYPES_HEADER_H__
#define __PROJECT_CARINA_TYPES_HEADER_H__

#ifdef __MINGW32__
	#define SDL_MAIN_HANDLED
#endif

#include <chrono>

#include <SDL.h>

#include <my-lib/std.h>
#include <my-lib/coroutine.h>
#include <my-lib/macros.h>
#include <my-lib/math-vector.h>
#include <my-lib/math-geometry.h>
#include <my-lib/math-quaternion.h>
#include <my-lib/math-matrix.h>

#include <my-game-lib/my-game-lib.h>
#include <my-game-lib/opengl/opengl.h>
#include <my-game-lib/game/game.h>


namespace Game
{

// ---------------------------------------------------

using MyGlib::Graphics::Point2;
using MyGlib::Graphics::Vector2;
using Vector = Vector2;
using Point = Vector;
using MyGlib::Graphics::Color;
using MyGlib::Graphics::Rect2D;
using MyGlib::Graphics::Circle2D;
using MyGlib::Graphics::TextureDescriptor;
using MyGlib::Graphics::TextureRenderOptions;

using Colors = MyGlib::Graphics::Colors;
using AudioDescriptor = MyGlib::Audio::Descriptor;

using namespace MyGlib::Game;

using Line = Mylib::Math::Line<float, 2>;

using MyGlib::Game::Clock;
using MyGlib::Game::ClockDuration;
using MyGlib::Game::ClockTime;

using FooEvent = int;

using MyGlib::Game::Coroutine;

// ---------------------------------------------------

using MyGlib::dprintln;
using MyGlib::dprint;

// ---------------------------------------------------

} // end namespace Game

#endif