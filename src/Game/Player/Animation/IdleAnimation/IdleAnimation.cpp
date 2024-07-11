#include "IdleAnimation.h"

IdleAnimation::IdleAnimation(std::shared_ptr<Animation> idleDown, std::shared_ptr<Animation> idleUp, std::shared_ptr<Animation> idleRight, std::shared_ptr<Animation> idleLeft)
{
    this->m_animations[Direction::Down] = idleDown;
    this->m_animations[Direction::Up] = idleUp;
    this->m_animations[Direction::Right] = idleRight;
    this->m_animations[Direction::Left] = idleLeft;
}

void IdleAnimation::Update(float deltaTime, entt::entity entity)
{
    auto &state = this->m_registry->get<EntityStateComponent>(entity);
    this->m_previousDirection = this->m_currentDirection;
    this->m_currentDirection = state.direction;
    this->m_animations[this->m_currentDirection]->Update(deltaTime);
}

std::shared_ptr<AnimationState> IdleAnimation::CheckTransitions()
{
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D))
    {
        auto newState = this->m_stateMachine->GetStates().at("walk");
        newState->SetDirection(this->m_previousDirection);
        return newState;
    }
    else if (IsKeyDown(KEY_SPACE))
    {
        auto newState = this->m_stateMachine->GetStates().at("attack");
        newState->SetDirection(this->m_previousDirection);
        return newState;
    }

    return nullptr;
}