#include <iostream>
#include "cce/CoucheTile.hpp"

using sf::Vector2f;
using cce::Tile;

namespace cce {


CoucheTile::CoucheTile()
{
    tiles = NULL;
}

CoucheTile::~CoucheTile() {

}

Tile& CoucheTile::getTile(const int x, const int y) const
{
    return tiles[y*largeur+x];
}

void CoucheTile::setTile(const int id, const int x, const int y)
{
    Tile t = getTile(x,y);
    t.setImage(id);
    t.calculCoordonnes(x,y);
}

void CoucheTile::unsetTile(const int x, const int y)
{
    getTile(x,y).unsetImage();
}

void CoucheTile::lecture(LecteurFichier& flux) {

    flux.allerSection("tiles");
    largeur = flux.lireInt();
    hauteur = flux.lireInt();
    flux.prochaineLigne();

    nbTiles = largeur * hauteur;
    tiles = new Tile[nbTiles];

    int x = 0 ;
    int y = 0 ;
    Tile *total = tiles + nbTiles;

    for (Tile *p = tiles; p < total ;p++) {
        if (x>= largeur) {
            y++;
            x=0;
        }

        int id = flux.lireIntVidePossible();
        if (id != -1)
            (*p).init(id,x,y);
        else
            (*p).unsetImage();
        //std::cout << id << std::endl;
        flux.prochaineLigne();
        x++;
    }

}

int CoucheTile::indiceDe(const int x_vue, const int y_vue) const {
    int x = x_vue/158;
    int y = y_vue/88;

    int indice = (y*2)*largeur+x;
    if (tiles[indice].contientPoint(x_vue, y_vue))
        return indice;


    x = (x_vue - 79) / 158;
    y = (y_vue - 44) / 88;
    int indiceDecale = (y*2)*largeur+x + largeur;
    if (tiles[indiceDecale].contientPoint(x_vue, y_vue))
        return indiceDecale;

    std::cout << "ERROR : impossible de trouver la tile du point (" << x_vue << ", " << y_vue << ") " << std::endl;

    if (indice > 0 && indice < hauteur*largeur)
        return indice;
    else return 0;
}


void CoucheTile::dessinerSur(RenderTarget& cible) {

    Vector2f centre =  cible.getView().getCenter();
    const Vector2f taille =  cible.getView().getSize();

    int gauche = centre.x - taille.x/2;
    int haut = centre.y - taille.y /2;


    int indice_debut = indiceDe(gauche, haut);
    if (indice_debut - largeur >=0 )
        indice_debut -= largeur;
    if (indice_debut % largeur > 0 )
        indice_debut--;
    int nbTileLargeur = (taille.x / 158) +3;
    int nbTileHauteur = (taille.y / 88) +3;


    if ( indice_debut%largeur + nbTileLargeur >= largeur )
        nbTileLargeur = largeur - indice_debut%largeur;
    if ( indice_debut/largeur + nbTileHauteur*2 >= hauteur) {
        nbTileHauteur = (hauteur - (indice_debut/largeur))/2 + 1;
        if (ceil((float)((hauteur - (indice_debut/largeur))/2.)) == (hauteur - (indice_debut/largeur))/2)
            indice_debut-= 2*largeur;
        else
            indice_debut -= largeur;
    }

//    std::cout << "nbTL : " << nbTileLargeur << " nbTH : " << nbTileHauteur << " indice " << indice_debut << std::endl;


    // int stats_parcours=0;
    Tile *indice_ligne, *indice_colonne, *finLigne, *finColonne;

    finLigne = tiles + indice_debut + (nbTileHauteur*largeur*2);
    for (indice_ligne = tiles + indice_debut ; indice_ligne < finLigne ; indice_ligne+=largeur ) {
        finColonne = indice_ligne + nbTileLargeur;

        for (indice_colonne = indice_ligne; indice_colonne < finColonne ; indice_colonne++ ) {
            cible.draw(*indice_colonne);
            //        stats_parcours++;

        }
    }

    //std::cout << "stat_parcours : "<< stats_parcours << std::endl;
}

int CoucheTile::getLargeur() const {
    return largeur;
}

int CoucheTile::getHauteur() const {
    return hauteur;
}

} /* End of namespace cce */
