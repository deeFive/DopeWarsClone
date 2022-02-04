#include "Command.hpp"
#include "player.hpp"

class CommandListYourDrugs :public Command {
    Player &player;
    public:
        CommandListYourDrugs(Player& player_) : player{player_}{}
        void call()const override {
            player.list_player_drugs();
        }

};