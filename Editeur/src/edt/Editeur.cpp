#include <cce/ImageManager.hpp>
#include "edt/GUI.hpp"
#include "edt/Editeur.hpp"


using cce::ImageManager;
using edt::GUI;
using std::string;
using sf::View;
using sf::FloatRect;

namespace edt {


Editeur::Editeur()
{

}

Editeur::~Editeur()
{

}

void Editeur::init(const string& path_carte) {

    fenetre = new sf::RenderWindow(sf::VideoMode( 1600, 900 ), "Hunters' World", sf::Style::Default );
    fenetre->setMouseCursorVisible(false);

    fenetre->setFramerateLimit(60);

    GUI::getInstance()->init();


    vue = new View(FloatRect(0,0,1600,900));
    fenetre->setView(*vue);

    carte = new CarteEditable(path_carte);
}

void Editeur::run() {

    while (fenetre->isOpen())
    {
        GUI::getInstance()->tocHorloge();

        sf::Event event;
        while (fenetre->pollEvent(event))
        {
            bool pressed;
            int x, y;
            if (GUI::getInstance()->captureEvent(event)) {
                // Décommenter pour ignorer les events utilisés par CEGUI dans SFML
                //continue;
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Right) {
                pressed = true;
                x = event.mouseButton.x;
                y = event.mouseButton.y;
            }

            if(pressed && event.type == sf::Event::MouseMoved) {
                int dx = (x - event.mouseMove.x);
                int dy = (y - event.mouseMove.y);
                if(vue->getCenter().x + dx < vue->getSize().x/2)
                    dx = 0;
                else if(vue->getCenter().x + dx > carte->getCoucheTileEditable()->getLargeur()*158 - vue->getSize().x/2 + 88)
                    dx=0;

                if(vue->getCenter().y + dy < vue->getSize().y/2)
                    dy = 0;
                else if(vue->getCenter().y + dy > carte->getCoucheTileEditable()->getHauteur()*44 - vue->getSize().y/2 + 44)
                    dy=0;

                vue->setCenter(vue->getCenter().x + dx, vue->getCenter().y + dy);

                x = event.mouseMove.x;
                y = event.mouseMove.y;
            }

            if(pressed && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Right) {
                pressed = false;
            }

            if (event.type == sf::Event::Closed) {
                fenetre->close();
            }
        }

        fenetre->clear();
        fenetre->setView(*vue);

        fenetre->pushGLStates();
        carte->dessinerSur(*fenetre);
        fenetre->popGLStates();


        GUI::getInstance()->dessiner();
        fenetre->display();
    }
}

sf::View* Editeur::getVueCourante() {
    return vue;
}

edt::CarteEditable* Editeur::getCarteCourante()
{
    return carte;
}

} /* End of namespace edt */
