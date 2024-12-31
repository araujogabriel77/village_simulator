//
// Created by Gabriel on 28/12/2024.
//

#ifndef MENU_H
#define MENU_H
#include "MenuOption.h"

class Menu {
private:
    std::vector<std::string> _building_names = {"House", "Market"};
    std::map<std::string, Vec2> _options;
    std::vector<std::shared_ptr<Building> > _option_shapes;
    Vec2 _option_size = Vec2(50, 50);

    std::shared_ptr<sf::RectangleShape> _shape;
    Vec2 _size;
    Vec2 _position;
    sf::Color _menu_color = sf::Color::Transparent;
    sf::Color _menu_outline_color = sf::Color::Red;
    int _menu_outline_thickness = 2;
    int _options_gap = 50;

    void setOptions();

    void setShape();

public:
    Menu(Vec2 size, Vec2 position);

    Vec2 size();

    Vec2 position();

    std::map<std::string, Vec2> &options();

    std::shared_ptr<sf::Shape> shape();

    void clear_option();

    void draw_options_in_screen(sf::RenderWindow *window);

    bool option_has_selected(const Vec2 &origin);
};

#endif //MENU_H