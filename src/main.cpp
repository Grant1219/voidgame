#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <entity.hpp>
#include <game_context.hpp>
#include <component_manager.hpp>
#include <components/position.hpp>
#include <components/sprite.hpp>
#include <components/keyboard_input.hpp>

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
    std::cout << "Testing component code" << std::endl;

    ALLEGRO_BITMAP* ship = al_load_bitmap ("data/ship.png");

    voidgame::game_context game;

    // create entity 1 and all its components
    auto ent1 = std::make_shared<voidgame::entity> ();
    auto pos1 = std::make_shared<voidgame::position> (ent1, 250, 400);
    ent1->add_component (pos1);
    auto sp1 = std::make_shared<voidgame::sprite> (ent1, ship);
    ent1->add_component (sp1);
    auto input = std::make_shared<voidgame::keyboard_input> (ent1);
    ent1->add_component (input);

    // create entity 2
    auto ent2 = std::make_shared<voidgame::entity> ();
    auto pos2 = std::make_shared<voidgame::position> (ent2, 900, 200);
    ent2->add_component (pos2);
    auto sp2 = std::make_shared<voidgame::sprite> (ent2, ship);
    ent2->add_component (sp2);

    // add a component manager to the game context
    auto compmgr = std::make_shared<voidgame::component_manager> ();
    game.add_component_manager (std::vector<uint16_t> {voidgame::SPRITE, voidgame::KEYBOARD_INPUT}, compmgr);

    // add entities
    game.add_entity (ent1);
    game.add_entity (ent2);

    // TODO end testing

    // prepare to begin the main loop
    al_clear_to_color (al_map_rgb (0, 0, 0) );
    al_flip_display ();

    al_start_timer (frame_timer);

    auto done = false;
    auto redraw = false;

    // handle events and redrawing the screen
    while (!done) {
        ALLEGRO_EVENT ev;

        al_wait_for_event (equeue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            done = true;
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
            }
        }

        if (redraw && al_is_event_queue_empty (equeue) ) {
            redraw = false;
            al_clear_to_color (al_map_rgb (0, 0, 0) );

            // TODO more testing
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
