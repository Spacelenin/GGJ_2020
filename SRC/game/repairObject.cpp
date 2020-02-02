/*
** EPITECH PROJECT, 2020
** repair
** File description:
** repairObject
*/

#include "../Include/repairObject.hpp"

void Machine::unlock_this(cr_class_t *obj)
{
    if ((obj->machine.is_unlocked == false) && (obj->player.getGold() >= obj->machine.getPrice())) {
        this->is_unlocked = true;
        obj->player.costGold(obj->machine.getPrice());
    } else {
        std::cout << "DEBUG -- Sorry you haven't enough money to buy this one ;)" << std::endl;
    }
}