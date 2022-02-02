#include "Observer.hpp"
#include "player.hpp"

class ConsolePlayerObserver : public Observer<Player> {
    void field_changed(Player & player, const string& field_name){
        cout << "Pole obiektu: " << player.
    }
}