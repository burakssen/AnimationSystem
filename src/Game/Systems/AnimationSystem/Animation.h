#pragma once

// Standard Headers
#include <math.h>

// External Headers
#include <raylib.h>

// Internal Headers
#include "Game/Components/TransformComponent.h"

class Animation
{
public:
    Animation(const char *spritesheetPath, int frameCount, float frameDuration, bool looping, bool horizontalFlip = false);
    ~Animation();

    void update(float deltaTime);
    void draw(const TransformComponent &transform) const;
    bool isFinished() const;
    void reset();

private:
    Texture2D m_spriteSheet;
    int m_frameCount;
    float m_frameDuration;
    bool m_looping;
    Rectangle m_frameRect;
    bool m_horizontalFlip;
    float m_currentFrame;
};