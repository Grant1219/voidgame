#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <map>
#include <vector>
#include <memory>

#include <allegro5/allegro5.h>

namespace voidgame {
    class component_manager;
    class entity;

    class game_context {
        public:
            game_context (ALLEGRO_DISPLAY* _display) { display = _display; }

            void add_component_manager (uint16_t _type, std::shared_ptr<component_manager> _mgr);
            void add_component_manager (std::vector<uint16_t> _types, std::shared_ptr<component_manager> _mgr);

            void add_entity (std::shared_ptr<entity> _ent);

            void logic ();
            void render ();

            ALLEGRO_DISPLAY* get_display () { return display; }

            void set_done (bool _state) { done = _state; }
            bool is_done () { return done; }
        private:
            bool done = false;
            ALLEGRO_DISPLAY* display;

            std::vector<std::shared_ptr<entity> > entities;
            std::map<uint16_t, std::shared_ptr<component_manager> > managers;
    };
}

#endif
