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

class WalkAnimation : public AnimationState
{
public:
    WalkAnimation(std::shared_ptr<Animation> walkDown, std::shared_ptr<Animation> walkUp, std::shared_ptr<Animation> walkRight, std::shared_ptr<Animation> walkLeft);

    void update(float deltaTime, entt::entity entity) override;
    std::shared_ptr<AnimationState> checkTransitions() override;

private:
    mutable Direction m_previousDirection = Direction::Down;
};