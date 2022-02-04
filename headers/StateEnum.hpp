#pragma once
#include "Command.hpp"

enum class EnumState
{
    Start,
    InLocation,
    Buy,
    Sell,
    YourDrugsList,
    Quit
};

enum class EnumTrigger
{
    StartGame,
    ToLocation,
    ToBuy,
    ToSell,
    ToYourDrugList,
    EndGame

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
    case EnumTrigger::ToYourDrugList: 
        os << "Aktualnie posiadasz: ";
        break;
    case EnumTrigger::EndGame:
        os << "Gra się kończy." << endl;
        break;
    }
    return os;
}