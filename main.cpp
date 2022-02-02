#include "headers/drug.hpp"
#include "headers/player.hpp"
#include "headers/commandBuyDrug.hpp"
#include "headers/instance.hpp"
int main() {
    Player player{"mic"};
    Instance new_york{"New york"};
    new_york.list_all_drugs();
    CommandBuyDrugs buyHera(player,new_york,10,"Hera");
    buyHera.call();
    cout << player.get_maney();
    return 0;
}