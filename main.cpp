#include "raylib.h"
#include "src/Scenes/GameScene.hpp"
#include "src/Scenes/MenuScene.hpp"
#include <memory>

int main(void) {
  InitWindow(800, 450, "raylib [core] example - basic window");

  Scene *scene;
  std::unique_ptr<MenuScene> menuScene = std::make_unique<MenuScene>();
  std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();
  scene = menuScene.get();

  while (!WindowShouldClose()) {
    // update here
    if (scene->screen == PLAY && scene == menuScene.get()) {
      scene = gameScene.get();
    } else if (scene->screen == MENU && scene == gameScene.get()) {
      scene = menuScene.get();
    }
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
