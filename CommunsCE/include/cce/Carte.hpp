///
///\file Carte.hpp
///\brief Réprésente une carte dans le modèle
///\author Matthieu637
///

#ifndef cce_Carte_hpp
#define cce_Carte_hpp
#include <string>
#include <bib/io/ILisible.hpp>
#include "IDessinable.hpp"
#include "CoucheTile.hpp"
#include "CoucheDecor.hpp"

using std::string;
using bib::io::ILisible;

namespace cce {

class Carte : public ILisible, public IDessinable {

public:

    ///
    ///\brief Construit une carte vide, necessite un appel à init
    /// 	afin d'être initialisé
    ///
    Carte();

    ///
    ///\brief Construit une carte à partir de son nom
    ///\param map : chemin de la map à ouvrir
    ///
    void init(const string &map);

    ///
    ///\brief Construit une carte à partir des differentes couches
    ///		utilisé principalement par CarteEditable
    ///
    Carte(CoucheTile *ct, CoucheDecor *d);

    ///
    ///\brief Dessine toutes les couches succesivements
    ///
    void dessinerSur(RenderTarget& cible);

    ///
    ///\brief Lance la lecture des differentes couches
    ///
    void lecture(LecteurFichier& flux);

    ///
    ///\brief Lit les ressources à partir du flux
    ///
    ///format : commence après la balise [id_ressource]
    ///		  nb_de_ressources
    ///		  id_texture nom_texture
    ///		  ...
    ///		  id_texture nom_texture
    ///
    void lireRessources(LecteurFichier& flux);



protected:
    virtual void creerCoucheTile() = 0;
    virtual void creerCoucheDecor() = 0;

    CoucheTile	* ctile;
    CoucheDecor	* decor;
};

} /* End of namespace cce */

#endif // cce_Carte_h
