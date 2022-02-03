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

enum class State
{
    Start,
    InLocation,
    Buy,
    Sell,
    Quit
};
inline ostream &operator<<(ostream &os, const State &s)
{
    switch (s)
    {
    case State::Start:
        os << "Start." << endl;
        break;
    case State::InLocation:
        os << "Gracz znajduje się w lokacji." << endl;
        break;
    case State::Buy:
        os << "Kup narkotyk: " << endl;
        break;
    case State::Sell:
        os << "Sprzedaj narkotyk: " << endl;
        break;
    case State::Quit:
        os << "Koniec gry" << endl;
        break;
    }
    return os;
}
enum class Trigger
{
    StartGame,
    ToLocation,
    ToBuy,
    ToSell,
    EndGame,
};
inline ostream &operator<<(ostream &os, const Trigger &s)
{
    switch (s)
    {
    case Trigger::StartGame:
        os << "Gra się zaczyna." << endl;
        break;
    case Trigger::ToLocation:
        os << "Przemieszczasz się do lokacji." << endl;
        break;
    case Trigger::ToBuy:
        os << "Co zamierzasz kupić." << endl;
        break;
    case Trigger::ToSell:
        os << "Co zamierzasz sprzedać." << endl;
        break;
    case Trigger::EndGame:
        os << "Gra się kończy." << endl;
        break;
    }
    return os;
}
class GameFST
{
    map<State, vector<pair<Trigger, State>>> rules;
    State current_state {State::Start};
    State exitState {State::Quit};
    
    void init_rules(){
        rules[State::Start] = {
            {Trigger::ToLocation,State::InLocation}
        };
        rules[State::InLocation] = {
            {Trigger::ToLocation,State::InLocation},
            {Trigger::ToBuy,State::Buy},
            {Trigger::ToSell,State::Sell},
            {Trigger::EndGame,State::Quit}
        };
        rules[State::Buy] = {
            {Trigger::ToLocation,State::InLocation},            
        };
        rules[State::Sell] = {
            {Trigger::ToLocation,State::InLocation}
        };
    }
    public:
        GameFST(){};
        void play(){
            while(true){
                cout << current_state;
                select_trigger:
                cout << "Wybierz akcję: " << endl;
                int i =0;
                for (auto item : rules[current_state])
                {
                    cout << i++ << item.first << endl;
                }
                int input;
                cin >> input;
                if(input < 0 || (input + 1) > rules[current_state].size())
                {
                    cout << "Nieprawidłowa opcja. Spróbuj jeszce raz." << endl;
                    goto select_trigger;
                }

                current_state = rules[current_state][input].second;
                if(current_state == exitState) break;
            }
        }
};