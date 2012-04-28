///
///\file Tile.hpp
///\brief Tile graphique au sol
///\author Matthieu637
///

#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using sf::Texture;
using sf::Sprite;


namespace cce {

class Tile : public Sprite {

public:
///
///\brief Construit une tile vide ( sans coordonnées )
///
    Tile();
    virtual ~Tile();
    
///
///\brief initialise la tile et sa position sur la carte ( afin de la dessiner )
/// 	  
///\param id : id du dessin à récupérer dans le gestionnaire de ressources
///	  x : rangé (horizontale) de la tile
///	  y : rangé (verticale) de la tile
///
    void init(int id, int x, int y);
    

public:
///
///\brief Returne l'id de l'image de la tile
///\return Returne l'id de l'image de la tile
///
    int getID() const;
    
///
///\brief Defini la texture de la tile
///\param id : id de la texture 
///
    void setImage(const int id);

///
///\brief Supprime la texture de la tile
///
    void unsetImage();
    
///
///\brief Calcul des positions de la tile par rapport à la carte entière
///
    void calculCoordonnes(const int x, const int y);

    bool contientPoint(const unsigned int x_vue, const unsigned int y_vue ) const;

private:
    int id;
    int decalage_hauteur_image;

public:
    const static unsigned int largeurTile=158;
    const static unsigned int hauteurTile=88;
private:
    // initialisé dans le cpp
    const static float hauteurSurLargeur;
    
    const static unsigned int demiLargeurTile = largeurTile / 2;
    const static unsigned int demiHauteurTile = hauteurTile / 2;
};

} /* End of namespace cce */

#endif // ASSETMANAGER_HPP
