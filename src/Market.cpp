//
// Created by Gabriel on 30/12/2024.
//

#include "Market.h"

Market::Market(const size_t &id, const Vec2 &pos)
    : Building(id, pos) {
    initialize_shape();
    set_cost(_market_cost);
    set_rentability(_market_rentability);
    set_seconds_to_profit(_market_seconds_to_profit);
}

void Market::initialize_shape() {
    _shape = std::make_shared<sf::RectangleShape>(_market_shape_size);
    _shape->setFillColor(_market_shape_color);
    _shape->setOutlineThickness(_market_shape_outline_thickness);
    _shape->setOutlineColor(_market_outline_color);
    _shape->setPosition(_pos.x, _pos.y);
}
