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

class WalkAnimation : public AnimationState
{
public:
    WalkAnimation(std::shared_ptr<Animation> walkDown, std::shared_ptr<Animation> walkUp, std::shared_ptr<Animation> walkRight, std::shared_ptr<Animation> walkLeft);

    void Update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> CheckTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};