#include "colors.hpp"
#include "constants.hpp"
#include "imgui.h"
#include "mui.hpp"
#include "raylib.h"
#include "rlImGui.h"

#define USE_DARKTHEME true

/*
* Initial Setup for RayLib
* Mostly flags and such for the window and rendering.
*/
void init_raylib() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(DEF_SCREEN_WIDTH, DEF_SCREEN_HEIGHT, APP_NAME);
	SetTargetFPS(TARGET_FPS);
	SetWindowFocused();
}

/*
* Call setup options for imgui such as theming, scaling, and other misc options.
*/
void init_imgui() {
	rlImGuiSetup(USE_DARKTHEME);

	// Scaling & handling etc.
	ImGuiStyle &style               = ImGui::GetStyle();
	style.Colors[ImGuiCol_WindowBg] = MUI::to_imvec4(MColors::Kanagawa::Crust);
	style.Colors[ImGuiCol_Text]     = MUI::to_imvec4(MColors::Kanagawa::Cornsilk);
	style.Colors[ImGuiCol_FrameBg]  = MUI::to_imvec4(MColors::Kanagawa::GreenYellow);

	// TODO: Move to constants / config file
	style.WindowRounding            = 8.0f;
	style.FrameRounding             = 4.0f;
	style.WindowPadding             = {12, 12};
	style.FramePadding              = {6, 6};
	style.CellPadding               = {4, 4};

	style.FontSizeBase              = 22.0f;

	return;
}

/*
* Sets up both RayLib and ImGui in one call.
*/
void init_all() {
	init_raylib();
	init_imgui();
}

void start_per_loop(
	bool &should_quit
) {
	if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_Q)) {
		should_quit = true;
	}

	BeginDrawing();
	rlImGuiBegin();
	ClearBackground(MUI::to_ray_color(MColors::Kanagawa::Crust));
}

/*
* Returns `true` if the window should close, either by the user clicking the 'X' or
*/
bool end_per_loop(
	bool &should_quit
) {
	rlImGuiEnd();
	EndDrawing();

	// We don't _have_ to check on bottom of loop, but generally it
	// feels a bit more responsive
	if (WindowShouldClose() || should_quit == true) {
		return true;
	}
	return false;
}

int main(
	int argc, char* argv[]
) {
	init_all();

	MUI::Mui ui{};

	// Main logic and stuff
	bool should_quit{false};

	while (!should_quit) {
		start_per_loop(should_quit);

		ui.update();
		ui.show_ui();
		ui.draw();

		if (end_per_loop(should_quit)) {
			break;
		}
	}

	rlImGuiShutdown();
	CloseWindow();

	return 0;
}
