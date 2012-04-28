///
///\file CoucheTile.hpp
///\brief Représente l'ensemble des Tiles au sol d'une carte
///\author matthieu637
///

#ifndef cce_CoucheTile_hpp
#define cce_CoucheTile_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <bib/io/EnregistreurFichier.hpp>
#include <bib/io/LecteurFichier.hpp>
#include "Couche.hpp"
#include "Tile.hpp"

using bib::io::LecteurFichier;
using bib::io::EnregistreurFichier;
using sf::RenderWindow;

namespace cce
{

class CoucheTile : public Couche
{

public:
///
///\brief Construit une couche vide, se créera essentiellement avec la lecture d'un stream
///
    CoucheTile ();

    virtual ~CoucheTile();
///
///\brief Calcul la position d'un Tile
///\param X : emplacement du Tile en largeur
///		  Y : emplacement du Tile en hauteur
///\return Retourne le Tile de la position
///
    Tile& getTile (const int X, const int Y ) const;

///
///\brief Defini une texture à une tile
///\param id : id de la texture
///        x,y : coordonnes de la tile
///
    void setTile(const int id, const int x, const int y);

///
///\brief Supprime la texture d'une tile
///\param x,y : coordonnes de la tile
///
    void unsetTile(const int x, const int y);

///
///\brief Remplie la couche par le flux
/// 	 format : commence après la balise [tile]
///		  nb_tile_en_largeur nb_tile_en_hauteur
///		  id_tile
///		  ...
///		  id_tile
///
///		la position des id détermine i = (y*largeur_total) + x
///		pour une tile vide il suffit de ne pas écrire d'id
///
///\param flux : flux de lecture pour le remplissage
///
    void lecture(LecteurFichier& flux);

///
///\brief Hérité de IDessinable, dessine les tiles sur la couche
///
    void dessinerSur(RenderTarget& cible);
    
    int getLargeur() const;
    int getHauteur() const;

private:
    int indiceDe(int x_vue, int y_vue) const;
    
protected:
///
///\brief Tableau de tiles
///
    Tile* tiles;
    int nbTiles;
    int largeur;
    int hauteur;
};

} /* End of namespace cce */

#endif // cce_CoucheTile_h
