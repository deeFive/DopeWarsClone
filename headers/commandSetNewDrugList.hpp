#include "drugsListModel.hpp"
#include "instance.hpp"
#include "Command.hpp"
#include <array>

class CommandSetNewDrugList : public Command
{
    DrugsListModel & drug_list_model;
    Instance &instance;
    public:
    CommandSetNewDrugList(DrugsListModel& drug_list_model_,Instance& instance_):
    drug_list_model{drug_list_model_}, instance{instance_}{};
    void call() const override {
        auto new_model = drug_list_model.create_new_model();
        for(auto obj : new_model){
            instance.set_drugs(obj);
        }
    }
};