#ifndef edt_Editeur_HPP
#define edt_Editeur_HPP

#include <SFML/Graphics/View.hpp>
#include <bib/Singleton.hpp>
#include <string.h>
#include "edt/CarteEditable.hpp"

using std::string;


namespace edt {

class Editeur : public bib::Singleton<Editeur> {

    friend class bib::Singleton<Editeur>;

protected:
    Editeur();
    ~Editeur();

public:
  void init(const string& path_carte);
  void run();
  sf::View* getVueCourante();
  edt::CarteEditable* getCarteCourante();
  
private:
    sf::View* vue;
    edt::CarteEditable* carte;
    sf::RenderWindow* fenetre;
};

} /* End of namespace edt */

#endif // edt_Editeur_h
