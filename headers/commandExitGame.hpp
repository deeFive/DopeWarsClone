#include <cstdlib>
class CommandExitGame : public Command {
    public: 
    CommandExitGame(){};
    void call()const override {
        exit(0);
    }
};