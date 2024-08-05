#pragma once
#include "raylib.h"
#include <cmath>

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

struct Orientation {
  const float f0, f1, f2, f3;
  const float b0, b1, b2, b3;
  const float start_angle; // in multiples of 60°
  Orientation(float f0_, float f1_, float f2_, float f3_, float b0_, float b1_,
              float b2_, float b3_, float start_angle_)
      : f0(f0_), f1(f1_), f2(f2_), f3(f3_), b0(b0_), b1(b1_), b2(b2_), b3(b3_),
        start_angle(start_angle_) {}
};

const Orientation layout_pointy =
    Orientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0, sqrt(3.0) / 3.0,
                -1.0 / 3.0, 0.0, 2.0 / 3.0, 0.5);
const Orientation layout_flat =
    Orientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0), 2.0 / 3.0, 0.0,
                -1.0 / 3.0, sqrt(3.0) / 3.0, 0.0);

struct Layout {
  const Orientation orientation;
  const Vector2 size;
  const Vector2 origin;
  Layout(Orientation orientation_, Vector2 size_, Vector2 origin_)
      : orientation(orientation_), size(size_), origin(origin_) {}
};

Vector2 hex_to_pixel(Layout layout, Axial h) {
  const Orientation &M = layout.orientation;
  float x = (M.f0 * h.q + M.f1 * h.r) * layout.size.x;
  float y = (M.f2 * h.q + M.f3 * h.r) * layout.size.y;
  return Vector2{x + layout.origin.x, y + layout.origin.y};
}

struct FractionalHex {
  const float q, r, s;
  FractionalHex(float q_, float r_, float s_) : q(q_), r(r_), s(s_) {}
};

Axial hex_round(FractionalHex h) {
  int q = int(round(h.q));
  int r = int(round(h.r));
  int s = int(round(h.s));
  float q_diff = abs(q - h.q);
  float r_diff = abs(r - h.r);
  float s_diff = abs(s - h.s);
  if (q_diff > r_diff and q_diff > s_diff) {
    q = -r - s;
  } else if (r_diff > s_diff) {
    r = -q - s;
  } else {
    s = -q - r;
  }
  return Axial{q, r, s};
}

FractionalHex pixel_to_hex(Layout layout, Vector2 p) {
  const Orientation &M = layout.orientation;
  Vector2 pt = Vector2{(p.x - layout.origin.x) / layout.size.x,
                       (p.y - layout.origin.y) / layout.size.y};
  float q = M.b0 * pt.x + M.b1 * pt.y;
  float r = M.b2 * pt.x + M.b3 * pt.y;
  return FractionalHex(q, r, -q - r);
}
