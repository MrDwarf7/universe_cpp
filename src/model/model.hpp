#pragma once

namespace GameModel {

enum StarColor { White, Blue, Red, GreenYellow, Yellow, Orange, Gold, Purple };

const StarColor STAR_COLORS[8] = {White, Blue, Red, GreenYellow, Yellow, Orange, Gold, Purple};

struct StarSystem {
	double radius;       // 'Solar Radi' ( 2000, 1 )
	StarColor color;     // Color (based on surface_temp)
	double luminosity;   // 'Solar Lum' ( 25, 1 )
	double surface_temp; // 'Solar Masses' ( 10000, 1 ) (based on mass)
	double mass;         // 'Kelvin' ( 210000, 1000 )

	/*
   * Transforms the index of the star color enum into a human readable string.
   */
	const char* color_name() const noexcept;
};

} // namespace GameModel
