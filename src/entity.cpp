#include <entity.hpp>
#include <component.hpp>
#include <game_context.hpp>

namespace voidgame {
    uint64_t entity::nextid = 1;

    entity::entity (game_context& _context) : context (_context) {
        eid = entity::nextid;
        entity::nextid++;
    }

    void entity::add_component (std::shared_ptr<component> _comp) {
        components[_comp->get_type ()] = _comp;
    }

    std::shared_ptr<component> entity::get_component (uint16_t _type) {
        auto comp = components.find (_type);
        return (comp != components.end () ) ? comp->second : nullptr;
    }
}
