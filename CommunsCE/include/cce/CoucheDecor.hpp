///
///\file CoucheDecor.hpp
///\brief Représente l'ensemble des elements de decor presents sur une map
///\author aymeric
///

#ifndef cce_CoucheDecor_hpp
#define cce_CoucheDecor_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "Couche.hpp"
#include "EltDecor.hpp"
#include "Tile.hpp"

using bib::io::LecteurFichier;
using cce::EltDecor;
using sf::RenderWindow;

namespace cce
{

class CoucheDecor :  public Couche
{
    public:

    ///
    ///\brief Construit une couche vide, se créera essentiellement avec la lecture d'un stream
    ///
        CoucheDecor ();
        virtual ~CoucheDecor ();

    ///
    ///\brief Remplie la couche par le flux
    ///\param flux : flux de lecture pour le remplissage
    ///
        void lecture(LecteurFichier& flux);

    ///
    ///\brief Dessine la couche
    ///\param
    ///
	void dessinerSur(RenderTarget& cible);

        virtual void addElt(int id, int x, int y) = 0;
        virtual void deleteElt(EltDecor& elt) = 0;

    protected :
        virtual void dessiner(RenderTarget& target) const = 0;
};

} /* End of namespace cce */

#endif // cce_CoucheDecor_hpp
