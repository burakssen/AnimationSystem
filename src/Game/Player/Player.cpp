#include "Player.h"

Player::Player(entt::registry &registry)
    : m_registry(registry),
      m_animationStateMachine(std::make_unique<AnimationStateMachine>(registry)),
      m_textureHandler(&TextureHandler::GetInstance())
{
    auto entity = m_registry.create();
    m_registry.emplace<TransformComponent>(entity, Vector2{0, 0}, 0.0f, Vector2{2, 2});
    m_registry.emplace<EntityStateComponent>(entity, "player");
    auto &camera = m_registry.emplace<CameraComponent>(entity);

    camera.camera.target = m_registry.get<TransformComponent>(entity).position;
    camera.camera.offset = Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.camera.rotation = 0.0f;
    camera.camera.zoom = 1.0f;

    auto &animationComponent = m_registry.emplace<AnimationComponent>(entity);

    auto idleDown = std::make_shared<Animation>(this->m_textureHandler->GetTexture("idle_down"), 6, 0.1f, true);
    auto idleUp = std::make_shared<Animation>(this->m_textureHandler->GetTexture("idle_up"), 6, 0.1f, true);
    auto idleRight = std::make_shared<Animation>(this->m_textureHandler->GetTexture("idle_right"), 6, 0.1f, true);
    auto idleLeft = std::make_shared<Animation>(this->m_textureHandler->GetTexture("idle_right"), 6, 0.1f, true, true); // Flip horizontally

    auto walkDown = std::make_shared<Animation>(this->m_textureHandler->GetTexture("walk_down"), 6, 0.1f, true);
    auto walkUp = std::make_shared<Animation>(this->m_textureHandler->GetTexture("walk_up"), 6, 0.1f, true);
    auto walkRight = std::make_shared<Animation>(this->m_textureHandler->GetTexture("walk_right"), 6, 0.1f, true);
    auto walkLeft = std::make_shared<Animation>(this->m_textureHandler->GetTexture("walk_right"), 6, 0.1f, true, true); // Flip horizontally

    auto attackDown = std::make_shared<Animation>(this->m_textureHandler->GetTexture("attack_down"), 4, 0.15f, false);
    auto attackUp = std::make_shared<Animation>(this->m_textureHandler->GetTexture("attack_up"), 4, 0.15f, false);
    auto attackRight = std::make_shared<Animation>(this->m_textureHandler->GetTexture("attack_right"), 4, 0.15f, false);
    auto attackLeft = std::make_shared<Animation>(this->m_textureHandler->GetTexture("attack_right"), 4, 0.15f, false, true); // Flip horizontally

    this->m_animationStateMachine->AddState("idle", std::make_shared<IdleAnimation>(idleDown, idleUp, idleRight, idleLeft));
    this->m_animationStateMachine->AddState("walk", std::make_shared<WalkAnimation>(walkDown, walkUp, walkRight, walkLeft));
    this->m_animationStateMachine->AddState("attack", std::make_shared<AttackAnimation>(attackDown, attackUp, attackRight, attackLeft));

    this->m_animationStateMachine->SetInitialState("idle");

    animationComponent.currentState = this->m_animationStateMachine->GetCurrentState();
}
