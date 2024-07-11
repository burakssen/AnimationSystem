#include "AttackAnimation.h"

AttackAnimation::AttackAnimation(std::shared_ptr<Animation> attackDown, std::shared_ptr<Animation> attackUp, std::shared_ptr<Animation> attackRight, std::shared_ptr<Animation> attackLeft)
{
    this->m_animations[Direction::Down] = attackDown;
    this->m_animations[Direction::Up] = attackUp;
    this->m_animations[Direction::Right] = attackRight;
    this->m_animations[Direction::Left] = attackLeft;
}
void AttackAnimation::Update(float deltaTime, entt::entity entity)
{
    auto &state = this->m_registry->get<EntityStateComponent>(entity);
    this->m_previousDirection = this->m_currentDirection;
    this->m_currentDirection = state.direction;
    this->m_animations[this->m_currentDirection]->Update(deltaTime);
}
std::shared_ptr<AnimationState> AttackAnimation::CheckTransitions()
{
    if (this->m_animations[this->m_currentDirection]->IsFinished())
    {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D))
        {
            auto newState = this->m_stateMachine->GetStates().at("walk");
            newState->SetDirection(this->m_previousDirection);
            return newState;
        }
        else
        {
            auto newState = this->m_stateMachine->GetStates().at("idle");
            newState->SetDirection(this->m_previousDirection);
            return newState;
        }
    }

    return nullptr;
}
