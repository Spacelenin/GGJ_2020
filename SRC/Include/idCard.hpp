/*
** EPITECH PROJECT, 2020
** idcard
** File description:
** idcrad
*/

#ifndef idcard
#define idcard

#include "../Include/header.hpp"

class Card {
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale;
        sf::Vector2f pos;
    public:
        Card() {
            texture.loadFromFile("./Asset/pokemon_id_card.png");
            sprite.setTexture(texture);
        }

        void setPosition(float x, float y) {
            pos.x = x;
            pos.y = y;
            sprite.setPosition(pos);
        }
};

#endif /* !idcard */
