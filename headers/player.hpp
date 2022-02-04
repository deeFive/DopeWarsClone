#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "drug.hpp"
#include "Observable.hpp"

using namespace std;

class Player : public Observable<Player>
{
    string name;
    int maney;

public:
    vector<Drug> player_drugs;
    Player(const string &name_) : name{name_}, maney{2000}
    {
    }
    Player(): name{"default"} ,maney{2000} {};
    const string &get_name() const
    {
        return name;
    }
    void set_name(const string &player_name_)
    {
        if (name != player_name_)
            name = player_name_;
        notify(*this, "name");
    }
    int get_maney() const
    {
        return maney;
    }
    void add_maney(int value)
    {
        if (value < 0)
            throw runtime_error("Value ma wartość ujemną. Nie dodajesz pieniędzy.");
        else
            maney += value;
        notify(*this, "maney");
    }
    void subtract_maney(int value)
    {
        if (value < 0)
            throw runtime_error("Value ma wartość ujemną. Nie odejmujesz pieniędzy.");
        else
            maney -= value;
        notify(*this, "maney");
    }
    void add_drug(Drug drug_)
    {
        bool is_in_list = false;
        for (auto &obj : player_drugs)
        {
            if (drug_.get_name() == obj.get_name())
            {
                int objValue = (obj.get_amount() * obj.get_price());
                int drugValue = (drug_.get_amount() * drug_.get_price());
                int totalAmount = (obj.get_amount() + drug_.get_amount());
                obj.set_price((objValue + drugValue)/totalAmount);
                obj.set_amount(totalAmount);
                is_in_list = true;
            }
        }
        if (is_in_list == false)
            player_drugs.push_back(drug_);
    }
    void add_drug(const string& drug_name, int amount)
    {
        for (auto &obj : player_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() + amount);
        }
        throw runtime_error("Niepowiodła się operacja dodania narkotyku.");
    }
    void substruct_drug(const string& drug_name, int amount)
    {
        for (auto &obj : player_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() - amount);
        }
        throw runtime_error("Niepowiodła się operacja odjęcia narkotyku.");
    }
    void list_player_drugs() const
    {
        for (const auto &drug : player_drugs)
        {
            cout << drug << endl;
        }
    }
};