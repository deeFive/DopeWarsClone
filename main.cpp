#include "headers/drug.hpp"
#include "headers/player.hpp"
#include "headers/commandBuyDrug.hpp"
#include "headers/instance.hpp"
#include "headers/consolePlayerObserver.hpp"
#include "headers/drugsListModel.hpp"
#include "headers/commandSetNewDrugList.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main() {
    Player player{"mic"};
    DrugsListModel drugs_list_model;    
    ConsolePlayerObserver consoleNotify;
    Instance new_york{"New york"};
    CommandBuyDrugs buyHera(player,new_york,10,"Speed");
    CommandSetNewDrugList set_new_drugs_list(drugs_list_model,new_york);
    player.subscribe(&consoleNotify);
    set_new_drugs_list.call();
    buyHera.call();
    set_new_drugs_list.call();
    // this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(5));
    buyHera.call();
    
    return 0;
}