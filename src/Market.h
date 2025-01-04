//
// Created by Gabriel on 30/12/2024.
//

#ifndef MARKET_H
#define MARKET_H
#include "Building.h"


class Market : public Building {
protected:
    sf::Vector2f _market_shape_size = sf::Vector2f(80, 80);
    sf::Color _market_shape_color = sf::Color::Blue;
    sf::Color _market_outline_color = sf::Color::White;
    float _market_shape_outline_thickness = 1;

    float _market_cost = 100;
    float _market_rentability = 5;
    int _market_seconds_to_profit = 2;

    void initialize_shape() override;

public:
    Market(const size_t &id, const Vec2 &pos);
};


#endif //MARKET_H
