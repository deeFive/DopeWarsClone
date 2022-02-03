#include "Command.hpp"
#include "player.hpp"
#include "instance.hpp"
#include "drug.hpp"

class CommandBuyDrugs : public Command
{
    Player &player;
    Instance &instance;
    int amount;
    string drug_name;

public:
    CommandBuyDrugs(Player &player_, Instance &instance_, int amount_, string drug_name_) : amount{amount_}, drug_name{drug_name_}, player{player_}, instance{instance_} {}
    void call() const override
    {
        Drug drug = instance.get_drug(drug_name);
        if (drug.get_name() != string{"Empty"})
        {
            if (player.get_maney() < amount * drug.get_price())
                cout << "Nie masz tyle pieniędzy. ";
            else
            {
                player.subtract_maney(amount * drug.get_price());
                instance.substruct_drug(drug_name, amount);
                drug.set_amount(amount);
                player.add_drug(drug);
            }
        }
    }
};