#pragma once
#include <array>
#include <random>
#include "drugInstance.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class DrugsListModel
{
    vector<DrugInstance> drugs_list_model 
    {
        DrugInstance{"Hera", 0, 1000, 300, 600},
            DrugInstance{"Speed", 0, 1000, 40, 150},
            DrugInstance{"Trawka", 0, 1000, 20, 60},
            DrugInstance{"Haszysz", 0, 1000, 30, 150},
    };

public:

    void set_price(DrugInstance &obj_)
    {
        random_device seed; 
        mt19937 gen{seed()};                  
        uniform_int_distribution dist{obj_.get_min_price(), obj_.get_max_price()}; 
        obj_.set_price(dist(gen));
    }
    DrugsListModel(){
        for(auto &obj : drugs_list_model){
            set_price(obj);
        }
    }
    vector<DrugInstance>& create_new_model()
    {
    
        for(auto & obj :drugs_list_model){
            set_price(obj);
        }
        return drugs_list_model;
    } 
};