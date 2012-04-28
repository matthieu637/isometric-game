#include <assert.h>
#include "bib/io/LecteurFichier.hpp"

#ifndef NDEBUG
#include <iostream>
#define MACRO_VERIF_FIN_ITERATEUR(X,Y) \
  if(iterateur == end) {\
  cout << "Impossible de " << X << " sur la ligne : " << Y << endl; \
	  exit(0); \
  }

using std::cout;
using std::endl;
#else
#define MACRO_VERIF_FIN_ITERATEUR(X,Y)
#endif

namespace bib {
namespace io {

LecteurFichier::LecteurFichier(const string& cheminFichier):flux(cheminFichier.c_str(), ios::in),_asProchaineLigne(true)
{
  
#ifndef NDEBUG
    indexLigne = 0;

    if (!flux) {
        cout << "Le fichier " << cheminFichier << " ne peut être trouvé" << endl;
        exit(0);
    }
#endif
    prochaineLigne();
}

LecteurFichier::~LecteurFichier(){
  flux.close();
}

bool LecteurFichier::asProchaineLigne()
{
    return _asProchaineLigne;
}


void LecteurFichier::prochaineLigne(const string& delimiteur)
{
    assert(asProchaineLigne());

    string ligne;
    if (getline(flux, ligne))
    {
        _asProchaineLigne = true;
        char_separator<char> _separateur ( delimiteur.c_str() );
        const Decoupeur decoupeur ( ligne, _separateur );
        iterateur = decoupeur.begin();
	end = decoupeur.end();
#ifndef NDEBUG
        this->ligne = ligne;
	indexLigne++;
#endif
    }
    else {
        _asProchaineLigne = false;
        flux.close();
    }
}

int LecteurFichier::lireInt()
{
    MACRO_VERIF_FIN_ITERATEUR("lireInt",indexLigne)

    int i = atoi((*iterateur).c_str());
    ++iterateur;
    return i;
}

int LecteurFichier::lireIntVidePossible()
{
    if(iterateur == end)
      return -1;

    int i = atoi((*iterateur).c_str());
    ++iterateur;
    return i;
}

string LecteurFichier::lireStringVidePossible()
{
    if(iterateur == end)
      return "";
  
    string s = (*iterateur);
    ++iterateur;
    return s;
}

string LecteurFichier::lireString()
{
    MACRO_VERIF_FIN_ITERATEUR("lireString",indexLigne)

    string s = (*iterateur);
    ++iterateur;
    return s;
}

bool LecteurFichier::lireBool()
{
    MACRO_VERIF_FIN_ITERATEUR("lireBool",indexLigne)

    bool b = (*iterateur) != "0";
    ++iterateur;
    return b;
}

void LecteurFichier::allerSection(const string& section) {

    while (asProchaineLigne()){
	string s = lireStringVidePossible();
	
	//std::cout << "l"<< indexLigne << " st :" << s << std::endl;
        if (s == "")
	  prochaineLigne();
	else if(s == "["+section+"]")
            break;
    }
	
    prochaineLigne();
}

}
}
