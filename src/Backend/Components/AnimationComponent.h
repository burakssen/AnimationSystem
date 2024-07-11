#pragma once

// Standard Headers
#include <memory>

// External Headers

// Internal Headers
#include "Backend/Systems/AnimationSystem/AnimationState/AnimationState.h"

struct AnimationComponent
{
    std::shared_ptr<AnimationState> currentState;
};