#ifndef VEC_HPP
#define VEC_HPP

namespace Core
{

template <class type>
struct vec2
{
    type m_X, m_Y;

    vec2() = default;
    vec2(type x, type y) : m_X(x), m_Y(y) {}

    bool operator==(const vec2<type>& v) { return (m_X == v.m_X && m_Y == v.m_Y); }
    bool operator!=(const vec2<type>& v) { return !(*this == v); }

};

}

#endif // VEC_HPP
