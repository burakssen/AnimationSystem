#pragma once

// Standard Headers
#include <math.h>

// External Headers
#include <raylib.h>

// Internal Headers
#include "Backend/Components/TransformComponent.h"

class Animation
{
public:
    Animation(Texture2D *texture, int frameCount, float frameDuration, bool looping, bool horizontalFlip = false);
    ~Animation();

    void Update(float deltaTime);
    void Draw(const TransformComponent &transform) const;
    bool IsFinished() const;
    void Reset();

private:
    Texture2D *m_spriteSheet = nullptr;
    int m_frameCount;
    float m_frameDuration;
    bool m_looping;
    Rectangle m_frameRect;
    bool m_horizontalFlip;
    float m_currentFrame;
};