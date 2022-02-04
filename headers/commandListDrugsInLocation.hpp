#include "Command.hpp"
#include "instance.hpp"


class CommandListDrugsInLocation : public Command {
    Instance &instance;
    public:
        CommandListDrugsInLocation(Instance &instance_):instance{instance_}{};
        void call()const  override {
            instance.list_all_drugs();
        }
    
};