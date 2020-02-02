/*
** EPITECH PROJECT, 2020
** buttonh
** File description:
** buttonh
*/

#ifndef buttonh
#define buttonh

#include "../Include/header.hpp"

class Button {
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
        sf::Vector2f scale = {0.6, 0.3};
        sf::IntRect rect[2] = {{0, 0, 340, 161}, {345, 0, 340, 161}};
        sf::Vector2f saveMouse;
        sf::IntRect buttonPos[6] = {{390, 485, 200, 50}, {990, 485, 200, 50}, {1590, 485, 200, 50}, {390, 885, 200, 50}, {990, 885, 200, 50}, {1590, 885, 200, 50}};
        int clicked = 6;
    public:
        Button() {
            texture.loadFromFile("./Asset/button.png");
            sprite.setTexture(texture);
            sprite.setTextureRect(rect[0]);
            sprite.setScale(scale);
        }

        void click() {
            clicked = 5;
            sprite.setTextureRect(rect[1]);
        }
};

#endif /* !buttonh */
