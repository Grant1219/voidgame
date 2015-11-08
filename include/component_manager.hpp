#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <memory>
#include <vector>

#include <component.hpp>

namespace voidgame {
    class component_manager {
        public:
            void add_component (std::shared_ptr<component> _comp) {
                components.push_back (_comp);
            }

            void logic () {
                for (auto i : components) {
                    i->logic ();
                }
            }

            void render () {
                for (auto i : components) {
                    i->render ();
                }
            }
        
        private:
            std::vector<std::shared_ptr<component> > components;
    };
}

#endif
