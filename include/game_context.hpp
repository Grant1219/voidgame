#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <map>
#include <vector>
#include <memory>

namespace voidgame {
    class component_manager;
    class entity;

    class game_context {
        public:
            void add_component_manager (uint16_t _type, std::shared_ptr<component_manager> _mgr);
            void add_component_manager (std::vector<uint16_t> _types, std::shared_ptr<component_manager> _mgr);

            void add_entity (std::shared_ptr<entity> _ent);

            void logic ();
            void render ();
        private:
            std::map<uint16_t, std::shared_ptr<component_manager> > managers;
    };
}

#endif
