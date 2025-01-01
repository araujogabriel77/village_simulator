//
// Created by Gabriel on 28/12/2024.
//

#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include <memory>
#include "Building.h"

class MenuOption {
private:
    std::shared_ptr<Building> _building;
    std::string _name;

    MenuOption(const std::shared_ptr<Building> &building, const std::string &name);

public:
    std::shared_ptr<Building> &building();

    std::string name();
};


#endif //MENU_OPTION_H
