#include "headers/drug.hpp"
#include "headers/player.hpp"
#include "headers/commandBuyDrug.hpp"
#include "headers/instance.hpp"
#include "headers/consolePlayerObserver.hpp"
int main() {
    Player player{"mic"};
    ConsolePlayerObserver consoleNotify;
    player.subscribe(&consoleNotify);
    Instance new_york{"New york"};
    new_york.list_all_drugs();
    CommandBuyDrugs buyHera(player,new_york,10,"Hera");
    buyHera.call();
    
    return 0;
}