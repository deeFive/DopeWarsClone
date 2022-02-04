#include <map>
#include <vector>
#include <iostream>
#include "drug.hpp"
#include "player.hpp"
#include "commandBuyDrug.hpp"
#include "instance.hpp"
#include "consolePlayerObserver.hpp"
#include "drugsListModel.hpp"
#include "commandSetNewDrugList.hpp"

using namespace std;

enum class EnumState
{
    Start,
    InLocation,
    Buy,
    Sell,
    Quit
};
inline ostream &operator<<(ostream &os, const EnumState &s)
{
    switch (s)
    {
    case EnumState::Start:
        os << "Start." << endl;
        break;
    case EnumState::InLocation:
        os << "Gracz znajduje się w lokacji." << endl;
        break;
    case EnumState::Buy:
        os << "Kup narkotyk: " << endl;
        break;
    case EnumState::Sell:
        os << "Sprzedaj narkotyk: " << endl;
        break;
    case EnumState::Quit:
        os << "Koniec gry" << endl;
        break;
    }
    return os;
}
enum class EnumTrigger
{
    StartGame,
    ToLocation,
    ToBuy,
    ToSell,
    EndGame,
};
inline ostream &operator<<(ostream &os, const EnumTrigger &s)
{
    switch (s)
    {
    case EnumTrigger::StartGame:
        os << "Gra się zaczyna." << endl;
        break;
    case EnumTrigger::ToLocation:
        os << "Przemieszczasz się do lokacji." << endl;
        break;
    case EnumTrigger::ToBuy:
        os << "Co zamierzasz kupić." << endl;
        break;
    case EnumTrigger::ToSell:
        os << "Co zamierzasz sprzedać." << endl;
        break;
    case EnumTrigger::EndGame:
        os << "Gra się kończy." << endl;
        break;
    }
    return os;
}
class GameFST
{
    map<EnumState, vector<pair<EnumTrigger, EnumState>>> rules;
    EnumState current_state {EnumState::Start};
    EnumState exit_state {EnumState::Quit};
    
    void init_rules(){
        rules[EnumState::Start] = {
            {EnumTrigger::ToLocation,EnumState::InLocation}
        };
        rules[EnumState::InLocation] = {
            {EnumTrigger::ToLocation,EnumState::InLocation},
            {EnumTrigger::ToBuy,EnumState::Buy},
            {EnumTrigger::ToSell,EnumState::Sell},
            {EnumTrigger::EndGame,EnumState::Quit}
        };
        rules[EnumState::Buy] = {
            {EnumTrigger::ToLocation,EnumState::InLocation},            
        };
        rules[EnumState::Sell] = {
            {EnumTrigger::ToLocation,EnumState::InLocation}
        };
    }
    public:
        GameFST(){};
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
        }
};