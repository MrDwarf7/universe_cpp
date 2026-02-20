#include "mui.hpp"

#include <cstdio>
#include <exception>

#include "colors.hpp"
#include "fast_rand.hpp"
#include "generator.hpp"
#include "imgui.h"
#include "model.hpp"
#include "raylib.h"

/*
*
* Inverse of density.
* The lower bound is almost always going to be 0,
* because we want to allow for the possibility of having a lot of circles.
*
*/
#define DENSITY_LOWER_BOUND 0
/*
*
* Inverse of density.
* Higher value means less circles.
*
*/
#define DENSITY_UPPER_BOUND 20

#define KEY_CAM_SENS_MULT 4.0f

#define KEY_CAM_SENS_DAMPING 0.6f

/*
* Higher value means smaller circles.
*/
#define RADIUS_INVERSE_SCALE 2100.0f

void MUI::Mui::update() {
	this->mouse_pos = Point{
	  static_cast<float>(static_cast<float>(GetMouseX()) / this->sector_size + this->cam_pos.x),
	  static_cast<float>(static_cast<float>(GetMouseY()) / this->sector_size + this->cam_pos.y),
	};

	// TODO: [dedup]
	this->frand.seed = MRand::CantorHashPairing(this->mouse_pos.x, this->mouse_pos.y);

	// HACK: [dedup] : This is identical to the code in draw() )
	if (this->frand.randInteger(DENSITY_LOWER_BOUND, DENSITY_UPPER_BOUND) == 1) {
		this->hovered_star = Generator::GenerateStar(this->mouse_pos.x, this->mouse_pos.y, this->star_system_rand);
	} else {
		this->hovered_star = std::nullopt;
	}

	const float KEY_CAM_SENS =
		this->sector_size * KEY_CAM_SENS_MULT * (GetFrameTime() * static_cast<float>(KEY_CAM_SENS_DAMPING));

	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
		this->cam_pos.y -= KEY_CAM_SENS;
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
		this->cam_pos.y += KEY_CAM_SENS;
	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
		this->cam_pos.x -= KEY_CAM_SENS;
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
		this->cam_pos.x += KEY_CAM_SENS;
	}
};

void MUI::Mui::show_ui() {
	if (this->hovered_star.has_value()) {
		//                                                            This is a sort of 'offset' so it looks like a tooltip style ui
		ImGui::SetNextWindowPos(ImGui::GetMousePos(), ImGuiCond_Always, ImVec2(0.0f, 1.0f));

		if (ImGui::Begin(
				"hovered",
				nullptr,
				ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize
			)) {
			ImGui::Text("Sector: X(%f) : Y(%f)", this->mouse_pos.x, this->mouse_pos.y);
			ImGui::Text("Sector Seed: %lu", this->star_system_rand.seed);
			ImGui::Text("Color: %s", this->hovered_star->color_name());
			ImGui::Text("Radius: %f", this->hovered_star->radius);
			ImGui::Text("Mass: %f", this->hovered_star->mass);
			ImGui::Text("Surface Temp: %f", this->hovered_star->surface_temp);
		}

		ImGui::End();
	}
};

void MUI::Mui::draw() {
	int num_sectors_x = GetScreenWidth() / this->sector_size;
	int num_sectors_y = GetScreenHeight() / this->sector_size;
	float radius      = this->sector_size / 2.0f;

	auto line_color   = to_ray_color(MColors::Kanagawa::Cornsilk);
	auto circle_color = to_ray_color(MColors::Kanagawa::SlateBlue);

	for (size_t x = 0; x < num_sectors_x; x++) {
		for (size_t y = 0; y < num_sectors_y; y++) {
			Point global_sector = Point{
			  static_cast<float>(this->cam_pos.x + x),
			  static_cast<float>(this->cam_pos.y + y),
			};

			// TODO: [dedup] : There's likely a way we can not have to hash=>seed in both update() and draw()
			this->frand.seed = MRand::CantorHashPairing(global_sector.x, global_sector.y);

			if (this->frand.randInteger(DENSITY_LOWER_BOUND, DENSITY_UPPER_BOUND) == 1) {
				GameModel::StarSystem star;
				try {
					star = Generator::GenerateStar(global_sector.x, global_sector.y, this->star_system_rand);
				} catch (const std::exception &e) {
					printf(
						"Error generating star at sector (%f, %f): %s\n", global_sector.x, global_sector.y, e.what()
					);
					throw e;
				};

				DrawCircle(
					((x * sector_size) + radius),
					((y * sector_size) + radius),
					(star.radius / RADIUS_INVERSE_SCALE) * radius,
					this->star_to_color(star.color)
				);
			}
		}
	}
};

Color MUI::Mui::star_to_color(
	GameModel::StarColor star_color
) {
	switch (star_color) {
		case GameModel::StarColor::White      : return MUI::to_ray_color(MColors::Kanagawa::Crust);
		case GameModel::StarColor::Blue       : return MUI::to_ray_color(MColors::Kanagawa::SlateBlue);
		case GameModel::StarColor::Red        : return MUI::to_ray_color(MColors::Kanagawa::Red);
		case GameModel::StarColor::GreenYellow: return MUI::to_ray_color(MColors::Kanagawa::GreenYellow);
		case GameModel::StarColor::Yellow     : return MUI::to_ray_color(MColors::Kanagawa::Orange);
		case GameModel::StarColor::Orange     : return MUI::to_ray_color(MColors::Kanagawa::Orange);
		case GameModel::StarColor::Gold       : return MUI::to_ray_color(MColors::Kanagawa::BurlyWood);
		case GameModel::StarColor::Purple     : return MUI::to_ray_color(MColors::Kanagawa::PurpGrey);
	}
	return MUI::to_ray_color(MColors::Kanagawa::Crust);
}

Color MUI::to_ray_color(
	MColors::Color col
) {
	return Color{col.r, col.g, col.b, col.a};
}

ImVec4 MUI::to_imvec4(
	const MColors::Color c
) {
	return ImVec4(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
}
