#pragma once

// Standard Headers
#include <string>

// External Headers

// Internal Headers
#include "TransformComponent.h"

struct EntityStateComponent
{
    std::string name;
    Direction direction = Direction::Down;
};