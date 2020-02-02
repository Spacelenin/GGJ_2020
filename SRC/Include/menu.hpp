#ifndef MENU
#define MENU

#include "../Include/header.hpp"

class Menu
{
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Font font;
        sf::Text play;
        sf::Text quit;
        sf::Text name;
        sf::Vector2f ppos = {350, 800};
        sf::Vector2f qpos = {1400, 800};
        sf::Vector2f npos = {375, 100};
        sf::Music music;

    Menu() {
        music.openFromFile("./Asset/menu_music.ogg");
        texture.loadFromFile("./Asset/menu_background.png");
        sprite.setTexture(texture);
        font.loadFromFile("./Asset/GOTHIC.ttf");

        play.setFont(font);
        play.setCharacterSize(60);
        play.setString("Play");
        play.setPosition(ppos);

        name.setFont(font);
        name.setCharacterSize(80);
        name.setString("Communist Repair Industries");
        name.setPosition(npos);

        quit.setFont(font);
        quit.setCharacterSize(60);
        quit.setString("Quit");
        quit.setPosition(qpos);
    }
    ~Menu() {
    }
};

class Lore
{
    public:
    sf::Text lore;
    sf::Text skip;
    sf::Font font;
    std::string Text[6] = {"You are a resident of \"The Glorious Nation\".", "Your daughter is sick but the nation has a cure.", "You will have to work hard to get it.", "Fortunately, a repair station has just become available.", "Try to do better than the old one.", ""};
    sf::Vector2f pos[6] = {{525, 200}, {525, 200}, {630, 200}, {425, 200}, {600, 200}, {0, 0}};
    sf::Vector2f spos = {800, 800};

    Lore() {
        font.loadFromFile("./Asset/GOTHIC.ttf");
        lore.setFont(font);
        lore.setString(Text[0]);
        lore.setCharacterSize(40);
        lore.setPosition(pos[0]);
        skip.setFont(font);
        skip.setString("Click to continue.");
        skip.setCharacterSize(30);
        skip.setPosition(spos);
    }
};

#endif