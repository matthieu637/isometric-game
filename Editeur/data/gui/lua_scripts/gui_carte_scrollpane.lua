function gui_viewscroll_change_vertical(args)
	local scroll = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
	local vue = edt.Editeur:getInstance():getVueCourante()
	local carte = edt.Editeur:getInstance():getCarteCourante()
	local couche = carte:getCoucheTileEditable()

	local logger = CEGUI.Logger:getSingleton()
		
	vue:SetCenter(vue:GetCenter().x, scroll:getScrollPosition() * couche:getHauteur()  + vue:GetSize().y/2 );
end

function gui_viewscroll_change_horizontal(args)
	local scroll = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
	local vue = edt.Editeur:getInstance():getVueCourante()
	local carte = edt.Editeur:getInstance():getCarteCourante()
	local couche = carte:getCoucheTileEditable()

	vue:SetCenter( scroll:getScrollPosition() + ( vue:GetSize().x / 2 ) , vue:GetCenter().y );
end


