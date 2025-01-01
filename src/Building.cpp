//
// Created by Gabriel on 28/12/2024.
//

#include "Building.h"

Building::Building(const size_t &id, const Vec2 &pos)
    : _id(id)
      , _pos(pos) {
}

void Building::change_shape_color(const sf::Color &color) const {
    _shape->setFillColor(color);
}

void Building::change_shape_outline_thickness(const int &thickness) const {
    _shape->setOutlineThickness(thickness);
}

void Building::change_shape_size(const Vec2 &size) const {
    _shape->setSize(sf::Vector2f(size.x, size.y));
}

void Building::init_time_count() {
    _clock.restart();
}

float Building::get_elapsed_time() const {
    return _clock.getElapsedTime().asSeconds();
}

void Building::set_cost(const float &cost) {
    _cost = cost;
}

void Building::set_rentability(const float &rentability) {
    _rentability = rentability;
}

void Building::set_seconds_to_profit(const int &seconds) {
    _seconds_to_profit = seconds;
}

bool Building::is_ready_to_profit() const {
    return get_elapsed_time() >= _seconds_to_profit;
}

void Building::make_money() {
    if (is_ready_to_profit()) {
        update_balance();
        init_time_count();
    }
}

void Building::update_balance() {
    _balance += _rentability;
}

void Building::change_pos(const Vec2 &pos) const {
    _shape->setPosition(pos.x, pos.y);
}

void Building::draw(sf::RenderWindow *window) const {
    window->draw(*_shape);
}

SharedPtrShape Building::shape() {
    return _shape;
}

int Building::id() const {
    return _id;
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
