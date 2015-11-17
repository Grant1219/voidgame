#ifndef COMP_COLLISION_HPP
#define COMP_COLLISION_HPP

#include <component.hpp>

namespace voidgame {
    class collision : public component {
        public:
            collision (std::shared_ptr<entity> _ent, uint16_t _type) : component (_ent, COLLISION) {}
    };
}

#endif
