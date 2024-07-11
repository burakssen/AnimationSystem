#include "MovementSystem.h"

void MovementSystem::Update(float deltaTime)
{
    this->m_registry.view<TransformComponent, EntityStateComponent>().each(
        [deltaTime](auto entity, TransformComponent &transform, EntityStateComponent &state)
        {
            Vector2 direction = {0, 0};
            if (IsKeyDown(KEY_W))
            {
                direction.y = -1;
                state.direction = Direction::Up;
            }
            if (IsKeyDown(KEY_S))
            {
                direction.y = 1;
                state.direction = Direction::Down;
            }
            if (IsKeyDown(KEY_A))
            {
                direction.x = -1;
                state.direction = Direction::Left;
            }
            if (IsKeyDown(KEY_D))
            {
                direction.x = 1;
                state.direction = Direction::Right;
            }
            direction = Vector2Normalize(direction);
            float speed = 100.0f;
            transform.position.x += direction.x * speed * deltaTime;
            transform.position.y += direction.y * speed * deltaTime;
        });
}