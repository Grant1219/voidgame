#ifndef COMP_PLAYER_CONTROL_HPP
#define COMP_PLAYER_CONTROL_HPP

#include <allegro5/allegro.h>

#include <component.hpp>
#include <components/thrust.hpp>

namespace voidgame {
    class player_control : public component {
        public:
            player_control (std::shared_ptr<entity> _ent) : component (_ent, PLAYER_CONTROL) {
                // get thrust component from entity
                thrusters = std::static_pointer_cast<thrust> (ent->get_component (THRUST) );
            }

            virtual void logic () override {
                al_get_keyboard_state (&state);

                if (al_key_down (&state, ALLEGRO_KEY_RIGHT) )
                    thrusters->h_thrust (0.1);
                if (al_key_down (&state, ALLEGRO_KEY_LEFT) )
                    thrusters->h_thrust (-0.1);
                if (al_key_down (&state, ALLEGRO_KEY_DOWN) )
                    thrusters->v_thrust (0.1);
                if (al_key_down (&state, ALLEGRO_KEY_UP) )
                    thrusters->v_thrust (-0.1);
            }

        private:
            ALLEGRO_KEYBOARD_STATE state;
            std::shared_ptr<thrust> thrusters;
    };
}

#endif
