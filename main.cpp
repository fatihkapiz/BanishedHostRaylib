#include "raylib.h"
#include "src/Scenes/GameScene.hpp"
#include "src/Scenes/MenuScene.hpp"
#include <memory>

int main(void) {
  InitWindow(800, 450, "raylib [core] example - basic window");
  SetTargetFPS(60);

  Scene *scene;
  std::unique_ptr<MenuScene> menuScene = std::make_unique<MenuScene>();
  std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();
  scene = menuScene.get();

  float log = 10000;

  while (!WindowShouldClose()) {
    std::cout << "Running" << std::endl;
    log -= 16;
    if (log < 0) {
      std::cout << Scene::screen << std::endl;
      log += 10000;
    }

    // handle input here
    if (scene->screen == PLAY && scene == menuScene.get()) {
      std::cout << "Play clicked" << std::endl;
      scene = gameScene.get();
      std::cout << "Game scene runnin" << std::endl;
    } else if (scene->screen == MENU && scene == gameScene.get()) {
      scene = menuScene.get();
    }
    scene->handleInput();

    // update here
    scene->update();

    // render here
    BeginDrawing();
    ClearBackground(RAYWHITE);

    scene->render();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
