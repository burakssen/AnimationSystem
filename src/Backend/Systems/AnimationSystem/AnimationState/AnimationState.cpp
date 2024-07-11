#include "AnimationState.h"

void AnimationState::Enter()
{
    for (auto &anim : this->m_animations)
    {
        anim.second->Reset();
    }
}

void AnimationState::Exit()
{
}

void AnimationState::Draw(entt::entity entity) const
{
    auto &transform = this->m_registry->get<TransformComponent>(entity);

    // FIXME: Log warning if transformComponent is not found
    if (this->m_animations.find(this->m_currentDirection) == this->m_animations.end())
        return;

    this->m_animations.at(this->m_currentDirection)->Draw(transform);
}