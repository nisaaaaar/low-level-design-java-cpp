## 🧱 **Builder Pattern Overview (C++)**

The **Builder Pattern** helps construct a complex object step by step. It separates **construction logic** from the final **object representation**, offering flexibility and clarity.

---

## 📦 Example Scenario: Building a `Computer`

You want to create a `Computer` with required attributes like `CPU` and `RAM`, and optional ones like `Graphics Card` and `Bluetooth`.

---

### 🔹 1. The Product Class: `Computer`

```cpp
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
```

---

### 🔹 2. Client Code: `main.cpp`

```cpp
int main() {
    Computer gamingPC = Computer::Builder("Intel i9", "32GB")
                            .setGraphicsCard(true)
                            .setBluetooth(true)
                            .build();

    Computer officePC = Computer::Builder("Intel i5", "16GB")
                            .setGraphicsCard(false)
                            .setBluetooth(true)
                            .build();

    gamingPC.printSpecs();
    officePC.printSpecs();

    return 0;
}
```

---

### ✅ Output

```
Computer [CPU=Intel i9, RAM=32GB, GraphicsCard=true, Bluetooth=true]
Computer [CPU=Intel i5, RAM=16GB, GraphicsCard=false, Bluetooth=true]
```

---

## 🧠 Benefits of Builder Pattern in C++

| Benefit                   | Explanation                             |
| ------------------------- | --------------------------------------- |
| Improves readability      | Clear, fluent object construction       |
| Avoids telescoping        | No need for overloaded constructors     |
| Immutable object creation | Built object is constructed in one step |
| Optional attributes       | Set only what is required               |

---

## ✅ When to Use Builder Pattern

* When an object has **many optional parameters**
* When you want **flexible and readable** object construction
* To prevent **constructor overload hell**
* To construct **immutable or consistent** objects

