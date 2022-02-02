#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "drug.hpp"

using namespace std;

class DrugInstance : public Drug
{
private:
    int min_price;
    int max_price;

public:
    DrugInstance(string name_, int price_, int amount_, int min_price_, int max_price_) : Drug{name_, price_, amount_}, min_price{min_price_}, max_price{max_price_} {};
    DrugInstance(const Drug& drug_,int min_price_,int max_price_) : Drug{drug_},min_price{min_price_},max_price{max_price_} {};
    DrugInstance(const DrugInstance& tmp):Drug{tmp.get_name(),tmp.get_price(),tmp.get_amount()},
    min_price{tmp.get_min_price()}, max_price{tmp.get_max_price()}{};
    DrugInstance& operator=(const DrugInstance& tmp){
        this->set_name(tmp.get_name());
        this->set_price(tmp.get_price());
        this->set_amount(tmp.get_amount());
        this->set_min_price(tmp.get_min_price());
        this->set_max_price(tmp.get_max_price());
        return *this;
    }
    void set_min_price(int value)
    {
        if (value < 0)
            throw runtime_error("Value jest mniejesze od zera.");
        else
            min_price = value;
    }
    int get_min_price() const
    {
        return min_price;
    }
    void set_max_price(int value)
    {
        if (value < 0)
            throw runtime_error("Value jest mniejesze od zera.");
        else
            max_price = value;
    }
    int get_max_price() const
    {
        return max_price;
    }
};