cmake_minimum_required(VERSION 3.30)
project(village_simulator)

include(FetchContent)
set(BUILD_SHARED_LIBS off)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.2)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)
add_executable(village_simulator src/main.cpp
        src/components.h
        src/vec2.cpp
        src/vec2.h
        src/MenuOption.cpp
        src/MenuOption.h
        src/Menu.cpp
        src/Menu.h
        src/Building.cpp
        src/Building.h
        src/House.cpp
        src/House.h
        src/Market.cpp
        src/Market.h
        src/Game.cpp
        src/Game.h
)

target_link_libraries(village_simulator sfml-graphics sfml-audio sfml-window sfml-system)


