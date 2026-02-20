# Universe

A procedurally generated infinite star field explorer built in C++26 using RayLib and ImGui.

## Overview

Universe is a deterministic procedural universe simulator that generates star systems on-the-fly as you navigate through space.
Each coordinate in the infinite grid produces consistent results—the same location always generates the same stars.

The project uses a **Lehmer Random Number Generator** combined with **Szudzik's pairing function** to hash coordinate pairs (x, y) into a single seed.
This approach allows for truly infinite procedural generation without any memory overhead—stars are generated lazily as you explore,
and the same location always yields identical results.

## Features

- **Infinite Exploration**: Navigate an unbounded procedurally generated star field
- **Deterministic Generation**: Same coordinates always produce identical star systems (useful for seeding/sharing locations)
- **Star Properties**: Each star has radius, color, luminosity, mass, and surface temperature
- **Interactive UI**: Hover over stars to view detailed information in a tooltip
- **Kanagawa Theme**: Beautiful color palette inspired by the Kanagawa VS Code theme

## Controls

| Key         | Action     |
| ----------- | ---------- |
| `W` / `↑`   | Move up    |
| `S` / `↓`   | Move down  |
| `A` / `←`   | Move left  |
| `D` / `→`   | Move right |
| `Q` / `Esc` | Quit       |

## Building

```bash
# Debug build (default)
./make.sh

# Release build
./make.sh release

# Run debug build
./make.sh run

# Run release build
chmod +x ./build-release/universe_cpp && ./build-release/universe_cpp
```

### Vendored Dependencies

This project includes pre-compiled versions of RayLib and ImGui in the `vendored/` directory. If you encounter issues or want to use your own build:

- **RayLib**: A pre-compiled `libraylib.a` is included in `vendored/raylib/`. You can replace this with your own compiled copy of RayLib if needed.
- **ImGui**: Source files are included directly in `vendored/imgui/`.

## Architecture

```
src/
├── main.cpp          # Entry point, RayLib/ImGui initialization
├── constants.hpp     # Window size, FPS, app name
├── colors.hpp        # Kanagawa color palette (& TokyoNight WIP)
├── model/
│   ├── model.hpp     # StarSystem data structure
│   └── model.cpp     # Star color name mapping
├── universe/
│   ├── generator.hpp/cpp  # Procedural star generation
│   └── fast_rand.hpp/cpp  # Lehmer RNG + Szudzik pairing hash
└── mui/
    ├── mui.hpp       # Main UI/rendering class
    └── mui.cpp       # Camera, input handling, star rendering
```
