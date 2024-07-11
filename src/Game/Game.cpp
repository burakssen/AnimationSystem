#include "Game.h"

Game::Game()
    : m_registry(std::make_shared<entt::registry>()),
      m_animationSystem(*m_registry),
      m_movementSystem(*m_registry),
      m_cameraSystem(*m_registry)
{
    // SetTraceLogLevel(LOG_NONE);
    InitWindow(this->m_size.x, this->m_size.y, this->m_title.c_str());
    SetTargetFPS(0);
    this->m_player = std::make_shared<Player>(*m_registry);
    spdlog::info("Game initialized");
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

void Game::Run()
{
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        this->Update(deltaTime);
        this->Draw();
    }
}

void Game::Update(float deltaTime)
{
    this->m_cameraSystem.Update(deltaTime);
    this->m_animationSystem.Update(deltaTime);
    this->m_movementSystem.Update(deltaTime);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->m_camera = this->m_cameraSystem.GetCamera();
    if (this->m_camera)
    {
        BeginMode2D(*this->m_camera);
        this->m_animationSystem.Draw();
        EndMode2D();
    }
    DrawFPS(10, 10);

    EndDrawing();
}
