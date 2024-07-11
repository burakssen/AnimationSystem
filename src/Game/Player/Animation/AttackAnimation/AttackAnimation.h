#pragma once

// Standard Headers
#include <memory>

// External Headers
#include <raylib.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Components/TransformComponent.h"
#include "Backend/Components/EntityStateComponent.h"
#include "Backend/Systems/AnimationSystem/Animation/Animation.h"
#include "Backend/Systems/AnimationSystem/AnimationState/AnimationState.h"

class AttackAnimation : public AnimationState
{
public:
    AttackAnimation(std::shared_ptr<Animation> attackDown, std::shared_ptr<Animation> attackUp, std::shared_ptr<Animation> attackRight, std::shared_ptr<Animation> attackLeft);
    void Update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> CheckTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};