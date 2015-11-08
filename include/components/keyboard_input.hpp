#ifndef COMP_KEYBOARD_INPUT_HPP
#define COMP_KEYBOARD_INPUT_HPP

#include <allegro5/allegro.h>

#include <component.hpp>
#include <components/position.hpp>

namespace voidgame {
    class keyboard_input : public component {
        public:
            keyboard_input (std::shared_ptr<entity> _ent) : component (_ent, KEYBOARD_INPUT) {
                // get position component from entity
                pos = std::static_pointer_cast<position> (ent->get_component (POSITION) );
            }

            virtual void logic () {
            }

        private:
            std::shared_ptr<position> pos;
    };
}

#endif
