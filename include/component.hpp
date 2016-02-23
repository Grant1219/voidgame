#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <map>
#include <memory>
#include <functional>
#include <iostream>

#include <entity.hpp>

namespace voidgame {
    // enum used during runtime
    enum comp_type : uint16_t {
        POSITION = 1,
        THRUST,
        SPRITE,
        COLLISION,
        PLAYER_CONTROL
    };

    // mapping used during component file loading
    /*
    static std::map<std::string, uint16_t> comp_map {
        {"position", POSITION},
        {"thrust", THRUST},
        {"sprite", SPRITE},
        {"collision", COLLISION},
        {"player_control", PLAYER_CONTROL},
    };
    */

    class component {
        public:
            component (std::shared_ptr<entity> _ent, uint16_t _type) : type (_type), ent (_ent) {}

            uint16_t get_type () { return type; }

            virtual void logic () {}
            virtual void render () {}

        protected:
            uint16_t type;
            std::shared_ptr<entity> ent;
    };

    static std::map<const std::string, std::function<std::shared_ptr<component>(std::shared_ptr<entity>)>>& factory_map () {
        static std::map<const std::string, std::function<std::shared_ptr<component>(std::shared_ptr<entity>)>> cm;
        return cm;
    }

    static bool register_factory (const std::string& _type, std::function<std::shared_ptr<component>(std::shared_ptr<entity>)> _func) {
        factory_map ()[_type] = _func;
        return true;
    }
}

#endif
