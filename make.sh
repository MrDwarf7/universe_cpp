#!/bin/env bash

# Get the project name from the parent folder's name
PROJECT_NAME=$(basename "$(dirname "$(realpath "$0")")")
BUILD_DIR_G=build
BE_QUIET=false

# cmake --build ./${BUILD_DIR} && "./${BUILD_DIR}/${PROJECT_NAME}"

function build() {
  local build_dir=${1:-${BUILD_DIR_G}}

  if [[ "$BE_QUIET" == true ]]; then
    cmake -S . -B "${build_dir}" >/dev/null 2>&1 &&
      cmake --build "./${build_dir}" >/dev/null 2>&1
  else
    cmake -S . -B "${build_dir}" && cmake --build "./${build_dir}"
  fi
  # --parallel -j 99
}

function build_release() {
  local build_dir=${1:-${BUILD_DIR_G}}
  if [[ "$BE_QUIET" == true ]]; then
    cmake -S . -B "${build_dir}" -DCMAKE_BUILD_TYPE=Release >/dev/null 2>&1 &&
      cmake --build "./${build_dir}" --config Release >/dev/null 2>&1
  else
    cmake -S . -B "${build_dir}" -DCMAKE_BUILD_TYPE=Release &&
      cmake --build "./${build_dir}" --config Release
  fi

  #--parallel -j 99
}

function main() {
  local mode=${1:-build}
  # declare build_dir="${BUILD_DIR_G}"

  printf "BUILD_DIR_G (global variable): %s\n" "${BUILD_DIR_G}"

  if [[ "$mode" == "build" ]]; then
    build "${BUILD_DIR_G}"
  elif [[ "$mode" == "release" ]]; then
    # if release, we should use 'cmake-build-release' as the build directory to avoid conflicts with the debug build
    BUILD_DIR_G="${BUILD_DIR_G}-release"
    printf "Using release build directory: %s\n" "${BUILD_DIR_G}"
    build_release "$BUILD_DIR_G"
  elif [[ "$mode" == "clean" ]]; then
    rm -rf "${BUILD_DIR_G}" "${BUILD_DIR_G}-release"
    rm -rf "deps"
  elif [[ "$mode" == "run" ]]; then
    # build then run the executable
    build "${BUILD_DIR_G}"
    printf "Running the executable: %s\n" "${PROJECT_NAME}"
    ./"${BUILD_DIR_G}/${PROJECT_NAME}"
  else
    echo "Unknown mode: $mode"
    echo "Usage: $0 [build|release|clean|run]"
    exit 1
  fi
  return 0
}

main "$@"
