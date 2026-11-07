#include "DisplayManager.h"
#include <iomanip>
#include <iostream>
#include "Memory.h"

void DisplayManager::displayMemoryMatrix(const Memory& mem) {
    std::cout << std::hex << std::uppercase
    << std::setfill('0') ;std::cout << "  ";
    for (int c = 0; c < 16; c++) {
        std::cout << std::setw(2) << c << " ";
    }
    std::cout << std::endl;
        for (unsigned i = 0; i < 16; i++) {
            std::cout <<i<<" ";
            for (unsigned j = 0; j < 16; j++) {
                unsigned addr = i * 16 + j;
                std::cout<< std::setw(2)<<static_cast<int>(mem.read(addr) )<<" ";
            }
            std::cout << std::endl;

        }
       std::cout<< std::dec << std::nouppercase << std::setfill(' ');
    }
