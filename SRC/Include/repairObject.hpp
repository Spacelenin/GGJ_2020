/*
** EPITECH PROJECT, 2020
** repair
** File description:
** repair
*/

#ifndef repair
#define repair

#include "header.hpp"

typedef struct cr_class_s cr_class_t;

class Machine {
    public:
        //Texture
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f scale;
        sf::Vector2f pos;
        sf::Text name;
        //Attributs
        std::string nameValue;
        bool autoRepair = false;
        int speedauto;
        int earning;
        int timeRepair;
        bool is_unlocked = false;

    public:
        Machine() {
        }

        ~Machine() = default;

        void setScale(float x, float y) {
            scale.x = x;
            scale.y = y;
            sprite.setScale(scale);
        }

        void setPosition(float x, float y) {
            pos.x = x;
            pos.y = y;
            sprite.setPosition(pos);
        }

        void earningUp(int up) {
            earning += up;
        }

        void changeText(std::string text1, std::string text2, float value)
        {
            std::stringstream ss;
            ss << value;
            ss.str();
        }

        void unlock_this(cr_class_t *obj);

        int _price;

        int getPrice()
            {
                return (this->_price);
            }
};

class Toaster : public Machine
{
    public:
        int getPrice()
            {
                return (this->_price);
            }
        Toaster() {
            texture.loadFromFile("./Asset/toaster.png");
            sprite.setTexture(texture);
        }
    protected:
        int _price = 10;
};

class Microwave : public Machine
{
    public:
        int getPrice()
            {
                return (this->_price);
            }
        Microwave() {
            texture.loadFromFile("./Asset/microwave.png");
            sprite.setTexture(texture);
        }
    protected:
        int _price = 100;
};

class Hoven : public Machine
{
    public:
        Hoven() {
            texture.loadFromFile("./Asset/hoven.png");
            sprite.setTexture(texture);
        }
        int getPrice()
            {
                return (this->_price);
            }
    protected:
        int _price = 10000;
};

class Fridge : public Machine {
    public:
        Fridge() {
            texture.loadFromFile("./Asset/fridge.png");
            sprite.setTexture(texture);
        }
        int getPrice()
            {
                return (this->_price);
            }
    protected:
        int _price = 1000000;
};

class Freezer : public Machine {
    public:
        Freezer() {
            texture.loadFromFile("./Asset/freezer.png");
            sprite.setTexture(texture);
        }
        int getPrice()
            {
                return (this->_price);
            }
    protected:
        int _price = 100000000;
};

#endif /* !repair */
