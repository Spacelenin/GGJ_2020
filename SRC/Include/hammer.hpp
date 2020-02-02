/*
** EPITECH PROJECT, 2020
** hammer
** File description:
** hammer
*/

#ifndef hammerhead
#define hammerhead

#include "../Include/header.hpp"

class Hammer {
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale = {0.1, 0.1};
        sf::Vector2f pos;
        sf::IntRect anim[3] = {{0, 0, 520, 560}, {520, 0, 630, 560}, {1150, 0, 1500, 560}};
        int pos_anim = 0;
        bool print;
        int appear = 0;
    public:
        Hammer() {
                texture.loadFromFile("./Asset/hammersheet.png");
                sprite.setTexture(texture);
                sprite.setScale(scale);
                sprite.setTextureRect(anim[1]);
                print = false;
        }

        void setPosition(int x, int y)
        {
            pos.x = x;
            pos.y = y;
            sprite.setPosition(pos);
        }

        void animation() {
            pos_anim++;
            if (pos_anim >= 3)
                pos_anim = 0;
            sprite.setTextureRect(anim[pos_anim]);
        }
};

#endif /* !hammer */
