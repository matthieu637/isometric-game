#ifndef _SINGLETON_HPP
#define _SINGLETON_HPP

#include <assert.h>

namespace bib {

template <class T>
class Singleton
{


public:
    static T* getInstance()
    {
        assert(_singleton != NULL);
        return _singleton;
    }

protected:
    Singleton() {}
    ~Singleton() {}

private:
    static T* _singleton;
};

template <class T>
T *Singleton<T>::_singleton = new T;

}

#endif

