function gui_viewscroll_change_vertical(args)
	local scroll = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
	local vue = edt.Editeur:getInstance():getVueCourante()
	local carte = edt.Editeur:getInstance():getCarteCourante()
	local couche = carte:getCoucheTileEditable()

--[[	local logger = CEGUI.Logger:getSingleton()
	logger:setLoggingLevel( CEGUI.Informative )
	logger:logEvent( vue:getCenter().x .." , ".. scroll:getScrollPosition()/100 .. " , " .. couche:getHauteur() .. " , " .. (vue:getSize().y/2) )
	logger:logEvent( scroll:getScrollPosition()/100 * couche:getHauteur()  + vue:getSize().y/2  )
	]]	
	vue:setCenter(vue:getCenter().x, scroll:getScrollPosition()/100 * ( couche:getHauteur() - vue:getSize().y/88 + 4)  + vue:getSize().y/2 )
end

function gui_viewscroll_change_horizontal(args)
	local scroll = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
	local vue = edt.Editeur:getInstance():getVueCourante()
	local carte = edt.Editeur:getInstance():getCarteCourante()
	local couche = carte:getCoucheTileEditable()

	vue:setCenter(scroll:getScrollPosition()/100 *(couche:getLargeur() - vue:getSize().x/(158) + 2) + vue:getSize().x / 2 , vue:getCenter().y )
end
