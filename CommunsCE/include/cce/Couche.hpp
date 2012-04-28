///
///\file Couche.hpp
///\brief Classe abstraite de toutes les couches
///\author matthieu637
///

#ifndef COUCHE_HPP
#define COUCHE_HPP

#include <bib/io/ILisible.hpp>
#include "IDessinable.hpp"

using bib::io::ILisible;

namespace cce {

class Couche : public ILisible, public IDessinable
{

};
}

#endif //  COUCHE_HPP
