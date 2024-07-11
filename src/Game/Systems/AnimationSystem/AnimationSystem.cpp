#include "AnimationSystem.h"

AnimationSystem::AnimationSystem(entt::registry &registry) : m_registry(registry) {}

void AnimationSystem::update(float deltaTime)
{
    this->m_registry.view<AnimationComponent>().each(
        [deltaTime](auto entity, AnimationComponent &animComp)
        {
            auto newState = animComp.currentState->checkTransitions();
            if (newState && newState != animComp.currentState)
            {
                animComp.currentState->exit();
                animComp.currentState = newState;
                animComp.currentState->enter();
            }
            animComp.currentState->update(deltaTime, entity);
        });
}

void AnimationSystem::draw()
{
    this->m_registry.view<AnimationComponent>().each(
        [](auto entity, const AnimationComponent &animComp)
        { animComp.currentState->draw(entity); });
}