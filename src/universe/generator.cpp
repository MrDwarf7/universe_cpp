#include "generator.hpp"

#include <stdexcept>

#include "fast_rand.hpp"
#include "model.hpp"

GameModel::StarSystem Generator::GenerateStar(
	uint32_t x, uint32_t y, MRand::FastRand &rnd
) {
	rnd.seed = MRand::CantorHashPairing(x, y);

	if (sizeof(GameModel::STAR_COLORS[0]) == 0 || sizeof(GameModel::STAR_COLORS) == 0) {
		throw std::runtime_error("STAR_COLORS array is empty");
	}

	std::size_t num_colors = sizeof(GameModel::STAR_COLORS) / sizeof(GameModel::STAR_COLORS[0]);
	if (num_colors == 0) {
		// Handle the case where there are no colors available
		throw std::runtime_error("No star colors available");
	}

	return GameModel::StarSystem{
	  rnd.rndDouble(1, 2000),
	  GameModel::STAR_COLORS[rnd.randInteger(0, num_colors)],
	  rnd.rndDouble(1, 25),
	  rnd.rndDouble(1000, 21000),
	  rnd.rndDouble(1, 1000),
	};
}
