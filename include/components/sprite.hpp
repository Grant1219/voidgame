#ifndef COMP_SPRITE_HPP
#define COMP_SPRITE_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <component.hpp>
#include <components/position.hpp>

namespace voidgame {
    class sprite : public component {
        public:
            sprite (std::shared_ptr<entity> _ent, ALLEGRO_BITMAP* _bmp) : component (_ent, SPRITE) {
                bmp = _bmp;

                // get position component from entity
                pos = std::static_pointer_cast<position> (ent->get_component (POSITION) );
            }

            virtual void render () {
                // TODO render actual bitmap
                auto x = pos->get_x ();
                auto y = pos->get_y ();

                al_draw_filled_rectangle (x, y, x + 100, y + 100, al_map_rgb (255, 255, 255) );
            }
        private:
            ALLEGRO_BITMAP* bmp;
            std::shared_ptr<position> pos;
    };
}

#endif
