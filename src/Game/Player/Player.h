#pragma once

// Standard Headers
#include <memory>

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Animation/IdleAnimation/IdleAnimation.h"
#include "Animation/WalkAnimation/WalkAnimation.h"
#include "Animation/AttackAnimation/AttackAnimation.h"
#include "Backend/Components/TransformComponent.h"
#include "Backend/Components/AnimationComponent.h"
#include "Backend/Components/EntityStateComponent.h"
#include "Backend/Components/CameraComponent.h"
#include "Backend/Systems/AnimationSystem/AnimationStateMachine/AnimationStateMachine.h"
#include "Backend/Handlers/TextureHandler/TextureHandler.h"

class Player
{
public:
    Player(entt::registry &registry);
    ~Player() = default;

private:
    entt::registry &m_registry;
    TextureHandler *m_textureHandler = nullptr;
    std::unique_ptr<AnimationStateMachine> m_animationStateMachine;
};