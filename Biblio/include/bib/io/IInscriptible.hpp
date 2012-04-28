///
///\file IInscriptible.hpp
///\brief Interface qu'une classe peut utiliser pour écrire des données dans un fichier
///\author matthieu637
///

#ifndef IINSCRIPTIBLE_HPP
#define IINSCRIPTIBLE_HPP

#include "bib/io/EnregistreurFichier.hpp"

namespace bib {
namespace io {

class IInscriptible
{
public :
    ///
    ///\brief Méthode à redéfinir dans la sous classe pour enregistrer ses informations
    ///
    ///\param flux : le flux à écrire
    ///
    virtual void enregistrement(EnregistreurFichier& flux) const = 0;
};
}
}

#endif // INSCRIPTIBLE_HPP
