#include <vector>
#include "Observer.hpp"
#include <algorithm>

using namespace std;

template<typename T> 
class Observable {
    public:
    void notify(T& source,const string& name)
    {
        for(auto obs : observers){
            obs->field_changed(source, name);
        }
    }
    void subscribe(Observer<T> *f) {observers.push_back(f);}
    void unsubscribe(Observer<T> *f) {
        remove(begin(observers),end(observers),f);
    }
    private:
    vector<Observer<T>*> observers;
};