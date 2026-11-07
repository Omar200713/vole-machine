#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include<cstdint>

class Memory {
    private:
uint8_t cells[256]={};
    public:
    uint8_t read(uint8_t addr) const {return cells[addr];}
    void write(uint8_t addr,uint8_t value){cells[addr]=value;}
};


#endif //VOLE_MACHINE_MEMORY_H