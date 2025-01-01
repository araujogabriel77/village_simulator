//
// Created by Gabriel on 28/12/2024.
//

#include "House.h"


House::House(const size_t &id, const Vec2 &pos)
    : Building(id, pos) {
    initialize_shape();
    set_cost(_house_cost);
    set_rentability(_house_rentability);
    set_seconds_to_profit(_house_seconds_to_profit);
}

void House::initialize_shape() {
    _shape = std::make_shared<sf::RectangleShape>(_house_shape_size);
    _shape->setFillColor(_house_shape_color);
    _shape->setOutlineThickness(_house_shape_outline_thickness);
    _shape->setOutlineColor(_house_outline_color);
    _shape->setPosition(_pos.x, _pos.y);
}
