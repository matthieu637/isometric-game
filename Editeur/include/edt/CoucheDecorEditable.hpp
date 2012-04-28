#ifndef edt_CoucheDecorEditable_hpp
#define edt_CoucheDecorEditable_hpp

#include <set>
#include <cce/CoucheDecor.hpp>
#include <bib/io/EnregistreurFichier.hpp>
#include <bib/io/IInscriptible.hpp>

using bib::io::EnregistreurFichier;

namespace edt {

class CoucheDecorEditable : public cce::CoucheDecor, public bib::io::IInscriptible {

    public:

    ///
    ///\brief Construit une couche vide, se créera essentiellement avec la lecture d'un stream
    ///
        CoucheDecorEditable ();

        virtual ~CoucheDecorEditable();

    ///
    ///\brief Ajoute un element de decor
    ///\param id : id de la texture
    ///        x,y : coordonnes de l'element
    ///
        void addElt(const int id, const int x, const int y);

    ///
    ///\brief Supprime un element
    ///\param elt: l'element en question
    ///
        void deleteElt(EltDecor& elt);

        void enregistrement(EnregistreurFichier& flux) const;

    ///
    ///\brief Renvoie un element selon ses coordonnees
    ///\param x: abcisse
    ///       y: ordonnee
    ///
        const EltDecor* getElt(int x, int y) const;

    protected:
        void dessiner(RenderTarget& target) const;

    private:
        std::set<cce::EltDecor> *decor;
};

} /* End of namespace edt */

#endif // edt_CoucheDecorEditable_hpp
