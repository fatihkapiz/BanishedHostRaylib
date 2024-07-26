#pragma once

typedef enum Screen { MENU, PLAY } Screen;

class Scene {
public:
  static Screen screen;
  virtual ~Scene() = default;
  virtual bool handleInput() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
};

inline Screen Scene::screen = MENU;
