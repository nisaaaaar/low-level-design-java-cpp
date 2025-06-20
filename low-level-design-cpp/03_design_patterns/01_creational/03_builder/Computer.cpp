#include <iostream>
#include <string>

class Computer {
private:
    // Required parameters
    std::string CPU;
    std::string RAM;

    // Optional parameters
    bool hasGraphicsCard;
    bool hasBluetooth;

    // Private constructor
    Computer(const std::string& cpu, const std::string& ram, bool graphics, bool bluetooth)
        : CPU(cpu), RAM(ram), hasGraphicsCard(graphics), hasBluetooth(bluetooth) {}

public:
    // Builder Class
    class Builder {
    private:
        std::string CPU;
        std::string RAM;
        bool hasGraphicsCard = false;
        bool hasBluetooth = false;

    public:
        Builder(const std::string& cpu, const std::string& ram)
            : CPU(cpu), RAM(ram) {}

        Builder& setGraphicsCard(bool value) {
            hasGraphicsCard = value;
            return *this;
        }

        Builder& setBluetooth(bool value) {
            hasBluetooth = value;
            return *this;
        }

        Computer build() {
            return Computer(CPU, RAM, hasGraphicsCard, hasBluetooth);
        }
    };

    // Output description
    void printSpecs() const {
        std::cout << "Computer [CPU=" << CPU
                  << ", RAM=" << RAM
                  << ", GraphicsCard=" << (hasGraphicsCard ? "true" : "false")
                  << ", Bluetooth=" << (hasBluetooth ? "true" : "false")
                  << "]" << std::endl;
    }
};