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

class AttackAnimation : public AnimationState
{
public:
    AttackAnimation(std::shared_ptr<Animation> attackDown, std::shared_ptr<Animation> attackUp, std::shared_ptr<Animation> attackRight, std::shared_ptr<Animation> attackLeft);
    void update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> checkTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};