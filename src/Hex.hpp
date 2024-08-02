#pragma once
#include "raylib.h"
#include <cmath>
#include <string>

enum Terrain { FLATLAND, WOODS, ROUGH_TERRAIN };

struct Hex {
  int q, r, s;
  Terrain terrain;
  float size;
  Vector2 center;

  Hex(int q, int r, float size, Terrain terrain)
      : q(q), r(r), s(-q - r), terrain(terrain), size(size),
        center(axialToCartesian(q, r, size)) {}

  Hex(float x, float y, float size, Terrain terrain)
      : center(Vector2{x, y}), size(size), terrain(terrain) {
    auto axial = cartesianToAxial(x, y, size);
    q = axial.q;
    r = axial.r;
    s = -q - r;
  }

  bool operator==(const Hex &other) const {
    return q == other.q && r == other.r && s == other.s;
  }

  Hex operator+(const Hex &other) const {
    return Hex(q + other.q, r + other.r, size, terrain);
  }

  Hex operator-(const Hex &other) const {
    return Hex(q - other.q, r - other.r, size, terrain);
  }

  Hex operator*(int k) const { return Hex(q * k, r * k, size, terrain); }

  Vector2 axialToCartesian(int q, int r, float size) const {
    float x = size * sqrt(3) * (q + r / 2.0);
    float y = size * 3 / 2 * r;
    return Vector2{x, y};
  }

  struct Axial {
    int q, r;
  };

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

    return Axial{rq, rr};
  }

  Vector2 DrawHexagonCorner(Vector2 center, float size, int i) {
    float angleDeg = 60 * i - 30;
    float angleRad = PI / 180 * angleDeg;
    return Vector2{center.x + size * cos(angleRad),
                   center.y + size * sin(angleRad)};
  }

  void DrawHexagon(Vector2 center, float size) {
    for (int i = 0; i < 6; i++) {
      DrawLineV(DrawHexagonCorner(center, size, i),
                DrawHexagonCorner(center, size, i + 1), BLACK);
    }
  }

  void DrawAxialPoints() {
    Axial qr = cartesianToAxial();
    std::string str =
        "q: " + std::to_string(qr.q) + " r: " + std::to_string(qr.r);
    DrawText(str.c_str(), center.x, center.y, 10, BLACK);
  }

  void update() {}
  void render() { DrawHexagon(center, size); }
};

/*
struct Hex {
  Vector3 axial;
  Terrain terrain;
  float size;
  Vector2 center;

  Hex(int q, int r, int size) : size(size), terrain(FLATLAND) {
    axial.x = q;
    axial.y = r;
    axial.z = -q - r;
  }

  Hex(float x, float y, float size, Terrain _terrain)
      : center(Vector2{x, y}), size(size), terrain(_terrain) {}

  int hex_length(Hex hex) {
    return int((abs(hex.axial.x) + abs(hex.axial.y) + abs(hex.axial.z)) / 2);
  }

  int hex_distance(Hex a, Hex b) { return hex_length(a.axial - b.axial); }

  static Vector2 AxialToCartesian(int q, int r, int size) {
    float x = size * std::sqrt(3) * (q + r / 2.0);
    float y = size * 3 / 2 * q;
    return Vector2{x, y};
  }

  Vector2 DrawHexagonCorner(Vector2 center, float size, int i) {
    float angleDeg = 60 * i - 30;
    float angleRad = PI / 180 * angleDeg;
    return Vector2{center.x + size * std::cos(angleRad),
                   center.y + size * std::sin(angleRad)};
  }

  void DrawHexagon(Vector2 center, float size) {
    for (int i = 0; i < 6; i++) {
      DrawLineV(DrawHexagonCorner(center, size, i),
                DrawHexagonCorner(center, size, i + 1), BLACK);
    }
  }

  void DrawAxialPoints() {
    std::string str = "q: " + std::to_string(q) + " r: " + std::to_string(r);
    DrawText(str.c_str(), AxialToCartesian(q, r, size).x,
             AxialToCartesian(q, r, size).y, 10, BLACK);
  }

  void update() {}
  void render() {
    DrawHexagon(center, size);
    DrawAxialPoints();
    // DrawPoly(center, 6, size, 90, GREEN);
    // DrawPolyLines(center, 6, size, 90, BLACK);
  }
};*/
