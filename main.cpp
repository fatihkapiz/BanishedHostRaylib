#include "raylib.h"
#include "src/Scenes/CombatScene.hpp"
#include "src/Scenes/GameScene.hpp"
#include "src/Scenes/MenuScene.hpp"
#include <memory>

int screenWidth = 1200;
int screenHeight = 800;

int main(void) {
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  Camera2D camera = {0};
  camera.target = (Vector2){0, 0};
  camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
  BeginMode2D(camera);

  SetTargetFPS(60);

  GameData gamedata;

  Scene *scene;
  std::unique_ptr<MenuScene> menuScene = std::make_unique<MenuScene>();
  std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>(gamedata);
  std::unique_ptr<CombatScene> combatScene =
      std::make_unique<CombatScene>(gamedata);

  scene = combatScene.get();
  Scene::screen = COMBAT;

  float log = 10000;

  while (!WindowShouldClose()) {
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

  EndMode2D();
  CloseWindow();

  return 0;
}
