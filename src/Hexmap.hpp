#pragma once
#include "Hex.hpp"
#include "HexLayout.hpp"
#include "constants/Constants.hpp"
#include "raylib.h"
#include <raymath.h>
#include <vector>

Layout defaultLayout(layout_pointy, Vector2{10.0f, 10.0f}, Vector2{0.0f, 0.0f});

class Hexmap {
private:
  int sizeX;
  int sizeY;
  int radius;
  //  std::vector<std::vector<Hex>> grid;
  float hexSize;
  Layout layout;
  std::vector<Hex> grid{};

public:
  /*
  Hexmap(int _sizeX, int _sizeY, float _hexSize)
      : sizeX(_sizeX), sizeY(_sizeY), hexSize(_hexSize),
        layout(defeaultLayout) {
    int offset = 160;
    for (int i = 0; i < sizeY; i++) {
      for (int j = 0; j < sizeX; j++) {
        float x = offset + j * std::sqrt(3) * hexSize;
        float y = i * 3 / 2 * hexSize;
        if (i % 2 == 0) {
          x += std::sqrt(3) / 2 * hexSize;
        } else {
          y += hexSize / 2;
        }
        grid.push_back(Hex(x, y, hexSize, FLATLAND));
      }
    }
    */

  // axial init of hexes
  /*
  for (int i = -4; i <= 4; i++) {
    for (int j = -4; j <= 4; j++) {
      grid.push_back(Hex(i, j, hexSize, FLATLAND));
    }
  }
}
*/

  // Hexagonal shaped hexmap
  Hexmap(int radius, float hexSize)
      : radius(radius), hexSize(hexSize),
        layout(layout_pointy, Vector2{hexSize, hexSize}, Vector2{0.0f, 0.0f}) {

    for (int i = -radius; i <= radius; i++) {
      for (int j = std::max(-radius, -i - radius);
           j <= std::min(radius, -i + radius); j++) {
        grid.push_back(Hex(i, j, hexSize, FLATLAND, layout));
      }
    }
  }

  Hex *getHex(Axial pos) {
    for (auto &hex : grid) {
      if (hex.axial == pos) {
        return &hex;
      }
    }
    return nullptr;
  }

  void update() {}
  void render() { /*
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
