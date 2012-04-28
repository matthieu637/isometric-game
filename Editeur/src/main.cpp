#include "edt/Editeur.hpp"
#include "cce/ImageManager.hpp"

using edt::Editeur;
using cce::ImageManager;

int main()
{
    ImageManager::getInstance()->add_resource_directory("data/");
  
    Editeur* e = Editeur::getInstance();
    e->init("data/test.txt");
    e->run();

    return EXIT_SUCCESS;
}

