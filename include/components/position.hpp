#ifndef COMP_POSITION_HPP
#define COMP_POSITION_HPP

#include <component.hpp>

namespace voidgame {
    class position : public component {
        public:
            position (std::shared_ptr<entity> _ent, const double _x, const double _y)
                : component (_ent, POSITION), x (_x), y (_y) {}

            double get_x () { return x; }
            double get_y () { return y; }
            void set_x (const double _x) { x = _x; }
            void set_y (const double _y) { y = _y; }

        private:
            double x, y;
    };
}

#endif
