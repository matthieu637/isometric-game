#include "cce/ImageManager.hpp"
#include "cce/Carte.hpp"

using std::string;

namespace cce {

Carte::Carte()
{

}

void Carte::init(const string &map) {
    LecteurFichier flux(map);
    creerCoucheTile();
    creerCoucheDecor();

    lecture(flux);
}

Carte::Carte(CoucheTile *ct, CoucheDecor *d) {
    ctile = ct;
    decor = d;
}

void Carte::lecture(LecteurFichier& flux) {
    lireRessources(flux);
    ctile->lecture(flux);
    decor->lecture(flux);
}

void Carte::lireRessources(LecteurFichier& flux) {
    flux.allerSection("id_ressource");

    int nbRessource = flux.lireInt();
    flux.prochaineLigne();

    for (int i=0;i<nbRessource;i++) {
        int id = flux.lireInt();
        string chemin = flux.lireString();
	
        if (!ImageManager::getInstance()->is_loaded(id))
            ImageManager::getInstance()->load_asset(id,chemin);
        flux.prochaineLigne();
    }
}

void Carte::dessinerSur(RenderTarget& target) {
    ctile->dessinerSur(target);
    decor->dessinerSur(target);
}


} /* End of namespace cce */


