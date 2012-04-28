#ifndef edt_CoucheNPCEditable_hpp
#define edt_CoucheNPCEditable_hpp

#include <bib/io/IInscriptible.hpp>
#include <cce/CoucheNPC.hpp>

using bib::io::IInscriptible;

namespace edt {

class CoucheNPCEditable : public cce::CoucheNPC, public IInscriptible {

};

} /* End of namespace edt */

#endif // edt_CoucheNPCEditable_h
