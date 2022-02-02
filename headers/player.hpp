#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "drug.hpp"
#include "Observable.hpp"

using namespace std;

class Player :public Observable<Player>
{
    string name;
    int maney;
public:
    vector<Drug> player_drugs;
    Player(string name_) : name{name_}, maney{2000}
    {
        cout << "Utworzono gracza o nazwie: " << name << '\n';
    }
    const string& get_name() const {
        return name;
    }
    void set_name(const string player_name_){
        if(name != player_name_)
            name = player_name_;
        notify(*this,"name");
    }
    int get_maney() const 
    {
        return maney;
    }
    void add_maney(int value){
        if(value < 0)
            throw runtime_error("Value ma wartość ujemną. Nie dodajesz pieniędzy.");
        else
            maney += value;
            notify(*this,"maney");
    }
    void subtract_maney(int value) {
        if (value < 0)
            throw runtime_error("Value ma wartość ujemną. Nie odejmujesz pieniędzy.");
        else
            maney -= value;
            notify(*this,"maney");
    }
    void list_player_drugs() const{
        for(const auto& drug : player_drugs){
            cout << drug << '\n';
        }
    }
};