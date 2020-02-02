/*
** EPITECH PROJECT, 2020
** window header
** File description:
** window header
*/

#ifndef windowheader
#define windowheader

#include "../Include/header.hpp"

class wind {
    public:
        sf::RenderWindow window;
    public:
        wind() {
            window.create(sf::VideoMode(1920, 1080), "Our game");
            window.setFramerateLimit(60);
        }
};

#endif /* !windowheader */
