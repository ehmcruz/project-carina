#include <my-game-lib/my-game-lib.h>
#include <my-game-lib/debug.h>

#include <carina/types.h>
#include <carina/globals.h>


// ---------------------------------------------------

namespace Game
{

// ---------------------------------------------------

int main (int argc, char **argv)
{
	Mylib::Memory::DefaultManager memory_manager;
	unique_ptr<Entity> entity = make_unique<Entity>(memory_manager, 0);

	constexpr float target_dt = 1.0f / 60.0f;

	Main *game = Main::load({
		.window_name = "Carina Project",
		.window_width_px = 1920,
		.window_height_px = 1080,
		.fullscreen = false,
		.target_dt = target_dt,
		.max_dt = 1.0f / 10.0f,
		.sleep_to_save_cpu = true,
		.sleep_threshold = target_dt * 0.9f,
		.busy_wait_to_ensure_fps = true
	}, entity.get());
	
	game->run();

	Main::unload();
}

// ---------------------------------------------------

} // end namespace Game

// ---------------------------------------------------

int main (int argc, char **argv)
{
	try {
		return Game::main(argc, argv);
	}
	catch (const std::exception& e) {
		Game::dprintln("Something bad happened!", '\n', e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}