#include <my-game-lib/my-game-lib.h>
#include <my-game-lib/game/game.h>
#include <my-game-lib/game/components-2d.h>
#include <my-game-lib/debug.h>

#include <carina/types.h>
#include <carina/globals.h>
#include <carina/lib.h>
#include <carina/world.h>
#include <carina/graphics.h>


// ---------------------------------------------------

namespace Game
{

// ---------------------------------------------------

void main (int argc, char **argv)
{
	constexpr float target_dt = 1.0f / 60.0f;

	MyGlib::Game::Main *game = MyGlib::Game::Main::load({
		.window_name = "Carina Project",
		.window_width_px = 1920 / 2,
		.window_height_px = 1080 / 2,
		.fullscreen = false,
		.target_dt = target_dt,
		.max_dt = 1.0f / 10.0f,
		.sleep_to_save_cpu = true,
		.sleep_threshold = target_dt * 0.9f,
		.busy_wait_to_ensure_fps = true
	});

	load_graphics();

	unique_ptr<World> world = make_unique<World>();
	game->set_scene(world.get());
	
	game->run();

	MyGlib::Game::Main::unload();
}

// ---------------------------------------------------

} // end namespace Game

// ---------------------------------------------------

int main (int argc, char **argv)
{
	try {
		Game::main(argc, argv);
	}
	catch (const std::exception& e) {
		Game::dprintln("Something bad happened!", '\n', e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}