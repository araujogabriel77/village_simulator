//
// Created by Gabriel on 31/12/2024.
//

#include "Game.h"
#include <iostream>

#include "House.h"
#include "Market.h"


Game::Game() {
    init_window();
}

void Game::init_window() {
    _window.create(_window_size, _game_name);
    _window.setFramerateLimit(_frame_limit);
    _window.setVerticalSyncEnabled(_vertical_sync_enabled);
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
    while (_window.pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            _is_game_running = false;
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left && !_has_building_selected) {
                const auto mouse_origin = Vec2(static_cast<float>(event.mouseButton.x),
                                               static_cast<float>(event.mouseButton.y));

                const BuildingType building = _menu.get_selected_option_building_type(mouse_origin);
                std::cout << (_current_selected_building != nullptr) << "\n";

                int building_id = _current_selected_building_id + (_buildings.size() + 1);

                switch (building) {
                    case BuildingType::House: {
                        _current_selected_building = std::make_shared<House>(
                        building_id, Vec2(500, 500));
                        break;
                    }
                    case BuildingType::Market: {
                        _current_selected_building = std::make_shared<Market>(
                        building_id, Vec2(500, 500));
                        break;
                    }
                    case BuildingType::None: {
                        deselect_current_building();
                        break;
                    }
                }

                if (building != BuildingType::None) {
                    _has_building_selected = true;
                    update_current_selected_building_position();
                }

                return;
            }
            if (event.mouseButton.button == sf::Mouse::Left && _has_building_selected)
            {
                _current_selected_building->init_time_count();
                add_building(_current_selected_building);
                deselect_current_building();
                return;
            }

            if (event.mouseButton.button == sf::Mouse::Right && _has_building_selected)
            {
                deselect_current_building();
                std::cout << "cancel\n";
                return;
            }
        }
    }
}

void Game::update_current_selected_building_position() const {
    const auto mouse_position = sf::Mouse::getPosition(_window); // Posição do mouse em relação à janela
    _current_selected_building->change_pos(Vec2(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y)));// Ajustar para centralizar o círculo
}

void Game::add_building(const std::shared_ptr<Building>& building_to_add) {
    _buildings.push_back(building_to_add);
}

void Game::deselect_current_building() {
    _current_selected_building = nullptr;
    _has_building_selected = false;
}

void Game::render_system() {
    _window.clear();

    _window.draw(*_menu.shape());
    _menu.draw_options_in_screen(&_window);

    if (_has_building_selected) {
        update_current_selected_building_position();
        _current_selected_building->draw(&_window);
    }

    for (const auto& building: _buildings) {
        building->draw(&_window);
    }
    _window.display();
}
