#pragma once

// Standard Headers

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Components/AnimationComponent.h"

class AnimationSystem
{
public:
    AnimationSystem(entt::registry &registry);
    void Update(float deltaTime);
    void Draw();

private:
    entt::registry &m_registry;
};