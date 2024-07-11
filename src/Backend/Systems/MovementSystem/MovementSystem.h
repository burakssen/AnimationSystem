#pragma once

// Standard Headers

// External Headers
#include <raylib.h>
#include <raymath.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Components/TransformComponent.h"
#include "Backend/Components/EntityStateComponent.h"

class MovementSystem
{
public:
    MovementSystem(entt::registry &registry) : m_registry(registry) {}

    void Update(float deltaTime);

private:
    entt::registry &m_registry;
};