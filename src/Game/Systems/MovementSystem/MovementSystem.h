#pragma once

// Standard Headers

// External Headers
#include <raylib.h>
#include <raymath.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Game/Components/TransformComponent.h"
#include "Game/Components/EntityStateComponent.h"

class MovementSystem
{
public:
    MovementSystem(entt::registry &registry) : m_registry(registry) {}

    void update(float deltaTime);

private:
    entt::registry &m_registry;
};