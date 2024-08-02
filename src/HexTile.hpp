#pragma once
#include "array"
#include "raylib.h"
#include <raymath.h>
#include <vector>

enum Terrain { FLATLAND, WOODS, ROUGH_TERRAIN };

struct Hex {
  int q, r, s;
  Terrain terrain;
  float size;
  Vector2 center;

  Hex(int q, int r) : q(q), r(r), s(-q - r), terrain(FLATLAND) {}
  Hex(float x, float y, float size, Terrain _terrain)
      : center(Vector2{x, y}), size(size), terrain(_terrain) {}

  void update() {}
  void render() {
    DrawPoly(center, 6, size, 90, GREEN);
    DrawPolyLines(center, 6, size, 90, BLACK);
  }
};

class Hexmap {
private:
  int sizeX = 8;
  int sizeY = 8;
  float hexSize = 10;
  std::vector<std::vector<Hex>> grid;

public:
  Hexmap(int _sizeX, int _sizeY, float _hexSize)
      : sizeX(_sizeX), sizeY(_sizeY), hexSize(_hexSize) {
    grid.resize(sizeY); // Resize the outer vector to sizeY
    for (int i = 0; i < sizeY; i++) {
      for (int j = 0; j < sizeX; j++) {
        float x = j * std::sqrt(3) * hexSize;
        float y = i * 3 / 2 * hexSize;
        if (i % 2 == 0) {
          grid[i].push_back(
              Hex(x + std::sqrt(3) / 2 * hexSize, y, hexSize, FLATLAND));
        } else {
          grid[i].push_back(Hex(x, y, hexSize, FLATLAND));
        }
      }
    }
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
