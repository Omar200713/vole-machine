//
// Created by 7750 on 11/4/2026.
//

#ifndef VOLE_MACHINE_SIMULATORCONTROLLER_H
#define VOLE_MACHINE_SIMULATORCONTROLLER_H
#include<cstdint>
#include<string>
#include "Machine.h"
class SimulatorController {
    private:
    Machine machine;
    public:
    bool loadProgram(const std::string& fileName,uint8_t startAddr);
    void editRegister(uint8_t r,uint8_t value);
    void editMemory(uint8_t addr,uint8_t value);
    void runAll();
    void runStep();
    void displayStatus();
    void reset();


};
#endif //VOLE_MACHINE_SIMULATORCONTROLLER_H