#include "Command.hpp"
#include "player.hpp"
#include "instance.hpp"
#include "drug.hpp"

class CommandSellDrugs : public Command
{
    Player &player;
    Instance &instance;
    int amount;
    string drug_name;

public:
    CommandSellDrugs(Player &player_, Instance &instance_, int amount_, string drug_name_) : amount{amount_}, drug_name{drug_name_}, player{player_}, instance{instance_} {}
    void call() const override
    {
        Drug drug = instance.get_drug(drug_name);
        if (drug.get_name() != string{"Empty"})
        {   
            player.add_maney(amount * drug.get_price());
            instance.add_drug(drug_name, amount);
            player.substruct_drug(drug_name,amount);
        }
    }
};