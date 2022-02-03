#include "headers/drug.hpp"
#include "headers/player.hpp"
#include "headers/commandBuyDrug.hpp"
#include "headers/instance.hpp"
#include "headers/consolePlayerObserver.hpp"
#include "headers/drugsListModel.hpp"
#include "headers/commandSetNewDrugList.hpp"
#include "State.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main() {
    Player player{"mic"};
    DrugsListModel drugs_list_model;    
    ConsolePlayerObserver consoleNotify;
    Instance new_york{"New york"};
    CommandBuyDrugs *buyHera;
    CommandSetNewDrugList set_new_drugs_list(drugs_list_model,new_york);
    player.subscribe(&consoleNotify);
    set_new_drugs_list.call();
    buyHera = new CommandBuyDrugs(player,new_york,20,"Speed");
    buyHera->call();
    set_new_drugs_list.call();
    delete buyHera;
    buyHera = new CommandBuyDrugs(player,new_york,10,"Speed");
    buyHera->call();
    player.list_player_drugs();
    
    return 0;
}