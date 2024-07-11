#pragma once

// Standard Headers

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Animation.h"
#include "AnimationStateMachine.h"
#include "Game/Components/TransformComponent.h"

// Forward Declarations
class AnimationStateMachine;

class AnimationState
{
public:
    virtual ~AnimationState() = default;
    virtual void enter();
    virtual void update(float deltaTime, entt::entity) = 0;
    virtual void exit();
    virtual std::shared_ptr<AnimationState> checkTransitions() = 0;
    virtual void draw(entt::entity) const;

    void setDirection(Direction direction) { this->m_currentDirection = direction; }
    void setRegistry(entt::registry &reg) { this->m_registry = &reg; }

public:
    AnimationStateMachine *m_stateMachine = nullptr;

protected:
    std::unordered_map<Direction, std::shared_ptr<Animation>> m_animations;
    entt::registry *m_registry = nullptr;
    mutable Direction m_currentDirection = Direction::Down;
};