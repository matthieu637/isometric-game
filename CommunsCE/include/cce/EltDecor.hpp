///
///\file EltDecor.hpp
///\brief Element du decor
///\author Matthieu637
///

#ifndef ELTDECOR_HPP
#define ELTDECOR_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using sf::Sprite;
using sf::Texture;

namespace cce
{

class EltDecor : public Sprite
{

    public:
    ///
    ///\brief Construit un element.
    ///\param x: abcisse
    ///\param y: ordonnee
    ///\param ID: ID du dessin à récupérer dans le gestionnaire de ressources
    ///
        EltDecor(int ID, int x = 0, int y = 0);
        virtual ~EltDecor();

    public:
    ///
    ///\brief Retourne l'id de l'image utilisee
    ///
        int getID() const;

    ///
    ///\brief Retourne l'abcisse
    ///
        int getX() const;

    ///
    ///\brief Retourne l'ordonnee
    ///
        int getY() const;

    ///
    ///\brief Retourne un int de comparaison pour le tri dans le set
    ///
        int Compare (const EltDecor& d) const;

        bool operator == (const EltDecor& e) const;

        bool operator < (const EltDecor& e) const;

    private:
    ///
    ///\brief yCompare: sert a comparer avec les autres elts pour ne pas recalculer a chaque comparaison
    ///
        int id, x, y, yCompare;
};

} /* End of namespace cce */

#endif // ELTDECOR_HPP
