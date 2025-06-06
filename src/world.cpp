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

World::World ()
	: Scene2D(0)
{
	auto rect = make_unique<Rect2DRenderer>(Vector(1.0f, 1.0f), Colors::red);
	rect->set_translation(5.0f, 5.0f);
	rect->set_angular_velocity(Mylib::Math::degrees_to_radians(30.0f));
	this->add_child(std::move(rect));

	auto tile_map = make_unique<TileMap>(0, 3, 3, Vector(1, 1));
	tile_map->set(0, 0, Texture::tree_00);
	tile_map->set(0, 1, Texture::tree_00);
	tile_map->set(1, 0, Texture::tree_00);
	tile_map->set(1, 1, Texture::tree_00);
	this->add_child(std::move(tile_map));

	auto player = make_unique<Player>(this, Point(0.0f, 0.0f));
	this->add_child(std::move(player));
}

// ---------------------------------------------------

MyGlib::Graphics::RenderArgs2D World::setup_render_args ()
{
	const Vector ws = renderer->get_normalized_window_size();

	return MyGlib::Graphics::RenderArgs2D {
		.clip_init_norm = Vector(0, 0),
		.clip_end_norm = Vector(ws.x, ws.y),
		.world_init = Vector(-10, -10),
		.world_end = Vector(10, 10),
		.force_camera_inside_world = true,
		.world_camera_focus = Vector(0, 0),
		.world_screen_width = 40,
		.invert_y_axis = false
		};
}

// ---------------------------------------------------

} // end namespace Game