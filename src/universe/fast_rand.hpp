#pragma once

#include <cstdint>

namespace MRand {
/*
* Based on the Lehmer Random Number Generator (Principle).
*  Xₖ₊₁ = a ⋅ Xₖ mod m
*/
struct FastRand {
	uint64_t seed;
	uint32_t rnd();
	int randInteger(int min, int max);
	double rndDouble(double min, double max);
};

/*
* Takes 2 uint32_t and produces a _unique_ 
* uint64_t hash for the pair.
* Useful for hashing coordinates (x, y) into a single value.
*/
uint64_t CantorHashPairing(uint32_t a, uint32_t b);

} // namespace MRand
