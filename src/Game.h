//
// Created by Gabriel on 31/12/2024.
//

#ifndef GAME_H
#define GAME_H
#include <memory>

#include "Menu.h"

class Game {
protected:
    int _frame_limit = 30;
    bool _vertical_sync_enabled = true;
    sf::VideoMode _window_size = sf::VideoMode(1024, 600);
    sf::RenderWindow _window;

    Vec2 _menu_size = Vec2(100, static_cast<float>(_window_size.height - 10));
    Vec2 _menu_position = Vec2(5, 5);
    Menu _menu = Menu(_menu_size, _menu_position);
    std::string _game_name = "Village Simulator";

    std::string _font_path = "../assets/fonts/Roboto/Roboto-Regular.ttf";
    sf::Font _font;
    float _total_coins = 0;
    sf::Text _total_coins_text = sf::Text('0', _font);

    bool _is_game_running = true;
    float _draw_area_x = (_window_size.width - _menu_size.x - 30);
    float _draw_area_y = (_window_size.height - 110);
    sf::RectangleShape _draw_area = sf::RectangleShape(sf::Vector2f(_draw_area_x, _draw_area_y));

    // ID RESERVADO PARA A CONSTRUÇÃO SELECIONADA
    int _current_selected_building_id = 1;
    bool _has_building_selected = false;
    std::shared_ptr<Building> _current_selected_building = nullptr;
    std::vector<std::shared_ptr<Building>> _buildings;

    void init_window();
    void init_draw_area();
    void set_text_config();
    void user_input_system();
    void render_system();
    void update_current_selected_building_position() const;
    void deselect_current_building();
    void draw_points();
    void draw_buildings();
    void draw_menu();
    void draw_current_selected_building();
    void update_economy();

    bool check_if_is_inside_draw_area(const Vec2& origin) const;

    void add_building(const std::shared_ptr<Building>& building_to_add);
    void remove_building();

public:
    Game();
    void run();
};

#endif //GAME_H
