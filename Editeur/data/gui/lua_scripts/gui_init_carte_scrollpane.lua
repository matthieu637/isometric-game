-- initialse taille pane
local wmn = CEGUI.WindowManager:getSingleton()
local pane = CEGUI.toScrollablePane( wmn:getWindow("Editeur/Pane") )
local carte = edt.Editeur:getInstance():getCarteCourante()
local couche = carte:getCoucheTileEditable()

pane:setContentPaneArea(CEGUI.Rect(0,0,couche:getLargeur(), couche:getHauteur()));


