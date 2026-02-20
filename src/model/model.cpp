#include "model.hpp"

const char* GameModel::StarSystem::StarSystem::color_name() const noexcept {
	switch (this->color) {
		case White      : return "White";
		case Blue       : return "Blue";
		case Red        : return "Red";
		case GreenYellow: return "Green-Yellow";
		case Yellow     : return "Yellow";
		case Orange     : return "Orange";
		case Gold       : return "Gold";
		case Purple     : return "Purple";
	}
	return "Unknown";
}
