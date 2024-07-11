#pragma once

// Standard Headers
#include <string>

// External Headers
#include <raylib.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Player/Player.h"
#include "Systems/AnimationSystem/AnimationSystem.h"
#include "Systems/MovementSystem/MovementSystem.h"

class Game
{
private:
    Game();

public:
    ~Game();
    static Game &getInstance();
    void run();

private:
    void update(float deltaTime);
    void draw();

private:
    Vector2 m_size = {1280, 720};
    std::string m_title = "Game";

    std::shared_ptr<entt::registry> m_registry;
    AnimationSystem m_animationSystem;
    MovementSystem m_movementSystem;
    std::shared_ptr<Player> m_player;
};