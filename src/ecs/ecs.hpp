#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <array>
#include <memory>
#include <vector>

namespace Core::ECS
{

using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
    static ECS::ComponentID lastID = 0;
    return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept
{
    static ECS::ComponentID typeID = getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

class Component;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Entity
{
public:
    Entity() {};
    virtual ~Entity() {}

    virtual void Update();
    
    bool isActive() const;
    void Destroy();

    template <typename cmp_type> bool hasComponent() const
    {
        static_assert(
            std::is_base_of<ECS::Component, cmp_type>::value, 
            "Cannot add component, type is not derived from component class."
        );

        return m_ComponentBitSet[ECS::getComponentTypeID<cmp_type>()];
    }

    template <typename T, typename... TArgs> T& addComponent(TArgs&&... args)
    {
        static_assert(
            std::is_base_of<ECS::Component, T>::value, 
            "Cannot add component, type is not derived from component class."
        );

        T* c(new T(std::forward<TArgs>(args)...));
        c->m_pEntity = this;
        std::unique_ptr<ECS::Component> upComponent{c};

        m_Components.emplace_back(std::move(upComponent));
        m_ComponentArray[ECS::getComponentTypeID<T>()] = c;
        m_ComponentBitSet[ECS::getComponentTypeID<T>()] = true;
       
        c->Init();
        return *c;
    }

    template <typename T> T* getComponent() const
    {
        // !!!
        Component* pComponent = m_ComponentArray[getComponentTypeID<T>()];
        return static_cast<T*>(pComponent);
    }

protected:
    bool m_bActive = true;
    std::vector<std::unique_ptr<Component>> m_Components;

    ComponentArray m_ComponentArray;
    ComponentBitSet m_ComponentBitSet;

};

class Component
{
public:
    Component() {};

    virtual void Init() {};
    virtual void Update() {};

    virtual ~Component() {};

public:
    Entity* m_pEntity = nullptr;

};

}

#endif // ECS_H
