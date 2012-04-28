///
///\file Ressources.hpp
///\brief Permet d'acceder aux managers.
///\author Aymeric
///

#ifndef RESSOURCES_HPP
#define RESSOURCES_HPP

#include "bib/AssetManager.hpp"
#include "bib/Singleton.hpp"
#include "cce/ImageManager.hpp"

using bib::AssetManager;

namespace cce {

class Ressources : public bib::Singleton<Ressources>
{
    friend class bib::Singleton<Ressources>;

public :
        ImageManager* getImageManager(){
            return ImageManager::getInstance();
        }

private:
        Ressources(){}
        virtual ~Ressources(){}
};

} /* End of namespace cce */

#endif // RESSOURCES_HPP
