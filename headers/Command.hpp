#pragma once
#include "StateEnum.hpp"
struct Command {
    EnumState state;
    void set_state(EnumState state_) {
        state = state_;
    }
    EnumState get_state()const {
        return state;
    }
    Command() {};
    Command(Command&t) {state = t.state;};
    virtual void call() const =0;
};

inline ostream &operator<<(ostream &os, const Command &c)
{
    EnumState s = c.get_state();
    switch (s)
    {
    case EnumState::Start:
        os << "Start." << endl;
        c.call();
        break;
    case EnumState::InLocation:
        os << "Gracz znajduje się w lokacji." << endl;
        c.call();
        break;
    case EnumState::Buy:
        os << "Kup narkotyk: " << endl;
        c.call();
        break;
    case EnumState::Sell:
        os << "Sprzedaj narkotyk: " << endl;
        c.call();
        break;
    case EnumState::Quit:
        os << "Koniec gry" << endl;
        c.call();
        break;
    }
    return os;
}