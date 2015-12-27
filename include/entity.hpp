#ifndef ENTITY_HPP 
#define ENTITY_HPP

#include <map>
#include <memory>

namespace voidgame {
    class component;
    class game_context;

    class entity {
        public:
            entity (game_context& _context);

            uint64_t get_id () { return eid; }

            void add_component (std::shared_ptr<component> _comp);
            std::shared_ptr<component> get_component (uint16_t _type);

            game_context& get_game_context () { return context; }

            const std::map<uint16_t, std::shared_ptr<component> >& get_components () { return components; }
 
        private:
            uint64_t eid;
            std::map<uint16_t, std::shared_ptr<component> > components;
            game_context& context;

            static uint64_t nextid;
    };
}

#endif
