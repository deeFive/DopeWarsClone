#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "drug.hpp"
#include <algorithm>

using namespace std;

class Instance
{
    string name;

public:
    vector<Drug> instance_drugs;
    Instance(string name_) : name{name_}
    {
        instance_drugs.push_back(Drug{"Hera", 100, 100});
    }
    Drug get_drug(string drug_name_)
    {
        for (const auto drug : instance_drugs)
        {
            if (drug.get_name() == drug_name_)
                return drug;
        }
        return Drug{"Empty", 0, 0};
    }
    void add_drug(string drug_name, int amount)
    {
        for (auto &obj : instance_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() + amount);
        }
        throw runtime_error("Niepowiodła się operacja dodania narkotyku.");
    }
    void substruct_drug(string drug_name, int amount)
    {
        for (auto &obj : instance_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() - amount);
        }
        throw runtime_error("Niepowiodła się operacja odjęcia narkotyku.");
    }

    void list_all_drugs() const
    {
        for (const auto obj : instance_drugs)
            cout << obj << '\n';
    }
};