#include "AnimationState.h"

void AnimationState::enter()
{
    for (auto &anim : this->m_animations)
    {
        anim.second->reset();
    }
}

void AnimationState::exit()
{
}

void AnimationState::draw(entt::entity entity) const
{
    auto &transform = this->m_registry->get<TransformComponent>(entity);

    // FIXME: Log warning if transformComponent is not found
    if (this->m_animations.find(this->m_currentDirection) == this->m_animations.end())
        return;

    this->m_animations.at(this->m_currentDirection)->draw(transform);
}