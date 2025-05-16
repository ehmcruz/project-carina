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

World::World ()
	: Scene2D(0)
{
	unique_ptr<Rect2DRenderer> rect = make_unique<Rect2DRenderer>(Point(5.0f, 5.0f), Vector(1.0f, 1.0f), Colors::red);
	this->add_child(std::move(rect));

	unique_ptr<Player> player = make_unique<Player>(this, Point(7.0f, 7.0f));
	this->add_child(std::move(player));
}

// ---------------------------------------------------

MyGlib::Graphics::RenderArgs2D World::setup_render_args ()
{
	const Vector ws = renderer->get_normalized_window_size();

	return MyGlib::Graphics::RenderArgs2D {
		.clip_init_norm = Vector(0, 0),
		.clip_end_norm = Vector(ws.x, ws.y),
		.world_init = Vector(0, 0),
		.world_end = Vector(10, 10),
		.force_camera_inside_world = true,
		.world_camera_focus = Vector(5, 5),
		.world_screen_width = 10
		};
}

// ---------------------------------------------------

} // end namespace Game