#include "bib/io/EnregistreurFichier.hpp"
#include <iostream>

namespace bib {
namespace io {

EnregistreurFichier::EnregistreurFichier(const string & chemin, const string & _separateur) : flux(chemin.c_str()), separateur(_separateur)
{
  
}

EnregistreurFichier::~EnregistreurFichier()
{
  flux.close();
}

void EnregistreurFichier::prochaineLigne() {
  flux << std::endl;
}

void EnregistreurFichier::ecrireString(const string & s) {
  flux << s << separateur;
}

void EnregistreurFichier::ecrireEntier(const int i)
{
  flux << i << separateur;
}

void EnregistreurFichier::ecrireSection(const string &s)
{
  flux << '[' << s << ']' << std::endl;
}

}
}
