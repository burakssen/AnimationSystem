#pragma once

// Standard Headers
#include <memory>

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Animation/IdleAnimation.h"
#include "Animation/WalkAnimation.h"
#include "Animation/AttackAnimation.h"
#include "Game/Components/TransformComponent.h"
#include "Game/Components/AnimationComponent.h"
#include "Game/Components/EntityStateComponent.h"
#include "Game/Systems/AnimationSystem/AnimationStateMachine.h"

class Player
{
public:
    Player(entt::registry &registry);
    ~Player() = default;

private:
    entt::registry &m_registry;
    std::unique_ptr<AnimationStateMachine> m_animationStateMachine;
};