#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <entity.hpp>
#include <game_context.hpp>
#include <component_manager.hpp>
#include <components/position.hpp>
#include <components/thrust.hpp>
#include <components/sprite.hpp>
#include <components/player_control.hpp>
#include <components/collision.hpp>

using namespace voidgame;

int main (int argc, char** argv) {
    // initialize basic systems
    al_init ();
    al_set_app_name ("Void game");

    al_init_image_addon ();
    al_install_keyboard ();

    // create the window and FPS timer
    auto display = al_create_display (1600, 900);

    auto frame_timer = al_create_timer (1.0 / 60);

    // create the event queue
    auto equeue = al_create_event_queue ();
    al_register_event_source (equeue, al_get_display_event_source (display) );
    al_register_event_source (equeue, al_get_timer_event_source (frame_timer) );
    al_register_event_source (equeue, al_get_keyboard_event_source () );

    // TODO testing component code
    ALLEGRO_BITMAP* ship = al_load_bitmap ("data/media/ship.png");

    game_context game (display);

    // create entity 1 and all its components
    auto ent1 = std::make_shared<entity> (game);
    ent1->add_component (std::make_shared<position> (ent1, 250, 400) );
    ent1->add_component (std::make_shared<sprite> (ent1, ship) );
    ent1->add_component (std::make_shared<thrust> (ent1, 2.0, 1.5, 0.01, 0.01) );
    ent1->add_component (std::make_shared<player_control> (ent1) );
    ent1->add_component (std::make_shared<collision> (ent1) );

    // add a component manager to the game context
    auto compmgr = std::make_shared<component_manager> ();
    game.add_component_manager (std::vector<uint16_t> {SPRITE,
                                                       PLAYER_CONTROL,
                                                       THRUST,
                                                       COLLISION},
                                                       compmgr);

    // add entities
    game.add_entity (std::move (ent1) );

    // test factory method
    //voidgame::comp_map ()["position"] ();
    i//std::shared_ptr<entity> testy = factory_map ()["position"] (;
    //func = voidgame::position::factory;
    //func ();

    // TODO end testing

    // prepare to begin the main loop
    al_clear_to_color (al_map_rgb (0, 0, 0) );
    al_flip_display ();

    al_start_timer (frame_timer);

    auto redraw = false;

    // handle events and redrawing the screen
    while (!game.is_done () ) {
        ALLEGRO_EVENT ev;

        al_wait_for_event (equeue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            game.set_done (true);
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    game.set_done (true);
                    break;
            }
        }

        // right now the game speed is locked to 60 FPS, logic and rendering
        if (redraw && al_is_event_queue_empty (equeue) ) {
            redraw = false;
            al_clear_to_color (al_map_rgb (0, 0, 0) );

            game.logic ();
            game.render ();

            al_flip_display ();
        }
    }

    // clean up
    al_destroy_bitmap (ship);

    al_destroy_timer (frame_timer);
    al_destroy_event_queue (equeue);
    al_destroy_display (display);

    return 0;
}
