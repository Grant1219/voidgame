#ifndef ENTITY_HPP 
#define ENTITY_HPP

#include <map>
#include <memory>

namespace voidgame {
    class component;

    class entity {
        public:
            entity ();

            uint64_t get_id () { return eid; }

            void add_component (std::shared_ptr<component> _comp);
            std::shared_ptr<component> get_component (uint16_t _type);

            const std::map<uint16_t, std::shared_ptr<component> >& get_components () { return components; }
 
        private:
            uint64_t eid;
            std::map<uint16_t, std::shared_ptr<component> > components;

            static uint64_t nextid;
    };
}

#endif
