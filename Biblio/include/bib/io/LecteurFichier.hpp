///
///\file LecteurFichier.hpp
///\brief Permet de lire de façon simplifié un fichier morceau par morceau
///
///\example S'utilise typiquement de cette façon :
///    LecteurFichier l("test.txt");
///    while (l.asProchaineLigne())
///    {
///        l.lireString() ;
///		...
///        l.prochaineLigne();
///    }
///
///\author matthieu637
///

#ifndef LECTEURFICHIER_HPP
#define LECTEURFICHIER_HPP

#include <fstream>
#include <boost/tokenizer.hpp>

namespace bib {
namespace io {

using std::ifstream;
using std::string;
using std::ios;
using boost::tokenizer;
using boost::char_separator;

class LecteurFichier
{
public:
///
///\brief Constructeur de la classe LecteurFichier
///\param cheminFichier : le chemin vers le fichier à lire
///
    LecteurFichier(const string& cheminFichier);

///
///\brief Ferme le flux 
///
    virtual ~LecteurFichier();
///
///\brief Détermine si le fichier contient une prochaine ligne à lire
///	  ferme le flux dans le cas contraire
///\return si le fichier contient une nouvelle ligne
///
    bool asProchaineLigne();

///
///\brief Calcul de la prochaine ligne
///	 def ssi asProchaineLigne()
///\param delimiteur : le caractère de découpage de la ligne ( par defaut l'espace )
///
    void prochaineLigne(const string& delimiteur = " ");

///
///\brief Lit l'itérateur et l'incrémente
/// 	def ssi iterateur != decoupeur.end()
///\return Retourne l'entier lu à la position courante
///
    int lireInt();
    
///
///\brief Lit l'itérateur et l'incrémente 
///       retourne -1 si ligne vide
///\return Retourne l'entier lu à la position courante
///
    int lireIntVidePossible();

///
///\brief Lit l'itérateur et l'incrémente
/// 	def ssi iterateur != decoupeur.end()
///\return Retourne le string lu à la position courante
///
    string lireString();

///
///\brief Lit l'itérateur et l'incrémente
///\return Retourne le string lu à la position courante (possiblement vide)
///
    string lireStringVidePossible();
///
///\brief Lit l'itérateur et l'incrémente
/// 	def ssi iterateur != decoupeur.end()
///\return Retourne le boolean lu à la position courante
///
    bool lireBool();

///
///\brief Outils permettant de naviguer dans le flux
///\param section : la [section] du fichier à atteindre
///
void allerSection(const string& section);
    
private:
    typedef tokenizer<char_separator<char> > Decoupeur;
    ifstream flux;
    bool _asProchaineLigne;
    Decoupeur::const_iterator iterateur;
    Decoupeur::const_iterator end;
#ifndef NDEBUG
    string ligne;
    int indexLigne;
#endif
};

}
}

#endif // LECTEURFICHIER_H
