#ifndef edt_CarteEditable_hpp
#define edt_CarteEditable_hpp

#include <bib/io/IInscriptible.hpp>
#include <cce/Carte.hpp>
#include "edt/CoucheTileEditable.hpp"
#include "edt/CoucheDecorEditable.hpp"

using bib::io::IInscriptible;
using cce::Carte;

namespace edt {

class CarteEditable : public Carte, public IInscriptible {

public:
    ///
    ///\brief Construit une carte vide
    ///\param largeur : largeur en tile de la carte
    ///\param hauteur : hauteur en tile de la carte
    ///
    CarteEditable(const int &largeur, const int &hauteur);

    ///
    ///\brief Construit la carte à partir d'un fichier
    ///
    CarteEditable(const std::string& map);

    ///
    ///\brief Permet l'enregistrement successif des differents couches
    ///
    void enregistrement(EnregistreurFichier& flux) const;

    CoucheTileEditable* getCoucheTileEditable() const;

    CoucheDecorEditable* getCoucheDecorEditable() const;


private:
    ///
    ///\brief Enregistrement des ressources
    ///
    void ecrireRessources(EnregistreurFichier& flux) const;
  
    void creerCoucheTile();
    void creerCoucheDecor();

};

} /* End of namespace edt */

#endif // edt_CarteEditable_h
