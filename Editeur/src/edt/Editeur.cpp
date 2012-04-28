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
    fenetre->ShowMouseCursor(false);
    
    fenetre->SetFramerateLimit(60);

    GUI::getInstance()->init();


    vue = new View(FloatRect(0,0,1600,900));
    fenetre->SetView(*vue);

    carte = new CarteEditable(path_carte);
}

void Editeur::run() {

    while (fenetre->IsOpened())
    {
        GUI::getInstance()->tocHorloge();

        sf::Event Event;
        while (fenetre->PollEvent(Event))
        {

            if (GUI::getInstance()->captureEvent(Event)) {
                // Décommenter pour ignorer les events utilisés par CEGUI dans SFML
                //continue;
            }


            if (Event.Type == sf::Event::Closed){
                fenetre->Close();
            }
        }

        fenetre->Clear();
        fenetre->SetView(*vue);
        carte->dessinerSur(*fenetre);

        GUI::getInstance()->dessiner();
        fenetre->Display();
    }
}

sf::View* Editeur::getVueCourante(){
  return vue;
}

edt::CarteEditable* Editeur::getCarteCourante()
{
 return carte; 
}

} /* End of namespace edt */
