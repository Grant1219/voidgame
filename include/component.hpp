#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

#include <entity.hpp>

namespace voidgame {
    enum comp_type {
        POSITION = 1,
        SPRITE,
        KEYBOARD_INPUT
    };

    class component {
        public:
            component (std::shared_ptr<entity> _ent, uint16_t _type) : type (_type), ent (_ent) {}

            uint16_t get_type () { return type; }

            virtual void logic () {}
            virtual void render () {}

        protected:
            uint16_t type;
            std::shared_ptr<entity> ent;
    };
}

#endif
