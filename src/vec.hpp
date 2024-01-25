#ifndef VEC_HPP
#define VEC_HPP

namespace Core
{

template <class type>
struct vec2
{
    type x, y;

    bool operator==(const vec2<type>& v) { return (x == v.x && y == v.y); }
    bool operator!=(const vec2<type>& v) { return !(*this == v); }
};

}

#endif // VEC_HPP
