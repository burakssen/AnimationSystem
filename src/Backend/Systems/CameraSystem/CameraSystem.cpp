#include "CameraSystem.h"

CameraSystem::CameraSystem(entt::registry &registry) : m_registry(registry)
{
}

void CameraSystem::Update(float deltaTime)
{
    // Update the camera position
    auto view = m_registry.view<CameraComponent, TransformComponent>();
    for (auto entity : view)
    {
        auto &camera = view.get<CameraComponent>(entity);
        auto &transform = view.get<TransformComponent>(entity);

        // Make sure the camera follows the target with quadratic easing
        camera.camera.target = Vector2Lerp(camera.camera.target, transform.position, 0.02f);

        // Update the camera position
        camera.camera.offset = Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        camera.camera.rotation = 0.0f;
        camera.camera.zoom = 1.0f;
    }
}

Camera2D *CameraSystem::GetCamera()
{
    auto view = m_registry.view<CameraComponent>();
    for (auto entity : view)
    {
        return &view.get<CameraComponent>(entity).camera;
    }

    return nullptr;
}