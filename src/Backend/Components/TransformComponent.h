#pragma once

// Standard Headers

// External Headers
#include <raylib.h>

// Internal Headers

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

struct TransformComponent
{
    Vector2 position;
    float rotation;
    Vector2 scale;
    Vector2 direction;
};