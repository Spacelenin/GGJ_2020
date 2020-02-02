/*
** EPITECH PROJECT, 2020
** headprinc
** File description:
** headprinc
*/

#ifndef headprinc
#define headprinc

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "window.hpp"
#include "hammer.hpp"
#include "player.hpp"
#include "repairObject.hpp"
#include "idCard.hpp"
#include "menu.hpp"
#include "lock.hpp"
#include "button.hpp"

typedef struct cr_class_s {
    //Window
    wind window;
    //differentes classes
    Hammer hammer;
    Machine machine;
    Toaster toaster;
    Microwave microwave;
    Hoven hoven;
    Fridge fridge;
    Freezer freezer;
    Lore lore;
    Card card[6];
    Player player;
    Menu menu;
    Button button[6];
    //Lock
    Padlock lock[5];
    //game background
    sf::Texture backTexture;
    sf::Sprite backSprite;
    //Clock
        sf::Clock hamClock;
        sf::Time haminterval = sf::seconds(0.1);
        sf::Time hamtime;
        //Object repair clock
        sf::Clock objClock;
        //fair un tableau avec le nombre d'objets
        sf::Time objinter = sf::seconds(0.7);
        sf::Time objtime;
        //Clock button
        sf::Clock butClock;
        sf::Time butinterval = sf::seconds(0.5);
        sf::Time buttime;
        //Clock lock
        sf::Clock lockClock;
        sf::Time lockinterval = sf::seconds(0.5);
        sf::Time locktime;
    //Info
        sf::Font font;
        sf::Text txtName[6];
        std::string name[6] = {"Toaster", "Microwave", "Hoven", "Fridge", "Freezer", "Auto-Click"};
        sf::Vector2f namePos[6] = {{400, 293}, {1000, 293}, {1600, 293}, {400, 692}, {1000, 692}, {1600, 692}};
    //Nb of thing
        sf::Text txtNB[6];
        std::string nbValue[5];
        sf::Vector2f nbPos[6] = {{400, 365}, {1000, 365}, {1600, 365}, {400, 765}, {1000, 765}, {1600, 765}};

}cr_class_t;

void init_obj(cr_class_t *object);
void gameLoop(cr_class_t *object);

#endif /* !headprinc */
