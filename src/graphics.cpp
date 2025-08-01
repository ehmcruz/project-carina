#include <my-game-lib/my-game-lib.h>
#include <my-game-lib/game/game.h>
#include <my-game-lib/game/components-2d.h>
#include <my-game-lib/debug.h>

#include <carina/types.h>
#include <carina/globals.h>
#include <carina/lib.h>
#include <carina/graphics.h>


// ---------------------------------------------------

namespace Game
{

// ---------------------------------------------------

static void load_textures ()
{
	using namespace Texture;

	renderer->begin_texture_loading();

	tree_00 = renderer->load_texture("assets/tree_00.png");

	MyGlib::Game::preload_textures_from_tmx_file(Texture::tilemap_fname_forest);

	renderer->end_texture_loading();
}

// ---------------------------------------------------

void load_graphics ()
{
	load_textures();
}

// ---------------------------------------------------

} // end namespace Game