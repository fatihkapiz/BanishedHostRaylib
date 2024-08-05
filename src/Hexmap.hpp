#pragma once
#include "Hex.hpp"
#include "constants/Constants.hpp"
#include "raylib.h"
#include <raymath.h>
#include <vector>

class Hexmap {
private:
  int sizeX;
  int sizeY;
  float hexSize;
  //  std::vector<std::vector<Hex>> grid;
  std::vector<Hex> grid{};

public:
  Hexmap(int _sizeX, int _sizeY, float _hexSize)
      : sizeX(_sizeX), sizeY(_sizeY), hexSize(_hexSize) {
    // grid.resize(sizeY); // Resize the outer vector to sizeY
    int offset = 160;

    /* Cartesian initialization of hexes
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
  */
    // axial init of hexes
    for (int i = -4; i <= 4; i++) {
      for (int j = -4; j <= 4; j++) {
        grid.push_back(Hex(i, j, hexSize, FLATLAND));
      }
    }
  }

  void update() {}
  void render() {
    /*
    for (auto i : grid) {
      for (auto tile : i) {
        tile.render();
      }
    }
    */
    for (auto tile : grid) {
      tile.render();
    }
  }
};
