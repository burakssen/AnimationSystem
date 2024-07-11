#pragma once

// Standard Headers
#include <memory>
#include <unordered_map>

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "AnimationState.h"

class AnimationState;

class AnimationStateMachine : public std::enable_shared_from_this<AnimationStateMachine>
{
public:
    AnimationStateMachine(entt::registry &registry) : m_registry(registry) {}
    void addState(const std::string &name, std::shared_ptr<AnimationState> state);
    void setInitialState(const std::string &name);
    std::shared_ptr<AnimationState> getCurrentState() const;
    std::unordered_map<std::string, std::shared_ptr<AnimationState>> &getStates() { return m_states; }

private:
    std::unordered_map<std::string, std::shared_ptr<AnimationState>> m_states;
    std::shared_ptr<AnimationState> m_currentState;
    entt::registry &m_registry;
};