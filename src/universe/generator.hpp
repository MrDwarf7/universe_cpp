#pragma once

#include <cstdint>

#include "fast_rand.hpp"
#include "model.hpp"

namespace Generator {

GameModel::StarSystem GenerateStar(uint32_t x, uint32_t y, MRand::FastRand &rnd);

} // namespace Generator
