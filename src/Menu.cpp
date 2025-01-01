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
    for (int i = 0; i < _building_types.size(); i++) {
        auto building_type = _building_types[i];
        const auto gap = i > 0 ? _options_gap : 20;
        const auto initial_x_pos = (_size.x / 2) - (_option_size.x / 2);
        const int new_y_position = (_option_size.y * i) + gap;
        auto position = Vec2(initial_x_pos, new_y_position);
        _options.insert(std::pair<BuildingType, Vec2>(building_type, position));

        switch (building_type) {
            case BuildingType::House: {
                auto house = std::make_shared<House>(i, position);
                house->change_shape_size(_option_size);
                _option_shapes.push_back(house);
                break;
            }
            case BuildingType::Market: {
                auto market = std::make_shared<Market>(i, position);
                market->change_shape_size(_option_size);
                _option_shapes.push_back(market);
                break;
            }
            default:
                break;
        }
        // if (building_type == BuildingType::House) {
        //     auto house = std::make_shared<House>(i, position);
        //     house->change_shape_size(_option_size);
        //     _option_shapes.push_back(house);
        // } else if (building_type == "Market") {
        //     auto market = std::make_shared<Market>(i, position);
        //     market->change_shape_size(_option_size);
        //     _option_shapes.push_back(market);
        // }
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

std::map<BuildingType, Vec2> &Menu::options() {
    return _options;
}

BuildingType Menu::get_selected_option_building_type(const Vec2 &origin) {
    for (const auto &[building_name, position]: _options) {
        const int x1 = position.x;
        const int x2 = position.x + _option_size.x;
        const int y1 = position.y;
        const int y2 = position.y + _option_size.y;

        const auto point_is_insde = origin.x >= x1 && origin.x <= x2 && origin.y >= y1 && origin.y <= y2;
        if (point_is_insde) {
            return building_name;
        }
    }

    return BuildingType::None;
}

void Menu::draw_options_in_screen(sf::RenderWindow *window) {
    for (const auto &option_shape: _option_shapes) {
        window->draw(*option_shape->shape());
    }
}
