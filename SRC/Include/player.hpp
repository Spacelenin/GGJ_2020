/*
** EPITECH PROJECT, 2020
** player class
** File description:
** player class
*/

#ifndef playerclass
#define playerclass

#include "../Include/header.hpp"


class Player {
    public:
        std::string name;
        unsigned long long _Gold = 0;
        unsigned int Nb_toaster = 0;
        unsigned int Nb_microwave = 0;
        unsigned int Nb_hoven = 0;
        unsigned int Nb_fridge = 0;
        unsigned int Nb_freezer = 0;

        int _gain_toaster = 1;
        int _gain_microwave = 10;
        int _gain_hoven = 100;
        int _gain_fridge = 10000;
        int _gain_freezer = 1000000;
    public:
        sf::Text TxtName;
        sf::Font font;
    public:
        Player() {
            name = "Archange";
        }
        void Click();

        void setText() {
            font.loadFromFile("./Asset/GOTHIC.ttf");
            TxtName.setFont(font);
            TxtName.setCharacterSize(30);
            TxtName.setString(name);
        }

        std::string getName()
        {
            return (this->name);
        }

        void setName(std::string name)
        {
            this->name = name;
        }

        unsigned int getGold()
        {
            return (this->_Gold);
        }

        void setGold(unsigned long long nb)
        {
            this->_Gold = nb;
        }

        void addGold(unsigned long long nb)
        {
            this->_Gold += nb;
        }

        void costGold(unsigned long long nb)
        {
            this->_Gold -= nb;
        }

};

#endif /* !playerclass */
