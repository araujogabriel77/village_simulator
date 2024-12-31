//
// Created by Gabriel on 28/12/2024.
//

#include "MenuOption.h"


MenuOption::MenuOption(const std::shared_ptr<Building> &building, const std::string &name)
    : _building(building), _name(name) {
}

std::shared_ptr<Building> &MenuOption::building() {
    return _building;
}

std::string MenuOption::name() {
    return _name;
}
