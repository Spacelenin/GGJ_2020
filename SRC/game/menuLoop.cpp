#include "../Include/header.hpp"

void loreLoop(cr_class_t *object)
{
    sf::Event event;
    int i = 0;

    while (object->window.window.isOpen()) {
        object->window.window.clear(sf::Color::Black);
        object->window.window.draw(object->lore.lore);
        object->window.window.draw(object->lore.skip);
        object->window.window.display();
        while (object->window.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                object->window.window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                i++;
                if (i >= 5)
                    gameLoop(object);
                object->lore.lore.setString(object->lore.Text[i]);
                object->lore.lore.setPosition(object->lore.pos[i]);
            }

        }
    }
}

void do_menu_event(cr_class_t *object)
{
    sf::Event event;
    sf::FloatRect prect = {340, 800, 150, 75};
    sf::FloatRect qrect = {1380, 800, 160, 80};

    while (object->window.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || qrect.contains(event.mouseButton.x, event.mouseButton.y)) {
            object->menu.music.stop();
            object->window.window.close();
            }
        if (prect.contains(event.mouseButton.x, event.mouseButton.y)) {
            object->menu.music.stop();
            loreLoop(object);
        }

   }
}

void menuLoop(cr_class_t *object)
{
    object->menu.music.play();
    while (object->window.window.isOpen()) {
        object->window.window.clear(sf::Color::Black);
        object->window.window.draw(object->menu.sprite);
        object->window.window.draw(object->menu.play);
        object->window.window.draw(object->menu.name);
        object->window.window.draw(object->menu.quit);
        object->window.window.display();
        do_menu_event(object);
    }
}