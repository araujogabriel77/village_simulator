//
// Created by Gabriel on 28/12/2024.
//

#include "Building.h"

Building::Building(const size_t &id, const Vec2 &pos)
    : _id(id)
      , _pos(pos) {
}

void Building::change_shape_color(const sf::Color &color) {
    _shape->setFillColor(color);
}

void Building::change_shape_outline_thickness(const int &thickness) {
    _shape->setOutlineThickness(thickness);
}

void Building::change_shape_size(const Vec2 &size) {
    _shape->setSize(sf::Vector2f(size.x, size.y));
}

void Building::set_cost(const float &cost) {
    _cost = cost;
}

void Building::set_rentability(const float &rentability) {
    _rentability = rentability;
}

void Building::update_balance() {
    _balance += _rentability;
}

void Building::change_pos(const Vec2 &pos) {
    _pos = pos;
}

SharedPtrShape Building::shape() {
    return _shape;
}

float Building::balance() const {
    return _balance;
}

float Building::cost() const {
    return _cost;
}

float Building::rentability() const {
    return _rentability;
}
