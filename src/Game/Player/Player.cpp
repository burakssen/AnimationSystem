#include "Player.h"

Player::Player(entt::registry &registry)
    : m_registry(registry),
      m_animationStateMachine(std::make_unique<AnimationStateMachine>(registry))
{
    auto entity = m_registry.create();
    m_registry.emplace<TransformComponent>(entity, Vector2{400, 300}, 0.0f, Vector2{2, 2});
    m_registry.emplace<EntityStateComponent>(entity, "player");

    auto &animationComponent = m_registry.emplace<AnimationComponent>(entity);

    auto idleDown = std::make_shared<Animation>("../resources/idle_down.png", 6, 0.1f, true);
    auto idleUp = std::make_shared<Animation>("../resources/idle_up.png", 6, 0.1f, true);
    auto idleRight = std::make_shared<Animation>("../resources/idle_right.png", 6, 0.1f, true);
    auto idleLeft = std::make_shared<Animation>("../resources/idle_right.png", 6, 0.1f, true, true); // Flip horizontally

    auto walkDown = std::make_shared<Animation>("../resources/walk_down.png", 6, 0.1f, true);
    auto walkUp = std::make_shared<Animation>("../resources/walk_up.png", 6, 0.1f, true);
    auto walkRight = std::make_shared<Animation>("../resources/walk_right.png", 6, 0.1f, true);
    auto walkLeft = std::make_shared<Animation>("../resources/walk_right.png", 6, 0.1f, true, true); // Flip horizontally

    auto attackDown = std::make_shared<Animation>("../resources/attack_down.png", 4, 0.15f, false);
    auto attackUp = std::make_shared<Animation>("../resources/attack_up.png", 4, 0.15f, false);
    auto attackRight = std::make_shared<Animation>("../resources/attack_right.png", 4, 0.15f, false);
    auto attackLeft = std::make_shared<Animation>("../resources/attack_right.png", 4, 0.15f, false, true); // Flip horizontally

    this->m_animationStateMachine->addState("idle", std::make_shared<IdleAnimation>(idleDown, idleUp, idleRight, idleLeft));
    this->m_animationStateMachine->addState("walk", std::make_shared<WalkAnimation>(walkDown, walkUp, walkRight, walkLeft));
    this->m_animationStateMachine->addState("attack", std::make_shared<AttackAnimation>(attackDown, attackUp, attackRight, attackLeft));

    this->m_animationStateMachine->setInitialState("idle");

    animationComponent.currentState = this->m_animationStateMachine->getCurrentState();
}