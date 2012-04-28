#ifndef edt_CoucheTileEditable_h
#define edt_CoucheTileEditable_h

#include <bib/io/IInscriptible.hpp>
#include <cce/CoucheTile.hpp>

using bib::io::IInscriptible;
using cce::CoucheTile;

namespace edt {

class CoucheTileEditable : public CoucheTile, public IInscriptible {

public:
///
///\brief Constructeur de la classe CouchTile en fonction la hauteur et largeur
///\param largeur : nombre de Tile en largeur
///		  hauteur : nombre de Tile en hauteur
///
    CoucheTileEditable ( int largeur, int hauteur );

    CoucheTileEditable();

    void enregistrement(EnregistreurFichier& flux) const;
};

} /* End of namespace edt */

#endif // edt_CoucheTileEditable_h
