#include <iostream>

#include "inventory.hpp"
#include "../constants.hpp"

// public
InventView::InventView() :
    View(INVENTORY_VIEW_ID)
    , current(0)
{

}

bool InventView::load()
{
    // loading textures
    sf::Texture background;
    if (!background.loadFromFile("assets/gui/fd_inventaire.png"))
        return false;
    this->textures.addTexture("background", background);

    sf::Texture larrow;
    if (!larrow.loadFromFile("assets/gui/fd_bouton_previous.png"))
        return false;
    this->textures.addTexture("larrow", larrow);

    sf::Texture rarrow;
    if (!rarrow.loadFromFile("assets/gui/fd_bouton_next.png"))
        return false;
    this->textures.addTexture("rarrow", rarrow);

    sf::Texture p1;
    if (!p1.loadFromFile("assets/inventory/pockets/0.png"))
        return false;
    this->textures.addTexture("pocket1", p1);

    sf::Texture p2;
    if (!p2.loadFromFile("assets/inventory/pockets/1.png"))
        return false;
    this->textures.addTexture("pocket2", p2);

    sf::Texture p3;
    if (!p3.loadFromFile("assets/inventory/pockets/2.png"))
        return false;
    this->textures.addTexture("pocket3", p3);

    sf::Texture p4;
    if (!p4.loadFromFile("assets/inventory/pockets/3.png"))
        return false;
    this->textures.addTexture("pocket4", p4);

    sf::Texture p5;
    if (!p5.loadFromFile("assets/inventory/pockets/4.png"))
        return false;
    this->textures.addTexture("pocket5", p5);

    // setting sprites
    this->sprites[this->BCKG] = sf::Sprite(this->textures.getTexture("background"));
    this->sprites[this->LARROW] = sf::Sprite(this->textures.getTexture("larrow"));
    this->sprites[this->RARROW] = sf::Sprite(this->textures.getTexture("rarrow"));
    this->sprites[this->POCKET1] = sf::Sprite(this->textures.getTexture("pocket1"));
    this->sprites[this->POCKET2] = sf::Sprite(this->textures.getTexture("pocket2"));
    this->sprites[this->POCKET3] = sf::Sprite(this->textures.getTexture("pocket3"));
    this->sprites[this->POCKET4] = sf::Sprite(this->textures.getTexture("pocket4"));
    this->sprites[this->POCKET5] = sf::Sprite(this->textures.getTexture("pocket5"));

    // setting pos
    this->sprites[this->BCKG].setPosition(20.0f, 20.0f);
    this->sprites[this->LARROW].setPosition(30.0f, 240.0f);
    this->sprites[this->RARROW].setPosition(180.0f, 240.0f);
    this->sprites[this->POCKET1].setPosition(30.0f, 30.0f);
    this->sprites[this->POCKET2].setPosition(30.0f, 30.0f);
    this->sprites[this->POCKET3].setPosition(30.0f, 30.0f);
    this->sprites[this->POCKET4].setPosition(30.0f, 30.0f);
    this->sprites[this->POCKET5].setPosition(30.0f, 30.0f);

    // texts
    if (!this->font.loadFromFile("assets/fonts/pkmnemn.ttf"))
        return false;
    this->text.setFont(this->font);
    this->text.setString("Inventaire");
    this->text.setCharacterSize(24);
    this->text.setColor(sf::Color::White);
    this->text.setPosition(WIN_W / 2 - this->text.getGlobalBounds().width / 2, 30.0f);

    this->current_pocket_name.setFont(this->font);
    this->current_pocket_name.setString("Pocket0");
    this->current_pocket_name.setCharacterSize(24);
    this->current_pocket_name.setColor(sf::Color::White);
    this->current_pocket_name.setPosition(75.0f - this->current_pocket_name.getGlobalBounds().width / 2 + 50.0f, 30.0f);

    return true;
}

void InventView::render(sf::RenderWindow& window)
{
    window.draw(this->sprites[this->BCKG]);
    window.draw(this->text);
    window.draw(this->current_pocket_name);
    window.draw(this->sprites[this->LARROW]);
    window.draw(this->sprites[this->RARROW]);
    this->draw_content(window);
}

int InventView::process_event(sf::Event& event, sf::Time elapsed)
{
    return -1;
}

void InventView::update(sf::RenderWindow& window, sf::Time elapsed)
{

}

void InventView::draw_content(sf::RenderWindow& window)
{
    window.draw(this->sprites[this->POCKET1]); // just to test
}
