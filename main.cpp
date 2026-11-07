#include "Memory.h"
#include "DisplayManager.h"
#include "Menu.h"
int main() {
    Menu menu;
    menu.run();
    Memory m;
    m.write(0x00, 0x11);
    m.write(0x0A, 0x22);
    m.write(0xFF, 0x33);
    DisplayManager d;
    d.displayMemoryMatrix(m);
    Menu g;
    g.run();
    return 0;

}