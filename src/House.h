//
// Created by Gabriel on 28/12/2024.
//

#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"


class House : public Building {
protected:
    sf::Vector2f _house_shape_size = sf::Vector2f(50, 50);
    sf::Color _house_shape_color = sf::Color::Green;
    sf::Color _house_outline_color = sf::Color::White;
    float _house_shape_outline_thickness = 1;

    float _house_cost = 30;
    float _house_rentability = 2;
    float _house_seconds_to_profit = 2;

    void initialize_shape() override;

public:
    House(const size_t &id, const Vec2 &pos);
};


#endif //HOUSE_H
