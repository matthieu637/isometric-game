#include <iostream>
#include "cce/ImageManager.hpp"
#include "cce/Tile.hpp"

namespace cce {

const float Tile::hauteurSurLargeur = (float) Tile::hauteurTile / Tile::largeurTile;

Tile::Tile() : Sprite()
{
}

void Tile::init(int _id, int x, int y)
{
    setImage(_id);
    calculCoordonnes(x,y);
}


Tile::~Tile(void)
{

}

int Tile::getID() const
{
    return id;
}

void Tile::setImage(const int _id)
{
    id=_id;
    setTexture(ImageManager::getInstance()->get_asset(id));
}

void Tile::unsetImage()
{
    id= -1;
    //TODO: retirer tile
}

void Tile::calculCoordonnes(const int x, const int y)
{
    //calcul de la position d'affichage sur l'écran
    int xOnScreen, yOnScreen;
    int ligne = y/2;

    xOnScreen = x*largeurTile;
    yOnScreen = ligne*hauteurTile;

    //retire un peu de hauteur pour les tiles qui dépasse la hauteur conforme ( brins d'herbe , ...)
    decalage_hauteur_image = (getTexture()->getSize().y - hauteurTile);
    yOnScreen -= decalage_hauteur_image;

    //décalage d'une rangé sur 2
    if (y % 2 ==0)
        setPosition(xOnScreen, yOnScreen);
    else {
        //rangé décalé
        xOnScreen += demiLargeurTile;
        yOnScreen += demiHauteurTile;

        setPosition(xOnScreen, yOnScreen);
    }


#ifndef NDEBUG
    //std::cout << "read id : " << _id << " x : " << x<< " y : " << y << "\t\t";
    //std::cout << "write coord x : " << GetPosition().x << " y : " << GetPosition().y << std::endl;
#endif

}

bool Tile::contientPoint(const unsigned int x_vue, const unsigned int y_vue ) const
{
    unsigned int x0 = getPosition().x;
    unsigned int y0 = getPosition().y + decalage_hauteur_image;

    //verifie que le point est bien dans le rectangle
    if (x_vue < x0 || x_vue > x0 + largeurTile || y_vue < y0 || y_vue > y0 + hauteurTile)
        return false;
    else
        if (y_vue <= y0 + demiHauteurTile )
            if (x_vue <= x0 + demiLargeurTile )
                //triangle haut gauche
                return ((y0 + demiHauteurTile) - y_vue) <= (float)(hauteurSurLargeur*(x_vue-x0));
            else
                //triangle haut droite
                return (int)(y0 - y_vue) <= - (float)( hauteurSurLargeur*(x_vue - x0 -demiLargeurTile) )  ;
        else
            if (x_vue <= x0 + demiLargeurTile )
                //triangle bas gauche
                return ((int)(y0 + demiHauteurTile - y_vue)) >= (- (float)(hauteurSurLargeur * (x_vue-x0)) );
            else
                //triangle bas droite
                return (y0 + hauteurTile - y_vue) >= (float)(hauteurSurLargeur *(x_vue-demiLargeurTile-x0));

    /*
    std::cout << "x : " << x_vue << "   y : " << y_vue << "      x0 : " << x0 << "   y0 :" << y0 << std::endl;
    std::cout << "current : " << ((y0 + hauteurTile - y_vue)) <<" want : " << ((float)(hauteurSurLargeur *(x_vue-demiLargeurTile-x0))) << std::endl;
    */
}

}
