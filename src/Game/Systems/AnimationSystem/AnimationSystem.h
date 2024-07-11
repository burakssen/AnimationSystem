#pragma once

// Standard Headers

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Game/Components/AnimationComponent.h"

class AnimationSystem
{
public:
    AnimationSystem(entt::registry &registry);
    void update(float deltaTime);
    void draw();

private:
    entt::registry &m_registry;
};