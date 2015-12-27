#ifndef COMP_COLLISION_HPP
#define COMP_COLLISION_HPP

#include <component.hpp>
#include <components/position.hpp>
#include <components/sprite.hpp>

namespace voidgame {
    class collision : public component {
        public:
            collision (std::shared_ptr<entity> _ent) : component (_ent, COLLISION) {
                // get position and sprite components from entity
                pos = std::static_pointer_cast<position> (ent->get_component (POSITION) );
                sp = std::static_pointer_cast<sprite> (ent->get_component (SPRITE) );
            }

            virtual void logic () override {
                auto x = pos->get_x ();
                auto y = pos->get_y ();
                auto display = ent->get_game_context ().get_display ();
                auto limit_x = al_get_display_width (display) - sp->get_width ();
                auto limit_y = al_get_display_height (display) - sp->get_height ();

                // don't allow collision objects to go outside the screen
                if (x < 0)
                    pos->set_x (0);
                else if (x > limit_x)
                    pos->set_x (limit_x);

                if (y < 0)
                    pos->set_y (0);
                else if (y > limit_y)
                    pos->set_y (limit_y);
            }

        private:
            std::shared_ptr<position> pos;
            std::shared_ptr<sprite> sp;
    };
}

#endif
