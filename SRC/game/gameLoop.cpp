/*
** EPITECH PROJECT, 2020
** gameloop
** File description:
** gameloop
*/

#include "../Include/header.hpp"
#include "../Include/player.hpp"

void do_things(cr_class_t *object)
{
    if (object->hamtime > object->haminterval) {
        object->hammer.animation();
        object->hamClock.restart();
    }
    if (object->objtime > object->objinter) {
        if (object->hammer.appear != 0)
            object->hammer.appear--;
        object->objClock.restart();
    }
}

void draw(cr_class_t *object)
{
    object->window.window.draw(object->backSprite);
    for (int i = 0; i < 6; i++) object->window.window.draw(object->card[i].sprite);
    //Object
    object->window.window.draw(object->player.TxtName);
    object->window.window.draw(object->toaster.sprite);
    object->window.window.draw(object->microwave.sprite);
    object->window.window.draw(object->hoven.sprite);
    object->window.window.draw(object->fridge.sprite);
    object->window.window.draw(object->freezer.sprite);
    for (int i = 0; i < 6; i++) object->window.window.draw(object->txtName[i]);
    for (int i = 0; i < 6; i++) object->window.window.draw(object->txtNB[i]);
    if (object->hammer.appear > 0) object->window.window.draw(object->hammer.sprite);
}

void hammerBam(cr_class_t *object)
{
    object->hammer.appear = 2;
    object->hammer.sprite.setPosition(object->hammer.pos);
}

void drawLocks(cr_class_t *object)
{
    //Lock
    for (int i = 0; i < 5; i++) {
        if (object->lock[i].print <= 6 && object->lock[i].print != 0) {
            object->window.window.draw(object->lock[i].sprite);
            if (object->locktime > object->lockinterval) {
                object->lock[i].print--;
                if (object->lock[i].print == 0) object->lock[i].print = 6;
                object->lockClock.restart();
            }
        }
    }
}

void clickButton(cr_class_t *object)
{
    for (int i = 0; i < 6; i++) {
        if (object->button[i].buttonPos[i].contains(object->button[i].saveMouse.x, object->button[i].saveMouse.y))
            object->button[i].click();
    }
}

void drawButton(cr_class_t *object)
{
    for (int i = 0; i < 6; i++) {
        if (object->button[i].clicked <= 6 && object->button[i].clicked != 0) {
            object->window.window.draw(object->button[i].sprite);
            if (object->buttime > object->butinterval) {
                object->button[i].clicked--;
                if (object->button[i].clicked == 0) {
                    object->button[i].clicked = 6;
                    object->button[i].sprite.setTextureRect(object->button[i].rect[0]);
                }
                object->butClock.restart();
            }
        }
    }
}

void gameLoop(cr_class_t *object)
{
    sf::Event event;

    while (object->window.window.isOpen()) {
        //event
        while (object->window.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) object->window.window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                object->hammer.pos.x = event.mouseButton.x -20;
                object->hammer.pos.y = event.mouseButton.y -25;
                std::cout << "POSITION X: " << event.mouseButton.x <<" Y: " << event.mouseButton.y << std::endl;
                hammerBam(object);
                for (int i = 0; i < 6; i++) {
                    object->button[i].saveMouse.x = event.mouseButton.x;
                    object->button[i].saveMouse.y = event.mouseButton.y;
                }
                clickButton(object);
                object->player.Click();
            }
        }

        //clock
        object->hamtime = object->hamClock.getElapsedTime();
        object->objtime = object->objClock.getElapsedTime();
        object->buttime = object->butClock.getElapsedTime();
        object->locktime = object->lockClock.getElapsedTime();

        //draw
        object->window.window.clear(sf::Color(200, 200, 255, 255));

        //draw
        do_things(object);
        draw(object);
        drawLocks(object);
        drawButton(object);

        //display
        object->window.window.display();
    }
}

void Player::Click()
{
    unsigned long long gain = 1;

    gain += (Nb_toaster * _gain_toaster); std::cout << Nb_toaster * _gain_toaster << std::endl;
    gain += (Nb_microwave * _gain_microwave); std::cout << Nb_microwave * _gain_microwave << std::endl;
    gain += (Nb_hoven * _gain_hoven); std::cout << Nb_hoven * _gain_hoven << std::endl;
    gain += (Nb_fridge * _gain_fridge); std::cout << Nb_fridge * _gain_fridge << std::endl;
    gain += (Nb_freezer * _gain_freezer); std::cout << Nb_freezer * _gain_freezer << std::endl;

    this->addGold(gain);
    std::cout << "DEBUG --" << gain << "-- Money earned DEBUG" << std::endl;
    std::cout << "DEBUG --" << this->getGold() << "-- Money TOTAL DEBUG" << std::endl;
}