#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "../ecs.hpp"
#include "../../vec.hpp"

namespace Core::ECS
{

class PositionComponent : public Component
{
public:
    PositionComponent() : m_vPosition(0.0f, 0.0f) {}
    PositionComponent(vec2<float> pos) : m_vPosition(pos) {}

    vec2<float> getPosition() const { return m_vPosition; }
    void setPosition(vec2<float> vpos) { m_vPosition = vpos; }

private:
    vec2<float> m_vPosition;

};

}

#endif // POSITION_COMPONENT_HPP
