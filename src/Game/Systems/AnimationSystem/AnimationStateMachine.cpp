#include "AnimationStateMachine.h"

void AnimationStateMachine::addState(const std::string &name, std::shared_ptr<AnimationState> state)
{
    state->m_stateMachine = this;
    state->setRegistry(this->m_registry);
    this->m_states[name] = state;
}

void AnimationStateMachine::setInitialState(const std::string &name)
{
    m_currentState = this->m_states[name];
    this->m_currentState->enter();
}

std::shared_ptr<AnimationState> AnimationStateMachine::getCurrentState() const
{
    return this->m_currentState;
}