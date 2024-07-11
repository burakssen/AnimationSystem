#pragma once

// Standard Headers

// External Headers
#include <raylib.h>
#include <raymath.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Components/CameraComponent.h"
#include "Backend/Components/TransformComponent.h"

class CameraSystem
{
public:
    CameraSystem(entt::registry &registry);
    ~CameraSystem() = default;

    void Update(float deltaTime);
    Camera2D *GetCamera();

private:
    entt::registry &m_registry;
};
