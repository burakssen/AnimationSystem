#pragma once

// Standard Headers
#include <memory>
#include <unordered_map>

// External Headers
#include <entt/entt.hpp>

// Internal Headers
#include "Backend/Systems/AnimationSystem/AnimationState/AnimationState.h"

class AnimationState;

class AnimationStateMachine : public std::enable_shared_from_this<AnimationStateMachine>
{
public:
    AnimationStateMachine(entt::registry &registry) : m_registry(registry) {}
    void AddState(const std::string &name, std::shared_ptr<AnimationState> state);
    void SetInitialState(const std::string &name);
    std::shared_ptr<AnimationState> GetCurrentState() const;
    std::unordered_map<std::string, std::shared_ptr<AnimationState>> &GetStates() { return m_states; }

private:
    std::unordered_map<std::string, std::shared_ptr<AnimationState>> m_states;
    std::shared_ptr<AnimationState> m_currentState;
    entt::registry &m_registry;
};