///
///\file EltDecor.hpp
///\brief Element du decor
///\author aymeric
///

#include "cce/EltDecor.hpp"
#include "cce/ImageManager.hpp"

namespace cce
{
    EltDecor::EltDecor(int ID, int _x, int _y): x(_x), y(_y)
    {
        //std::cout << ID << std::endl;
        id = ID;
        setTexture(ImageManager::getInstance()->get_asset(ID));
        setPosition(x,y);
    }

    EltDecor::~EltDecor()
    {}

    int EltDecor::getID() const{ return id; }

    int EltDecor::getX() const{ return x; }

    int EltDecor::getY() const{ return y; }

    int EltDecor::Compare (const EltDecor& e) const{

        if(yCompare < e.yCompare)
            return -1;
        else if(yCompare > e.yCompare)
            return 1;
        else if(x < e.x)
            return -1;
        else if(x > e.x)
            return 1;

        return id < e.id;
    }

    bool EltDecor::operator == (const EltDecor& e) const{
       return !Compare(e);
    }

    bool EltDecor::operator < (const EltDecor& e) const{
      return Compare(e)<0;
    }

} /* End of namespace cce */
