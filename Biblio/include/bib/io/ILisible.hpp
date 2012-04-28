///
///\file ILisible.hpp
///\brief Interface qu'une classe peut utiliser pour lire des données d'un fichier
///\author matthieu637
///

#ifndef ILISIBLE_HPP
#define ILISIBLE_HPP

#include "bib/io/LecteurFichier.hpp"

namespace bib {
namespace io {

class ILisible
{
public :
    ///
    ///\brief Méthode à redéfinir dans la sous classe pour la remplir
    ///       par le flux de données
    ///\param flux : le flux à lire
    ///
    virtual void lecture(LecteurFichier& flux) = 0;
    
};
}
}

#endif // LISIBLE_HPP
