#ifndef edt_CoucheTransitionEditable_hpp
#define edt_CoucheTransitionEditable_hpp

#include <bib/io/IInscriptible.hpp>
#include <cce/CoucheTransition.hpp>

using bib::io::IInscriptible;

namespace edt {

class CoucheTransitionEditable : public cce::CoucheTransition, public IInscriptible {

};

} /* End of namespace edt */

#endif // edt_CoucheTransitionEditable_h
