#pragma once

// Standard Headers
#include <memory>

// External Headers
#include <raylib.h>
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Components/TransformComponent.h"
#include "Backend/Components/EntityStateComponent.h"
#include "Backend/Systems/AnimationSystem/AnimationState/AnimationState.h"

class IdleAnimation : public AnimationState
{
public:
    IdleAnimation(std::shared_ptr<Animation> idleDown, std::shared_ptr<Animation> idleUp, std::shared_ptr<Animation> idleRight, std::shared_ptr<Animation> idleLeft);
    void Update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> CheckTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};