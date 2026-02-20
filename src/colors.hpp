#pragma once

#include <cstdint>

namespace MColors {

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a = 255;
};

// Kanagawa palette

namespace Kanagawa {

	const Color Crust        = Color{22, 22, 29};
	const Color Base         = Color{30, 31, 40};
	const Color Midblue      = Color{43, 42, 56};
	const Color Midblue2     = Color{53, 54, 71};
	const Color Midblue3     = Color{84, 84, 109};
	const Color Cornsilk     = Color{221, 215, 186};
	const Color Slayteagrass = Color{114, 113, 104};
	const Color Navy         = Color{35, 50, 73};

	const Color Teal         = Color{44, 79, 103};
	const Color PurpGrey     = Color{148, 138, 169};
	const Color Purp         = Color{149, 127, 184};
	const Color LightBlue    = Color{126, 156, 215};
	const Color Teal2        = Color{122, 168, 160};
	const Color RosyPink     = Color{210, 126, 153};
	const Color Red          = Color{232, 35, 35};
	const Color SkyBlue      = Color{127, 180, 203};
	const Color GreenYellow  = Color{151, 187, 108};

	const Color VioletRed    = Color{227, 104, 118};
	const Color Orange       = Color{255, 160, 102};
	const Color CadetGreen   = Color{107, 149, 137};
	const Color BurlyWood    = Color{230, 195, 132};
	const Color Tan          = Color{192, 163, 110};
	const Color Salmon       = Color{255, 93, 98};
	const Color LightSteel   = Color{156, 170, 201};
	const Color SlateBlue    = Color{101, 132, 147};
} // namespace Kanagawa

// TODO: [colorschemes] : This is a WIP and need to swap them around
// + likely create a lookup
namespace TokyoNight {
	const Color Crust        = Color{22, 24, 38}; // deepest bg ≈ #16161e
	const Color Base         = Color{26, 27, 38}; // main bg      ≈ #1a1b26
	const Color Midblue      = Color{36, 40, 59}; // surfaces / floats ≈ #24283b
	const Color Midblue2     = Color{41, 48, 66}; // cursorline / subtle ≈ #292e42
	const Color Midblue3     = Color{65, 72, 99}; // borders / dim lines ≈ #414868

	const Color Cornsilk     = Color{192, 202, 245}; // main fg text     ≈ #c0caf5
	const Color Slayteagrass = Color{169, 177, 214}; // secondary fg     ≈ #a9b1d6
	const Color Navy         = Color{86, 95, 137};   // comments / dim   ≈ #565f89

	const Color Teal         = Color{122, 162, 247}; // primary blue accent / info ≈ #7aa2f7
	const Color PurpGrey     = Color{187, 154, 247}; // purple / special     ≈ #bb9af7
	const Color Purp         = Color{187, 154, 247}; // ≈ #bb9af7 (purple keywords/specials)
	//variants as well could be: #9d7cd8 or keep close #bb9af7 variant
	const Color LightBlue    = Color{125, 207};      // cyan / types         ≈ #7dcfff
	const Color Teal2        = Color{122, 168, 160}; // muted teal (less used, kept similar)
	const Color RosyPink     = Color{247, 118, 142}; // pinkish red accent   ≈ #f7768e
	const Color Red          = Color{247, 118, 142}; // errors / danger      ≈ #f7768e
	const Color SkyBlue      = Color{122, 162, 247}; // blue links/info      ≈ #7aa2f7 (duplicate ok if needed)
	const Color GreenYellow  = Color{158, 206, 106}; // strings / success    ≈ #9ece6a

	const Color VioletRed    = Color{247, 118, 142}; // strong red/pink      ≈ #f7768e
	const Color Orange       = Color{255, 158, 100}; // warnings / numbers   ≈ #ff9e64
	const Color CadetGreen   = Color{158, 206, 106}; // green variant        ≈ #9ece6a
	const Color BurlyWood    = Color{224, 175, 104}; // yellow/orange params ≈ #e0af68
	const Color Tan          = Color{224, 175, 104}; // muted yellow         ≈ #e0af68
	const Color Salmon       = Color{247, 118, 142}; // salmon red           ≈ #f7768e
	const Color LightSteel   = Color{192, 202, 245}; // light fg variant     ≈ #c0caf5
	const Color SlateBlue    = Color{65, 72, 99};    // slate / mid gray     ≈ #414868

} // namespace TokyoNight

} // namespace MColors
