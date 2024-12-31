//
// Created by Gabriel on 31/12/2024.
//

#include "Game.h"
#include <iostream>


Game::Game() {
    init_window();
    // init_menu();
}

void Game::init_window() {
    _window.create(_window_size, _game_name);
    _window.setFramerateLimit(_frame_limit);
    _window.setVerticalSyncEnabled(_vertical_sync_enabled);
}

void Game::init_menu() {
    _menu = Menu(_menu_size, _menu_position);
}

void Game::run() {
    while (_is_game_running) {
        user_input_system();
        render_system();
        // economy_system();
    }
}

void Game::user_input_system() {
    sf::Event event;
    while (_window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            _is_game_running = false;
            // _window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                const auto mouse_origin = Vec2(event.mouseButton.x, event.mouseButton.y);
                if (_menu.option_has_selected(mouse_origin)) {
                    std::cout << "clicked\n";
                    // clicked = true;
                    // selectedShape = s->shape();
                }
                // if (event.mouseButton.button == sf::Mouse::Left && !clicked)
                // {
                //     std::cout << "draw\n";
                // }
                //
                // if (event.mouseButton.button == sf::Mouse::Right && clicked)
                // {
                //     clicked = false;
                //     std::cout << "cancel\n";
                // }
            }
        }
    }
}

void Game::render_system() {
    _window.clear();
    _window.draw(*_menu.shape());
    _menu.draw_options_in_screen(&_window);
    _window.display();
}