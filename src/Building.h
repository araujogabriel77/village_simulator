//
// Created by Gabriel on 28/12/2024.
//

#ifndef BUILDING_H
#define BUILDING_H

#include<SFML/Graphics.hpp>
#include "Vec2.h"
#include <memory>

typedef std::shared_ptr<sf::RectangleShape> SharedPtrShape;

class Building {
protected:
    size_t _id = 0;
    Vec2 _pos;
    bool _active = true;
    float _balance = 0;
    float _cost = 0;
    float _rentability = 0;
    sf::Clock _clock;

    SharedPtrShape _shape = nullptr;

    Building(const size_t &id, const Vec2 &pos);

public:
    virtual ~Building() = default;

    virtual void initialize_shape() = 0;

    void update_balance();

    void change_pos(const Vec2 &pos) const;

    void change_shape_outline_thickness(const int &thickness) const;

    void change_shape_color(const sf::Color &color) const;

    void change_shape_size(const Vec2 &size) const;

    void draw(sf::RenderWindow *window) const;

    SharedPtrShape shape();

    void init_time_count();

    float get_elapsed_time() const;

    void set_cost(const float &cost);

    void set_rentability(const float &rentability);

    int id() const;

    float balance() const;

    float cost() const;

    float rentability() const;
};

#endif //BUILDING_H
