#include "edt/CarteEditable.hpp"
#include <cce/ImageManager.hpp>

using cce::ImageManager;

namespace edt {

CarteEditable::CarteEditable(const int &largeur, const int &hauteur) : Carte(new CoucheTileEditable(largeur,hauteur),
                                                                             new CoucheDecorEditable())
{

}

CarteEditable::CarteEditable(const std::string& map) : Carte()
{
  init(map);
}

void CarteEditable::enregistrement(EnregistreurFichier& flux) const {
    getCoucheTileEditable()->enregistrement(flux);
    getCoucheDecorEditable()->enregistrement(flux);
}

CoucheTileEditable* CarteEditable::getCoucheTileEditable() const {
    return static_cast<CoucheTileEditable*> (ctile);
}

CoucheDecorEditable* CarteEditable::getCoucheDecorEditable() const {
    return static_cast<CoucheDecorEditable*> (decor);
}

void CarteEditable::creerCoucheTile()
{
    ctile = new CoucheTileEditable();
}

void CarteEditable::creerCoucheDecor()
{
    decor = new CoucheDecorEditable();
}

void CarteEditable::ecrireRessources(EnregistreurFichier& flux) const {
    flux.ecrireSection("id_ressource");
/*
 *  TODO: enregistrement des ressources lorsque iterateur pret
 * 
    std::pair <typename std::map<int, sf::Texture>::iterator, typename std::map<int, sf::Texture>::iterator> pair;
    pair.first;
    
    int nbRessource = flux.lireInt();
    flux.prochaineLigne();

    for (int i=0;i<nbRessource;i++) {
        int id = flux.lireInt();
        string chemin = flux.lireString();

        if (!ImageManager::getInstance()->is_loaded(id))
            ImageManager::getInstance()->load_asset(id,chemin);
        flux.prochaineLigne();
    }
*/    
}

} /* End of namespace edt */
