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
                al_get_keyboard_state (&state);

                auto x = pos->get_x ();
                auto y = pos->get_y ();

                if (al_key_down (&state, ALLEGRO_KEY_RIGHT) )
                    x += 2;
                if (al_key_down (&state, ALLEGRO_KEY_LEFT) )
                    x -= 2;
                if (al_key_down (&state, ALLEGRO_KEY_DOWN) )
                    y += 2;
                if (al_key_down (&state, ALLEGRO_KEY_UP) )
                    y -= 2;

                pos->set_x (x);
                pos->set_y (y);
            }

        private:
            ALLEGRO_KEYBOARD_STATE state;
            std::shared_ptr<position> pos;
    };
}

#endif
