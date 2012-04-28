#ifndef edt_GUI_HPP
#define edt_GUI_HPP

#include <bib/Singleton.hpp>
#include <CEGUI/CEGUISystem.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>

using bib::Singleton;
using sf::Event;

namespace edt {

class GUI : public Singleton<GUI> {

    friend class Singleton<GUI>;

public:
    // fonction init obligatoire
    // car SFML doit être créer avant CEGUI
    void init();
    void dessiner() const;
    void tocHorloge();
    bool captureEvent(const Event& Event);
   
protected:
    GUI();
    ~GUI();

private:
    void initialiserRessources();
    void chargerRessources();
    void initialiserCastEvent();

    CEGUI::Key::Scan toCEGUIKey(const sf::Keyboard::Key& Code) const;
    CEGUI::MouseButton toCEGUIMouseButton(const sf::Mouse::Button& Button) const;

private:    

    CEGUI::System *cSys;
    sf::Clock horloge;

    typedef std::map<sf::Keyboard::Key, CEGUI::Key::Scan> ToucheCast;
    typedef std::map<sf::Mouse::Button, CEGUI::MouseButton> SourisCast;

    ToucheCast keys;
    SourisCast mouses;
};

} /* End of namespace edt */

#endif // edt_GUI_h
