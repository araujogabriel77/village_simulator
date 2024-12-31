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
    sf::VideoMode _window_size = sf::VideoMode(1280, 720);
    sf::RenderWindow _window;

    Vec2 _menu_size = Vec2(100, (_window_size.height - 10));
    Vec2 _menu_position = Vec2(5, 5);
    Menu _menu = Menu(_menu_size, _menu_position);
    std::string _game_name = "Village Simulator";

    bool _is_game_running = true;

    void init_window();
    void init_menu();
    void user_input_system();
    void render_system();
    // void time_system();
    // void economy_system();

public:
    Game();
    void run();
};

#endif //GAME_H
