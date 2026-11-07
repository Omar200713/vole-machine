#ifndef VOLE_MACHINE_MENU_H
#define VOLE_MACHINE_MENU_H
#include "SimulatorController.h"

class Menu {
private:
    SimulatorController controller;
    void showMenu();
    int readChoice();
    public:
    void run();
};
#endif //VOLE_MACHINE_MENU_H