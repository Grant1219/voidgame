#ifndef COMP_POSITION_HPP
#define COMP_POSITION_HPP

#include <iostream>

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

        public:
            static std::shared_ptr<position> factory (std::shared_ptr<entity> _ent) {
                return std::make_shared<position> (_ent, 0, 0);
            }

        private:
            double x, y;
    };

    static bool position_factory = voidgame::register_factory ("position", std::function<std::shared_ptr<component>(std::shared_ptr<entity>)> (voidgame::position::factory) );
}

#endif
