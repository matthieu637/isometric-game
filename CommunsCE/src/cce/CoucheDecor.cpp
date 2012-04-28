#include "cce/CoucheDecor.hpp"
#include <iostream>
namespace cce
{

CoucheDecor::CoucheDecor(){}
CoucheDecor::~CoucheDecor(){}

void CoucheDecor::lecture(LecteurFichier& flux) {

    flux.allerSection("decor");
    int taille = flux.lireInt();
    flux.prochaineLigne();
    //std::cout << taille << std::endl;

    while(taille-- > 0) {
        int id = flux.lireInt();
        int x = flux.lireInt();
        int y = flux.lireInt();
        addElt(id, x, y);
        flux.prochaineLigne();
    }
}

void CoucheDecor::dessinerSur(RenderTarget& target)
{
    dessiner(target);
}

}
