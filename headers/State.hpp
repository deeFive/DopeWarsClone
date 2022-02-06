#include <functional>
#include <map>
#include <vector>
#include <iostream>
#include "drug.hpp"
#include "player.hpp"
#include "commandBuyDrug.hpp"
#include "commandSellDrug.hpp"
#include "instance.hpp"
#include "consolePlayerObserver.hpp"
#include "drugsListModel.hpp"
#include "commandSetNewDrugList.hpp"
#include "commandListDrugsInLocation.hpp"
#include "commandListYourDrugs.hpp"
#include "StateEnum.hpp"
#include "commandExitGame.hpp"
using namespace std;

class GameFST
{
    Instance current_instance{"new york"};
    Player player{"default"};
    DrugsListModel drugs_list_model{};
    int current_amount = 0;
    string current_drug_name = "";
    CommandSetNewDrugList setNewDrugsInLocation{drugs_list_model, current_instance};
    CommandListDrugsInLocation listDrugInLocation{current_instance};
    CommandListYourDrugs listYourDrugs{player};
    CommandBuyDrugs buyDrugs{player, current_instance, current_amount, current_drug_name};
    CommandSellDrugs sellDrugs{player, current_instance, current_amount, current_drug_name};
    CommandExitGame exitGame;
    map<EnumState, vector<pair<EnumTrigger, reference_wrapper<Command>>>> rules;
    EnumState current_state{EnumState::Start};
    EnumState exit_state{EnumState::Quit};

    void init_rules()
    {   
        pair<EnumTrigger,std::reference_wrapper<Command>> in_pair = pair<EnumTrigger,reference_wrapper<Command>>(EnumTrigger::StartGame,listDrugInLocation);
        vector<std::pair<EnumTrigger,reference_wrapper<Command>>> tmp_v;
        tmp_v.push_back(in_pair);
        auto pair = make_pair(EnumState::Start,tmp_v);
        // rules.emplace();
    };
    /*
        rules[EnumState::InLocation] = {
            {EnumTrigger::ToLocation,listDrugInLocation},
            {EnumTrigger::ToBuy,buyDrugs},
            {EnumTrigger::ToSell,sellDrugs},
            {EnumTrigger::EndGame,exitGame}
        };
        rules[EnumState::Buy] = {
            {EnumTrigger::ToLocation,EnumState::InLocation},
        };
        rules[EnumState::Sell] = {
            {EnumTrigger::ToLocation,EnumState::InLocation}
        };
        rules[EnumState::Sell] = {
            {EnumTrigger::ToLocation, EnumState::InLocation}};
    }
    */
    public:
    GameFST(){};
    /*
    void play()
    {
        while(true){
            cout << current_state;
            select_trigger:
            cout << "wybierz komendę: " << endl;
            int i =0;
            for(auto item : rules[current_state]){
                cout << i++ << "." << item.first << endl;
            }
            int input;
            cin >> input;
            if(input < 0 || (input+1) > rules[current_state].size()){
                cout << "Niepoprawna opcja spróbuj jeszcze raz." << endl;
                goto select_trigger;
            }
            current_state = rules[current_state][input].second;
            if(current_state == exit_state) break;
        }

        current_state = rules[current_state][input].second;
        if (current_state == exit_enum_state)
            break;
    }
    */
};
