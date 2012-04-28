#include <cce/Tile.hpp>
#include "edt/CoucheTileEditable.hpp"

using cce::Tile;

namespace edt {

CoucheTileEditable::CoucheTileEditable(int _largeur, int _hauteur) : CoucheTile()
{
    this->largeur = _largeur;
    this->hauteur = _hauteur;
    this->nbTiles = _largeur*_hauteur;
    tiles = new Tile [nbTiles];
}

CoucheTileEditable::CoucheTileEditable() : CoucheTile()
{
  
}

void CoucheTileEditable::enregistrement(EnregistreurFichier& flux) const {
    flux.ecrireSection("tiles");

    flux.ecrireEntier(largeur);
    flux.ecrireEntier(hauteur);
    flux.prochaineLigne();

    Tile *total = tiles + nbTiles ;
    for (Tile *p = tiles; p < total ; p++) {
        int id = (*p).getID();
        if (id != -1)
            flux.ecrireEntier(id);
        flux.prochaineLigne();
    }
}

} /* End of namespace edt */
