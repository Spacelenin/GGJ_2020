/*
** EPITECH PROJECT, 2020
** lock
** File description:
** lock
*/

#ifndef lockh
#define lockh

#include "../Include/header.hpp"

class Padlock {
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f scale = {1.3, 1.3};
        sf::IntRect close = {130, 0, 130, 280};
        sf::IntRect open = {0, 0, 130, 280};
        int print = 6;
    public:
        Padlock() {
            texture.loadFromFile("./Asset/lock.png");
            sprite.setTexture(texture);
            sprite.setTextureRect(close);
            sprite.setScale(scale);
        }

        void unlock() {
            sprite.setTextureRect(open);
            print = 5;
        }
};

#endif /* !lock */
