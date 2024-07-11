#pragma once

// Standard Headers
#include <memory>

// External Headers

// Internal Headers
#include "Game/Systems/AnimationSystem/AnimationState.h"

struct AnimationComponent
{
    std::shared_ptr<AnimationState> currentState;
};