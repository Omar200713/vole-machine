#include "Menu.h"
#include <iostream>
using namespace std;

static bool readHex(const std::string& prompt, int& out) {
    cout << prompt;
    std::string s;
    if (!std::getline(cin, s)) {
        return false;
    }

    try {
        int v = stoi(s, nullptr, 16);
        if (v < 0 || v > 255) {
            return false;
        }
        out = v;
        return true;
    } catch (...) {
        return false;
    }
}
void Menu::showMenu() {
    cout <<"\n"<< "Enter choice:" << endl;
    cout << "1)Load program" << endl;
    cout << "2)Edit register" << endl;
    cout << "3)Edit memory" << endl;
    cout << "4)Run all" << endl;
    cout << "5)Run one step" << endl;
    cout << "6)Display status" << endl;
    cout << "7)Reset" << endl;
    cout << "0)Exit" << endl;

}
int Menu::readChoice() {
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return -1;
    }
    std::cin.ignore(1000, '\n');
    return choice;
}

void Menu::run() {
    int c;
    do {
        showMenu();
        c = readChoice();
        switch (c) {
            case 1:
            {
                std::string fileName;
                cout << "Enter file name: ";
                if (!std::getline(cin, fileName)) {
                    cout << "Invalid input\n";
                    break;
                }

                int startAddr;
                if (!readHex("Enter start address (hex): ", startAddr)) {
                    cout << "Invalid address\n";
                    break;
                }
                if (startAddr % 2 != 0) {
                    cout << "Error: Start address must be even\n";
                    break;
                }

                if (controller.loadProgram(fileName, static_cast<uint16_t>(startAddr))) {
                    cout << "Program loaded successfully\n";
                } else {
                    cout << "Error: File not found or contains invalid instruction\n";
                }
                break;
            }
            case 2: {int reg, val;
                if (!readHex("Register : ", reg)) { cout << "Invalid register\n"; break; }
                if (reg > 15) { cout << "Invalid register\n"; break; }
                if (!readHex("Value : ", val)) { cout << "Invalid value\n"; break; }
                controller.editRegister(static_cast<uint8_t>(reg), static_cast<uint8_t>(val));
                cout << "Done\n";
                break;
            }
            case 3: {
                int a, b;
                if (!readHex("Address : ", a)) { cout << "Invalid address\n"; break; }
                if (!readHex("Value : ", b)) { cout << "Invalid value\n"; break; }
                controller.editMemory(static_cast<uint8_t>(a), static_cast<uint8_t>(b));
                cout << "Done\n";
                break;
            }
            case 4:
                {
                    controller.runAll();
                    cout << "Program executed\n";
                    break;
                }
            case 5:
                {
                    controller.runStep();
                    cout << "Step executed\n";
                    break;
                }
            case 6:
                {
                    controller.displayStatus();
                    break;
                }
            case 7:
                {
                    controller.reset();
                    break;
                }
            case 0:
                {
                    cout << "Exiting...\n";
                    break;
                }
            default: std::cout << "invalid choice ,try again\n";
            }
        } while (c != 0);
    }