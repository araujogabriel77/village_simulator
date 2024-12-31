//
// Created by Gabriel on 30/12/2024.
//

#include "Market.h"

Market::Market(const size_t &id, const Vec2 &pos)
    : Building(id, pos) {
    initialize_shape();
    set_cost(_market_cost);
    set_rentability(_market_rentability);
}

void Market::initialize_shape() {
    const auto shape = std::make_shared<sf::RectangleShape>(_market_shape_size);
    shape->setFillColor(_market_shape_color);
    shape->setOutlineThickness(_market_shape_outline_thickness);
    shape->setOutlineColor(_market_outline_color);
    shape->setPosition(_pos.x, _pos.y);
    _shape = shape;
}
