#include <game_context.hpp>
#include <entity.hpp>
#include <component_manager.hpp>

namespace voidgame {
    void game_context::add_component_manager (uint16_t _type, std::shared_ptr<component_manager> _mgr) {
        managers[_type] = _mgr;
    }

    void game_context::add_component_manager (std::vector<uint16_t> _types, std::shared_ptr<component_manager> _mgr) {
        // register the component manager for every component type given
        for (auto t : _types)
            add_component_manager (t, _mgr);
    }

    void game_context::add_entity (std::shared_ptr<entity> _ent) {
        // go through the entity's components and add them to the right managers
        for (auto c : _ent->get_components () ) {
            auto mgr = managers.find (c.first);

            if (mgr != managers.end () )
                mgr->second->add_component (c.second);
        }

        entities.push_back (_ent);
    }

    void game_context::logic () {
        for (auto mgr : managers)
            mgr.second->logic ();
    }

    void game_context::render () {
        for (auto mgr : managers)
            mgr.second->render ();
    }
}
