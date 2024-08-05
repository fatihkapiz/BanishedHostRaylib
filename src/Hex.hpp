#pragma once
#include "constants/Constants.hpp"
#include "raylib.h"
#include <cmath>
#include <string>

enum Terrain { FLATLAND, WOODS, ROUGH_TERRAIN };

struct Axial {
  int q, r, s;

  Axial(int q, int r, int s) : q(q), r(r), s(s) {}
  Axial(int q, int r) : q(q), r(r), s(-q - r) {}

  bool operator==(const Axial &other) const {
    return q == other.q && r == other.r && s == other.s;
  }

  Axial operator+(const Axial &other) const {
    return Axial(q + other.q, r + other.r, s + other.s);
  }

  Axial operator-(const Axial &other) const {
    return Axial(q - other.q, r - other.r, s + other.s);
  }

  Axial operator*(int k) const { return Axial(q * k, r * k, s * k); }
};

struct Hex {
  Axial axial;
  Terrain terrain;
  float size;
  Vector2 center;

  Hex(int q, int r, float size, Terrain terrain)
      : axial(q, r), terrain(terrain), size(size),
        center(axialToCartesian(q, r, size)) {}

  Hex(float x, float y, float size, Terrain terrain)
      : axial(cartesianToAxial(x, y, size)), center(Vector2{x, y}), size(size),
        terrain(terrain) {}

  const std::vector<Axial> &hex_directions() {
    static const std::vector<Axial> directions = {
        Axial(1, 0, -1), Axial(1, -1, 0), Axial(0, -1, 1),
        Axial(-1, 0, 1), Axial(-1, 1, 0), Axial(0, 1, -1)};
    return directions;
  }

  int AxialDistance(Axial &a, Axial &b) {
    return (abs(a.q - b.q) + abs(a.r - b.r) + abs(a.s - b.s)) / 2;
  }

  Vector2 axialToCartesian(int q, int r, float size) const {
    float x = size * sqrt(3) * (q + r / 2.0) +
              static_cast<int>(Constants::windowWidth / 2);
    float y = size * 3 / 2 * r + static_cast<int>(Constants::windowHeight / 2);
    return Vector2{x, y};
  }

  Axial cartesianToAxial(float x, float y, float size) const {
    float q = (sqrt(3) / 3 * x - 1.0 / 3 * y) / size;
    float r = (2.0 / 3 * y) / size;
    return axialRound(q, r);
  }

  Axial cartesianToAxial() const {
    float q = (sqrt(3) / 3 * center.x - 1.0 / 3 * center.y) / size;
    float r = (2.0 / 3 * center.y) / size;
    return axialRound(q, r);
  }

  Axial axialRound(float q, float r) const {
    float s = -q - r;
    int rq = round(q);
    int rr = round(r);
    int rs = round(s);

    float q_diff = fabs(rq - q);
    float r_diff = fabs(rr - r);
    float s_diff = fabs(rs - s);

    if (q_diff > r_diff && q_diff > s_diff) {
      rq = -rr - rs;
    } else if (r_diff > s_diff) {
      rr = -rq - rs;
    } else {
      rs = -rq - rr;
    }

    return Axial{rq, rr, rs};
  }

  Vector2 DrawHexagonCorner(Vector2 center, float size, int i) {
    float angleDeg = 60 * i - 30;
    float angleRad = PI / 180 * angleDeg;
    return Vector2{center.x + size * cosf(angleRad),
                   center.y + size * sinf(angleRad)};
  }

  void DrawHexagon(Vector2 center, float size) {
    for (int i = 0; i < 6; i++) {
      DrawLineV(DrawHexagonCorner(center, size, i),
                DrawHexagonCorner(center, size, i + 1), BLACK);
    }
  }

  void DrawAxialPoints() {
    Axial qr = cartesianToAxial();
    std::string str = "q: " + std::to_string(qr.q) +
                      " r: " + std::to_string(qr.r) +
                      " s: " + std::to_string(qr.s);
    DrawText(str.c_str(), center.x, center.y, 10, BLACK);
  }

  void DrawAxialPointsSelf() {
    std::string str = "q: " + std::to_string(this->axial.q) +
                      " r: " + std::to_string(this->axial.r) +
                      " s: " + std::to_string(this->axial.s);
    DrawText(str.c_str(), center.x - size, center.y, 8, BLACK);
  }

  void update() {}

  void render() { // DrawHexagon(center, size);
    DrawPoly(center, 6, size, 30, GREEN);
    DrawPolyLines(center, 6, size, 30, BLACK);
    DrawAxialPointsSelf();
  }
};
