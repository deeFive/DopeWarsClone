#include "Observer.hpp"
#include "player.hpp"

class ConsolePlayerObserver : public Observer<Player> {
    void field_changed(Player & player, const string& field_name) override{
        cout << "Pole obiektu: " << player.get_name() << " " << field_name << " ma teraz wartość: ";
        if(field_name == "name") cout << player.get_name();
        if(field_name == "maney") cout << player.get_maney();
        if(field_name == "player_drugs") player.list_player_drugs();
    }
};