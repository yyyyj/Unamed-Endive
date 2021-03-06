#ifndef DEF_VIEW
#define DEF_VIEW

#include <SFML/Graphics.hpp>
#include "../objects/messenger.hpp"

class View {
private:
    int id;

public:
    View(int);
    int getId();
    bool hasActiveHud();
    virtual bool load() = 0;
    virtual void render(sf::RenderWindow&) = 0;
    virtual int process_event(sf::Event&, sf::Time) = 0;
    virtual void update(sf::RenderWindow&, sf::Time) = 0;
};

#endif // DEF_VIEW
