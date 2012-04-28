///
///\file Enregistreur.hpp
///\brief Permet d'enregistrer un fichier de façon simplifié 
///
///\author matthieu637
///

#ifndef ENREGISTREURFICHIER_HPP
#define ENREGISTREURFICHIER_HPP

#include <fstream>

using std::string;
using std::ofstream;

namespace bib {
namespace io {
class EnregistreurFichier
{

public:
    ///
    ///\brief creer ( et remplace si existe déjà ) un fichier
    ///\param chemin : chemin du fichier
    ///	      separateur : separateur de tout le fichier ( typicalement l'espace )
    ///
    EnregistreurFichier(const string & chemin, const string & separateur = " ");
    
    ///
    ///\brief Ferme le flux
    ///
    virtual ~EnregistreurFichier();
    
    ///
    ///\brief Va a la ligne suivante
    ///
    void prochaineLigne();
    
    ///
    ///\brief ecrit un string puis un separateur
    ///
    void ecrireString(const string & s);
    
    ///
    ///\brief ecrit un entier puis un separateur
    ///
    void ecrireEntier(const int i);
    
    ///
    ///\brief ecrit une [section] puis saute une ligne
    ///
    void ecrireSection(const string &s);

private:
    ofstream flux;
    string separateur;
};
}
}
#endif // ENREGISTREURFICHIER_H
