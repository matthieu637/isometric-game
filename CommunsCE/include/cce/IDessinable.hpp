///
///\file IDessinable.hpp
///\brief Interface qu'une classe peut utiliser pour indiquer qu'elle est dessinable
///	  contrairement à Drawable, c'est une interface ( pas de champs stocké )
///\author matthieu637
///

#ifndef IDESSINABLE_HPP
#define IDESSINABLE_HPP

#include <SFML/Graphics/RenderTarget.hpp>

using sf::RenderTarget;

namespace cce {

class IDessinable
{
public :
    ///
    ///\brief Méthode à redéfinir dans la sous classe pour la dessiner
    ///		la fonction n'est pas constante afin de laisser la
    ///		possibilité de stocker un état pour limiter les calculs
    ///
    ///\param cible : dessine sur la cible
    ///
    virtual void dessinerSur(RenderTarget& cible) = 0;
    
};
}

#endif // IDESSINABLE_HPP
