#pragma once

// Standard Headers
#include <string>

// External Headers
#include <raylib.h>
#include <entt/entt.hpp>
#include <spdlog/spdlog.h>

// Internal Headers
#include "Player/Player.h"
#include "Backend/Systems/AnimationSystem/AnimationSystem.h"
#include "Backend/Systems/MovementSystem/MovementSystem.h"
#include "Backend/Systems/CameraSystem/CameraSystem.h"

class Game
{
private:
    Game();

public:
    ~Game();
    static Game &getInstance();
    void Run();

private:
    void Update(float deltaTime);
    void Draw();

private:
    Vector2 m_size = {1280, 720};
    std::string m_title = "Game";

    std::shared_ptr<entt::registry> m_registry;
    AnimationSystem m_animationSystem;
    MovementSystem m_movementSystem;
    CameraSystem m_cameraSystem;
    std::shared_ptr<Player> m_player;

    Camera2D *m_camera = nullptr;
};