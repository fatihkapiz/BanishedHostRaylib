#pragma once
#include "Hex.hpp"
#include "raylib.h"
#include <raymath.h>
#include <vector>

class Hexmap {
private:
  int sizeX;
  int sizeY;
  float hexSize;
  std::vector<std::vector<Hex>> grid;

public:
  Hexmap(int _sizeX, int _sizeY, float _hexSize)
      : sizeX(_sizeX), sizeY(_sizeY), hexSize(_hexSize) {
    grid.resize(sizeY); // Resize the outer vector to sizeY
    int offset = 160;

    for (int i = 1; i <= sizeY; i++) {
      for (int j = 1; j < sizeX; j++) {
        float x = offset + j * std::sqrt(3) * hexSize;
        float y = i * 3 / 2 * hexSize;
        if (i % 2 == 0) {
          grid[i - 1].push_back(
              Hex(x + std::sqrt(3) / 2 * hexSize, y, hexSize, FLATLAND));
        } else {
          grid[i - 1].push_back(Hex(x, y + hexSize / 2, hexSize, FLATLAND));
        }
      }
    }
  }

  Vector3 cube_subtract(Hex a, Hex b) {
    int q = a.q - b.q;
    int r = a.r - b.r;
    int s = a.s - b.s;
    return Vector3{(float)q, (float)r, (float)s};
  }

  Vector3 cube_distance(Hex a, Hex b) {
    Vector3 vec = cube_subtract(a, b);
    return Vector3{(abs(vec.x) + abs(vec.y) + abs(vec.z)) / 2};
    // or: (abs(a.q - b.q) + abs(a.r - b.r) + abs(a.s - b.s)) / 2
  }

  void update() {}
  void render() {
    for (auto i : grid) {
      for (auto tile : i) {
        tile.render();
      }
    }
  }
};
