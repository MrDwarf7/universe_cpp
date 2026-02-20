#pragma once

#include <optional>

#include "colors.hpp"
#include "fast_rand.hpp"
#include "imgui.h"
#include "model.hpp"
#include "raylib.h"

namespace MUI {

// typedef int Pixels;
using Pixels = float;

struct Point {
	float x, y;
};

class Mui {
public:
	void update();
	void show_ui();
	void draw();

private:
	// Pixel pixel{};
	Pixels sector_size{32}; // ideally we would have a 'type' alias (properly) for this
	MRand::FastRand frand{};
	MRand::FastRand star_system_rand{};
	Point cam_pos{0, 0};
	Point mouse_pos{0, 0};
	std::optional<GameModel::StarSystem> hovered_star{std::nullopt};
	Color star_to_color(GameModel::StarColor star_color);
};

Color to_ray_color(MColors::Color col);
ImVec4 to_imvec4(const MColors::Color c);

} // namespace MUI
