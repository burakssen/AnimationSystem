#pragma once

// Standard Headers
#include <memory>

// External Headers
#include <raylib.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Game/Components/TransformComponent.h"
#include "Game/Components/EntityStateComponent.h"
#include "Game/Systems/AnimationSystem/AnimationState.h"

class IdleAnimation : public AnimationState
{
public:
    IdleAnimation(std::shared_ptr<Animation> idleDown, std::shared_ptr<Animation> idleUp, std::shared_ptr<Animation> idleRight, std::shared_ptr<Animation> idleLeft);
    void update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> checkTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};