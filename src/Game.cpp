//
// Created by Gabriel on 31/12/2024.
//

#include "Game.h"
#include <iostream>

#include "House.h"
#include "Market.h"


Game::Game() {
    set_text_config();
    init_window();
    init_draw_area();
}

void Game::init_window() {
    _window.create(_window_size, _game_name);
    _window.setFramerateLimit(_frame_limit);
    _window.setVerticalSyncEnabled(_vertical_sync_enabled);
}

void Game::init_draw_area() {
    _draw_area.setPosition(_menu_size.x + 15, 100);
    _draw_area.setOutlineThickness(2);
    _draw_area.setFillColor(sf::Color::White);
    _draw_area.setOutlineColor(sf::Color::Cyan);
}

void Game::run() {
    while (_is_game_running) {
        user_input_system();
        render_system();
        update_economy();
    }
}

void Game::user_input_system() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _is_game_running = false;
        if (event.type == sf::Event::MouseButtonPressed) {
            const auto mouse_origin = Vec2(static_cast<float>(event.mouseButton.x),
                                           static_cast<float>(event.mouseButton.y));
            if (event.mouseButton.button == sf::Mouse::Left && !_has_building_selected) {
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
            if (event.mouseButton.button == sf::Mouse::Left && _has_building_selected) {
                if (!check_if_is_inside_draw_area(mouse_origin)) return;
                _current_selected_building->init_time_count();
                add_building(_current_selected_building);
                deselect_current_building();
                return;
            }

            if (event.mouseButton.button == sf::Mouse::Right && _has_building_selected) {
                deselect_current_building();
                std::cout << "cancel\n";
                return;
            }
        }
    }
}

bool Game::check_if_is_inside_draw_area(const Vec2 &origin) const {
    const int x1 = _draw_area.getPosition().x;
    const int x2 = _draw_area.getPosition().x + _draw_area.getSize().x;
    const int y1 = _draw_area.getPosition().y;
    const int y2 = _draw_area.getPosition().y + _draw_area.getSize().y;

    const auto is_insde = origin.x >= x1 && origin.x <= x2 && origin.y >= y1 && origin.y <= y2;

    const auto selected_building_size = _current_selected_building->size();

    const auto is_not_trespassing = (origin.x + selected_building_size.x) >= x1 && (origin.x + selected_building_size.x) <=
                                x2 && (origin.y + selected_building_size.y) >= y1 && (
                                    origin.y + selected_building_size.y) <= y2;

    return is_insde && is_not_trespassing;
}

void Game::update_current_selected_building_position() const {
    const auto mouse_position = sf::Mouse::getPosition(_window);
    _current_selected_building->change_pos(Vec2(static_cast<float>(mouse_position.x),
                                                static_cast<float>(mouse_position.y)));
}

void Game::add_building(const std::shared_ptr<Building> &building_to_add) {
    _buildings.push_back(building_to_add);
}

void Game::deselect_current_building() {
    _current_selected_building = nullptr;
    _has_building_selected = false;
}

void Game::set_text_config() {
    _font.loadFromFile(_font_path);
    _total_coins_text.setPosition(((_draw_area_x / 2) + (_draw_area.getPosition().x + 100)), 10);
    _total_coins_text.setCharacterSize(30);
    _total_coins_text.setStyle(sf::Text::Bold);
    _total_coins_text.setFillColor(sf::Color::Yellow);
}

void Game::draw_points() {
    const auto text = std::to_string(static_cast<int>(_total_coins));
    _total_coins_text.setString(text);
    _window.draw(_total_coins_text);
}

void Game::update_economy() {
    for (const auto &building: _buildings) {
        const auto previous_balance = building->balance();
        building->make_money();
        if (previous_balance < building->balance()) {
            _total_coins += building->rentability();
        }
    }
}

void Game::draw_buildings() {
    for (const auto &building: _buildings) {
        building->draw(&_window);
    }
}

void Game::draw_menu() {
    _window.draw(*_menu.shape());
    _menu.draw_options_in_screen(&_window);
}

void Game::draw_current_selected_building() {
    if (_has_building_selected) {
        update_current_selected_building_position();
        _current_selected_building->draw(&_window);
    }
}

void Game::render_system() {
    _window.clear();

    _window.draw(_draw_area);
    draw_menu();
    draw_current_selected_building();
    draw_buildings();
    draw_points();
    _window.display();
}
