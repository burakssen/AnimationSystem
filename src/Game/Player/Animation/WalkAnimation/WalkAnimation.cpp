#include "WalkAnimation.h"

WalkAnimation::WalkAnimation(std::shared_ptr<Animation> walkDown, std::shared_ptr<Animation> walkUp, std::shared_ptr<Animation> walkRight, std::shared_ptr<Animation> walkLeft)
{
    this->m_animations[Direction::Down] = walkDown;
    this->m_animations[Direction::Up] = walkUp;
    this->m_animations[Direction::Right] = walkRight;
    this->m_animations[Direction::Left] = walkLeft;
}

void WalkAnimation::Update(float deltaTime, entt::entity entity)
{
    auto &state = this->m_registry->get<EntityStateComponent>(entity);
    this->m_previousDirection = this->m_currentDirection;
    this->m_currentDirection = state.direction;
    this->m_animations[this->m_currentDirection]->Update(deltaTime);
}

std::shared_ptr<AnimationState> WalkAnimation::CheckTransitions()
{
    if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D))
    {
        auto newState = this->m_stateMachine->GetStates().at("idle");
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