#include <iostream>
#include "cce/Ressources.hpp"
#include "edt/CoucheDecorEditable.hpp"

using namespace cce;

namespace edt {

CoucheDecorEditable::CoucheDecorEditable(): CoucheDecor()
{
    decor = new std::set<cce::EltDecor>;
}

CoucheDecorEditable::~CoucheDecorEditable() {
}

void CoucheDecorEditable::addElt(const int id, const int x, const int y)
{
    decor->insert(EltDecor(id, x, y));
}

void CoucheDecorEditable::deleteElt(EltDecor& elt)
{
    decor->erase(elt);
}

const EltDecor* CoucheDecorEditable::getElt(int x, int y) const
{
    int x_, y_, x_droit, y_bas, a;
    std::set<EltDecor>::iterator it = decor->begin();
    for(; it != decor->end(); it++){
        x_ = it->getX();
        y_ = it->getY();
        if(y_ > y)
            return NULL;
        x_droit = Ressources::getInstance()->getImageManager()->get_asset(it->getID()).getSize().x + x_;
        y_bas = Ressources::getInstance()->getImageManager()->get_asset(it->getID()).getSize().y + y_;
        if(x_ <= x && x <= x_droit && y_ <= y && y <= y_bas){
            a = Ressources::getInstance()->getImageManager()->get_asset(it->getID()).copyToImage().getPixel(x - x_, y - y_).a;
            if(a != 0)
                return &(*it);
        }
    }

    return NULL;
}

void CoucheDecorEditable::enregistrement(EnregistreurFichier& flux) const
{
    flux.ecrireSection("decor");
    flux.ecrireEntier(decor->size());
    flux.prochaineLigne();
    std::set<EltDecor>::iterator it = decor->begin();
    for(; it != decor->end(); ++it){
        flux.ecrireEntier((*it).getID());
        flux.ecrireEntier((*it).getX());
        flux.ecrireEntier((*it).getY());
        flux.prochaineLigne();
    }
}

void CoucheDecorEditable::dessiner(RenderTarget& target) const
{
    std::set<EltDecor>::iterator it = decor->begin();
    for(; it != decor->end(); ++it)
        target.draw(*it);
}

} /* End of namespace edt */
