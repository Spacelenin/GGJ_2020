/*
** EPITECH PROJECT, 2020
** initobject
** File description:
** initobject
*/

#include "../Include/header.hpp"

std::string toString(unsigned int nb)
{
    std::stringstream ss;
    ss << nb;
    return ss.str();
}

void init_obj(cr_class_t *object)
{
    //toaster
    object->toaster.setScale(0.5, 0.5);
    object->toaster.setPosition(130, 250);
    object->toaster.is_unlocked = true;
    //microwave
    object->microwave.setScale(0.7, 0.7);
    object->microwave.setPosition(750, 290);
    //hoven
    object->hoven.setScale(0.7, 0.7);
    object->hoven.setPosition(1340, 265);
    //freezer
    object->freezer.setScale(0.7, 0.7);
    object->freezer.setPosition(150, 680);
    //fridge
    object->fridge.setScale(0.5, 0.5);
    object->fridge.setPosition(780, 670);
    //player
    object->player.setText();
    //Card
    object->card[0].setPosition(100, 250);
    object->card[1].setPosition(700, 250);
    object->card[2].setPosition(1300,250);
    object->card[3].setPosition(100, 650);
    object->card[4].setPosition(700, 650);
    object->card[5].setPosition(1300,650);
    //Backgorund
    sf::Vector2f scale = {3.3, 2};
    object->backTexture.loadFromFile("./Asset/wall.png");
    object->backSprite.setTexture(object->backTexture);
    object->backSprite.setScale(scale);
    //Lock
    sf::Vector2f pos[5] = {{780, 150}, {1380, 150}, {180, 550}, {790, 550}, {1380, 550}};
    object->lock[0].sprite.setPosition(pos[0]);
    object->lock[1].sprite.setPosition(pos[1]);
    object->lock[2].sprite.setPosition(pos[2]);
    object->lock[3].sprite.setPosition(pos[3]);
    object->lock[4].sprite.setPosition(pos[4]);
    //Button
    object->button[0].pos.x = 390;
    object->button[0].pos.y = 485;
    object->button[0].sprite.setPosition(object->button[0].pos);
    //Button 1
    object->button[1].pos.x = 990;
    object->button[1].pos.y = 485;
    object->button[1].sprite.setPosition(object->button[1].pos);
    //Button 2
    object->button[2].pos.x = 1590;
    object->button[2].pos.y = 485;
    object->button[2].sprite.setPosition(object->button[2].pos);
    //Button 3
    object->button[3].pos.x = 390;
    object->button[3].pos.y = 885;
    object->button[3].sprite.setPosition(object->button[3].pos);
    //Button 4
    object->button[4].pos.x = 990;
    object->button[4].pos.y = 885;
    object->button[4].sprite.setPosition(object->button[4].pos);
    //Button 5
    object->button[5].pos.x = 1590;
    object->button[5].pos.y = 885;
    object->button[5].sprite.setPosition(object->button[5].pos);
    //INFO
        //txt
        object->font.loadFromFile("./Asset/GOTHIC.ttf");
        for (int i = 0; i < 6; i++) object->txtName[i].setFont(object->font);
        for (int i = 0; i < 6; i++) object->txtName[i].setCharacterSize(25);
        for (int i = 0; i < 6; i++) object->txtName[i].setPosition(object->namePos[i]);
        for (int i = 0; i < 6; i++) object->txtName[i].setString(object->name[i]);
        //nb
        object->nbValue[0] = toString(object->player.Nb_toaster);
        object->nbValue[1] = toString(object->player.Nb_microwave);
        object->nbValue[2] = toString(object->player.Nb_hoven);
        object->nbValue[3] = toString(object->player.Nb_fridge);
        object->nbValue[4] = toString(object->player.Nb_freezer);
        for (int i = 0; i < 6; i++) object->txtNB[i].setFont(object->font);
        for (int i = 0; i < 6; i++) object->txtNB[i].setCharacterSize(25);
        for (int i = 0; i < 5; i++) object->txtNB[i].setString(object->nbValue[i]);
        object->txtNB[5].setString("Disable");
        for (int i = 0; i < 6; i++) object->txtNB[i].setPosition(object->nbPos[i]);
}