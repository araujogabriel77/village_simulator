//
// Created by Gabriel on 28/12/2024.
//

#include "Menu.h"

#include <iostream>
#include <memory>

#include "House.h"
#include "Market.h"

Menu::Menu(const Vec2 size, const Vec2 position)
    : _size(size), _position(position) {
    setOptions();
    setShape();
}

void Menu::setOptions() {
    for (int i = 0; i < _building_names.size(); i++) {
        auto building_name = _building_names[i];
        const auto gap = i > 0 ? _options_gap : 20;
        const auto initial_x_pos = (_size.x / 2) - (_option_size.x /2 );
        const int new_y_position = (_option_size.y * i) + gap;
        auto position = Vec2(initial_x_pos, new_y_position);
        _options.insert(std::pair<std::string, Vec2>(building_name, position));

        if (building_name == "House") {
            auto house = std::make_shared<House>(i, position);
            house->change_shape_size(_option_size);
            _option_shapes.push_back(house);
        } else if (building_name == "Market") {
            auto market = std::make_shared<Market>(i, position);
            market->change_shape_size(_option_size);
            _option_shapes.push_back(market);
        }
    }
}

void Menu::setShape() {
    _shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(_size.x, _size.y));
    _shape->setPosition(sf::Vector2f(_position.x, _position.y));
    _shape->setFillColor(_menu_color);
    _shape->setOutlineColor(_menu_outline_color);
    _shape->setOutlineThickness(_menu_outline_thickness);
}

Vec2 Menu::size() {
    return _size;
}

Vec2 Menu::position() {
    return _position;
}

std::shared_ptr<sf::Shape> Menu::shape() {
    return _shape;
}

void Menu::clear_option() {
    _options.clear();
}

std::map<std::string, Vec2> &Menu::options() {
    return _options;
}

bool Menu::option_has_selected(const Vec2 &origin) {
    for (const auto &[building_name, position]: _options) {
        const int x1 = position.x;
        const int x2 = position.x + _option_size.x;
        const int y1 = position.y;
        const int y2 = position.y + _option_size.y;

        const auto point_is_insde = origin.x >= x1 && origin.x <= x2 && origin.y >= y1 && origin.y <= y2;
        if (point_is_insde) {
            return true;
        }
    }
    return false;
}

void Menu::draw_options_in_screen(sf::RenderWindow *window) {
    for (const auto &option_shape: _option_shapes) {
        window->draw(*option_shape->shape());
    }
}
