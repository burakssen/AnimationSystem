#include "Game.h"

Game::Game()
    : m_registry(std::make_shared<entt::registry>()),
      m_animationSystem(*m_registry),
      m_movementSystem(*m_registry)
{
    InitWindow(this->m_size.x, this->m_size.y, this->m_title.c_str());
    SetTargetFPS(60);
    this->m_player = std::make_shared<Player>(*m_registry);
}

Game::~Game()
{
    CloseWindow();
}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        this->update(deltaTime);
        this->draw();
    }
}

void Game::update(float deltaTime)
{
    this->m_animationSystem.update(deltaTime);
    this->m_movementSystem.update(deltaTime);
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->m_animationSystem.draw();
    EndDrawing();
}
