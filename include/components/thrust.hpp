#ifndef COMP_THRUST_HPP
#define COMP_THRUST_HPP

#include <component.hpp>
#include <components/position.hpp>

namespace voidgame {
    class thrust : public component {
        public:
            thrust (std::shared_ptr<entity> _ent, const double _max_h_thrust, const double _max_v_thrust, const double _h_slowdown, const double _v_slowdown)
                : component (_ent, comp_type::THRUST),
                  max_h_thrust (_max_h_thrust),
                  max_v_thrust (_max_v_thrust),
                  h_slowdown (_h_slowdown),
                  v_slowdown (_v_slowdown) {

                // get the position component
                pos = std::static_pointer_cast<position> (ent->get_component (POSITION) );
            }

            void h_thrust (const double _thrust) {
                curr_h_thrust += _thrust;
                if (curr_h_thrust < 0.0)
                    curr_h_thrust = std::max (-max_h_thrust, curr_h_thrust);
                else
                    curr_h_thrust = std::min (max_h_thrust, curr_h_thrust);
            }
            void v_thrust (const double _thrust) {
                curr_v_thrust += _thrust;
                if (curr_v_thrust < 0.0)
                    curr_v_thrust = std::max (-max_v_thrust, curr_v_thrust);
                else
                    curr_v_thrust = std::min (max_v_thrust, curr_v_thrust);
            }

            virtual void logic () override {
                // apply thrust to position component
                pos->set_x (pos->get_x () + curr_h_thrust);
                pos->set_y (pos->get_y () + curr_v_thrust);

                // apply slowdown to thrust
                if (curr_h_thrust < 0.0) {
                    curr_h_thrust += h_slowdown;
                    // catch edge case where thrust reaches 0
                    if (curr_h_thrust > 0.0)
                        curr_h_thrust = 0.0;
                }
                else {
                    curr_h_thrust -= h_slowdown;
                    // catch edge case where thrust reaches 0
                    if (curr_h_thrust < 0.0)
                        curr_h_thrust = 0.0;
                }

                if (curr_v_thrust < 0.0) {
                    curr_v_thrust += v_slowdown;
                    // catch edge case where thrust reaches 0
                    if (curr_v_thrust > 0.0)
                        curr_v_thrust = 0.0;
                }
                else {
                    curr_v_thrust -= v_slowdown;
                    // catch edge case where thrust reaches 0
                    if (curr_v_thrust < 0.0)
                        curr_v_thrust = 0.0;
                }
            }
        private:
            double max_h_thrust, max_v_thrust;
            double h_slowdown, v_slowdown;

            double curr_h_thrust = 0.0;
            double curr_v_thrust = 0.0;

            std::shared_ptr<position> pos;
    };
}

#endif
