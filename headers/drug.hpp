#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Drug
{
    string name;
    int price;
    int amount;

public:
    Drug(string name_, int price_, int amount_) : name{name_}, price{price_}, amount{amount_} {};
    Drug(string name_) : name{name_}, price{0}, amount{0} {};
    void set_price(int value)
    {
        if (value < 0)
            throw runtime_error("value is less than zero.");
        else
            price = value;
    }
    const int get_price() const
    {
        return price;
    }
    void set_amount(int value)
    {
        if (value < 0)
            throw runtime_error("value is less than zero.");
        else
            amount = value;
    }
    const int get_amount() const
    {
        return amount;
    }
    void set_name(const string& value)
    {
        name = value;
    }
    string get_name() const
    {
        if (name.c_str() != "")
            return name;
        
    }
    Drug& operator=(Drug& obj) =default;
    friend ostream & operator<<(ostream &os, const Drug& obj){
        return os << obj.name << " ilość: " << obj.amount << " wartość: " << obj.price;
    }
    friend istream & operator>>(istream &is, Drug & obj){
        cout << "Podaj nazwę: ";
        is >> obj.name;
        cout << "\nPodaj ilość: ";
        is >> obj.amount;
        cout << "\nPodaj cenę: ";
        is >> obj.price;
        return is;
    }
};