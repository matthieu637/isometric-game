/*
** Lua binding: LuaInterface
** Generated automatically by tolua++-1.0.92 on Wed Jan  4 02:39:37 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LuaInterface_open (lua_State* tolua_S);

#include "edt/Editeur.hpp"
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include "edt/CarteEditable.hpp"
#include "edt/CoucheTileEditable.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"sf::View");
 tolua_usertype(tolua_S,"edt::CarteEditable");
 tolua_usertype(tolua_S,"edt::CoucheTileEditable");
 tolua_usertype(tolua_S,"sf::Vector2f");
 tolua_usertype(tolua_S,"edt::Editeur");
}

/* method: getInstance of class  edt::Editeur */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_Editeur_getInstance00
static int tolua_LuaInterface_edt_Editeur_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"edt::Editeur",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   edt::Editeur* tolua_ret = (edt::Editeur*)  edt::Editeur::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"edt::Editeur");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVueCourante of class  edt::Editeur */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_Editeur_getVueCourante00
static int tolua_LuaInterface_edt_Editeur_getVueCourante00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"edt::Editeur",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  edt::Editeur* self = (edt::Editeur*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVueCourante'", NULL);
#endif
  {
   sf::View* tolua_ret = (sf::View*)  self->getVueCourante();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"sf::View");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVueCourante'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCarteCourante of class  edt::Editeur */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_Editeur_getCarteCourante00
static int tolua_LuaInterface_edt_Editeur_getCarteCourante00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"edt::Editeur",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  edt::Editeur* self = (edt::Editeur*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCarteCourante'", NULL);
#endif
  {
   edt::CarteEditable* tolua_ret = (edt::CarteEditable*)  self->getCarteCourante();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"edt::CarteEditable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCarteCourante'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCoucheTileEditable of class  edt::CarteEditable */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_CarteEditable_getCoucheTileEditable00
static int tolua_LuaInterface_edt_CarteEditable_getCoucheTileEditable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const edt::CarteEditable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const edt::CarteEditable* self = (const edt::CarteEditable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCoucheTileEditable'", NULL);
#endif
  {
   edt::CoucheTileEditable* tolua_ret = (edt::CoucheTileEditable*)  self->getCoucheTileEditable();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"edt::CoucheTileEditable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCoucheTileEditable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLargeur of class  edt::CoucheTileEditable */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_CoucheTileEditable_getLargeur00
static int tolua_LuaInterface_edt_CoucheTileEditable_getLargeur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const edt::CoucheTileEditable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const edt::CoucheTileEditable* self = (const edt::CoucheTileEditable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLargeur'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLargeur();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLargeur'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHauteur of class  edt::CoucheTileEditable */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_edt_CoucheTileEditable_getHauteur00
static int tolua_LuaInterface_edt_CoucheTileEditable_getHauteur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const edt::CoucheTileEditable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const edt::CoucheTileEditable* self = (const edt::CoucheTileEditable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHauteur'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHauteur();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHauteur'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCenter of class  sf::View */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_sf_View_SetCenter00
static int tolua_LuaInterface_sf_View_SetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"sf::View",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  sf::View* self = (sf::View*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenter'", NULL);
#endif
  {
   self->setCenter(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCenter of class  sf::View */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_sf_View_GetCenter00
static int tolua_LuaInterface_sf_View_GetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const sf::View",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const sf::View* self = (const sf::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenter'", NULL);
#endif
  {
   const sf::Vector2f& tolua_ret = (const sf::Vector2f&)  self->getCenter();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const sf::Vector2f");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  sf::View */
#ifndef TOLUA_DISABLE_tolua_LuaInterface_sf_View_GetSize00
static int tolua_LuaInterface_sf_View_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const sf::View",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const sf::View* self = (const sf::View*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const sf::Vector2f& tolua_ret = (const sf::Vector2f&)  self->getSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const sf::Vector2f");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  sf::Vector2f */
#ifndef TOLUA_DISABLE_tolua_get_sf__Vector2f_x
static int tolua_get_sf__Vector2f_x(lua_State* tolua_S)
{
  sf::Vector2f* self = (sf::Vector2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  sf::Vector2f */
#ifndef TOLUA_DISABLE_tolua_set_sf__Vector2f_x
static int tolua_set_sf__Vector2f_x(lua_State* tolua_S)
{
  sf::Vector2f* self = (sf::Vector2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  sf::Vector2f */
#ifndef TOLUA_DISABLE_tolua_get_sf__Vector2f_y
static int tolua_get_sf__Vector2f_y(lua_State* tolua_S)
{
  sf::Vector2f* self = (sf::Vector2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  sf::Vector2f */
#ifndef TOLUA_DISABLE_tolua_set_sf__Vector2f_y
static int tolua_set_sf__Vector2f_y(lua_State* tolua_S)
{
  sf::Vector2f* self = (sf::Vector2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaInterface_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"edt",0);
  tolua_beginmodule(tolua_S,"edt");
   tolua_cclass(tolua_S,"Editeur","edt::Editeur","",NULL);
   tolua_beginmodule(tolua_S,"Editeur");
    tolua_function(tolua_S,"getInstance",tolua_LuaInterface_edt_Editeur_getInstance00);
    tolua_function(tolua_S,"getVueCourante",tolua_LuaInterface_edt_Editeur_getVueCourante00);
    tolua_function(tolua_S,"getCarteCourante",tolua_LuaInterface_edt_Editeur_getCarteCourante00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CarteEditable","edt::CarteEditable","",NULL);
   tolua_beginmodule(tolua_S,"CarteEditable");
    tolua_function(tolua_S,"getCoucheTileEditable",tolua_LuaInterface_edt_CarteEditable_getCoucheTileEditable00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CoucheTileEditable","edt::CoucheTileEditable","",NULL);
   tolua_beginmodule(tolua_S,"CoucheTileEditable");
    tolua_function(tolua_S,"getLargeur",tolua_LuaInterface_edt_CoucheTileEditable_getLargeur00);
    tolua_function(tolua_S,"getHauteur",tolua_LuaInterface_edt_CoucheTileEditable_getHauteur00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"sf",0);
  tolua_beginmodule(tolua_S,"sf");
   tolua_cclass(tolua_S,"View","sf::View","",NULL);
   tolua_beginmodule(tolua_S,"View");
    tolua_function(tolua_S,"SetCenter",tolua_LuaInterface_sf_View_SetCenter00);
    tolua_function(tolua_S,"GetCenter",tolua_LuaInterface_sf_View_GetCenter00);
    tolua_function(tolua_S,"GetSize",tolua_LuaInterface_sf_View_GetSize00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Vector2f","sf::Vector2f","",NULL);
   tolua_beginmodule(tolua_S,"Vector2f");
    tolua_variable(tolua_S,"x",tolua_get_sf__Vector2f_x,tolua_set_sf__Vector2f_x);
    tolua_variable(tolua_S,"y",tolua_get_sf__Vector2f_y,tolua_set_sf__Vector2f_y);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaInterface (lua_State* tolua_S) {
 return tolua_LuaInterface_open(tolua_S);
}
#endif

