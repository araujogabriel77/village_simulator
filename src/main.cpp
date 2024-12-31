#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Menu.h"
int main() {
    auto game = Game();
    game.run();
}
