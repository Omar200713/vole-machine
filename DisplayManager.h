#ifndef VOLE_MACHINE_DISPLAYMANAGER_H
#define VOLE_MACHINE_DISPLAYMANAGER_H
#include "Machine.h"
#include "Memory.h"
class DisplayManager {
public:
    void displayMachineState(const Machine &machine);
    static void displayMemoryMatrix(const Memory &mem);
};

#endif
