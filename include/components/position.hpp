#ifndef COMP_POSITION_HPP
#define COMP_POSITION_HPP

#include <component.hpp>

namespace voidgame {
    class position : public component {
        public:
            position (std::shared_ptr<entity> _ent, const uint32_t _x, const uint32_t _y) : component (_ent, POSITION), x (_x), y (_y) {}

            const uint32_t get_x () { return x; }
            const uint32_t get_y () { return y; }
            void set_x (const uint32_t _x) { x = _x; }
            void set_y (const uint32_t _y) { y = _y; }

        private:
            uint32_t x, y;
    };
}

#endif
