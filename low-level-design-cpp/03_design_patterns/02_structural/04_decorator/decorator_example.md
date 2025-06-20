## ✅ Definition

The **Decorator Pattern** is a **structural design pattern** that:

> "**Adds new behavior to objects dynamically** without changing their structure or modifying existing code."

It uses **composition** over inheritance by wrapping objects with other objects that provide the additional behavior.

---

## 🎯 Analogy

> Think of a **coffee shop**:
> You order a **simple coffee**, and then you can **add milk**, **whipped cream**, or **sugar**.
> Each addition “decorates” the original coffee with more behavior (cost or description), without modifying the base `Coffee` class.

---

## 💻 Real-World Code Example (C++)

Let’s model a coffee ordering system using the Decorator pattern.

### ✅ Class Hierarchy:

* `Beverage` (Abstract base class)
* `Espresso`, `HouseBlend` (Concrete classes)
* `MilkDecorator`, `WhipDecorator` (Decorators)

```cpp
#include <iostream>
#include <memory>
#include <string>

// Component
class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() = default;
};

// Concrete Component 1
class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }
    double cost() const override {
        return 1.99;
    }
};

// Concrete Component 2
class HouseBlend : public Beverage {
public:
    std::string getDescription() const override {
        return "House Blend Coffee";
    }
    double cost() const override {
        return 0.89;
    }
};

// Decorator Base Class
class BeverageDecorator : public Beverage {
protected:
    std::shared_ptr<Beverage> beverage;
public:
    BeverageDecorator(std::shared_ptr<Beverage> bev) : beverage(std::move(bev)) {}
};

// Concrete Decorator 1
class MilkDecorator : public BeverageDecorator {
public:
    MilkDecorator(std::shared_ptr<Beverage> bev) : BeverageDecorator(bev) {}
    
    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return beverage->cost() + 0.30;
    }
};

// Concrete Decorator 2
class WhipDecorator : public BeverageDecorator {
public:
    WhipDecorator(std::shared_ptr<Beverage> bev) : BeverageDecorator(bev) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const override {
        return beverage->cost() + 0.50;
    }
};

// Client Code
int main() {
    std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();
    beverage = std::make_shared<MilkDecorator>(beverage);
    beverage = std::make_shared<WhipDecorator>(beverage);

    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;
    return 0;
}
```

### 🧾 Output:

```
Espresso, Milk, Whip $2.79
```

---

## ✅ UML Diagram

```
         +------------------+
         |   Beverage       |<<abstract>>
         +------------------+
         | +getDescription()|
         | +cost()          |
         +------------------+
                 /_\
                  |
    ----------------------------------
    |                |              |
+---------+    +--------------+   +--------------------+
|Espresso |    |HouseBlend    |   |BeverageDecorator   |
+---------+    +--------------+   +--------------------+
                                    /_\
                                  ---------
                                  |       |
                             +--------+ +----------+
                             | Milk   | |  Whip    |
                             +--------+ +----------+
```

---

## ✅ Key Benefits

* **Adds behavior dynamically at runtime** without modifying the original class.
* Promotes **Single Responsibility Principle** – functionality is split across classes.
* More **flexible than inheritance** for behavior extension.

---

## ✅ When to Use

* You want to add **responsibilities to objects without altering their class**.
* You want to use **composition instead of inheritance**.
* You need to **combine behaviors** in various flexible ways.

---

## ❗ Limitations or Caveats

* Can lead to **lots of small classes** (many combinations of decorators).
* Debugging can be hard due to **multiple levels of wrapping**.
* Order of decorators **may matter**.

---

## ✅ SOLID Principles

* ✅ **S**ingle Responsibility: Each class has one purpose (base drink or specific add-on).
* ✅ **O**pen/Closed: Easily extendable with new decorators.
* ✅ **L**iskov Substitution: Decorators and base class are interchangeable.
* ✅ **I**nterface Segregation: Minimal and focused interface.
* ✅ **D**ependency Inversion: Depends on abstractions, not concretions.

---

## 🌍 Real-World Use Cases

* **UI Frameworks**: Adding scrollbars, borders, shadows to widgets.
* **Java I/O Streams**: `BufferedInputStream`, `DataInputStream` decorate `InputStream`.
* **Middleware / Logging**: Wrapping components with logging, auth checks, or retries.
* **Weapon systems in games**: Add-ons like silencers, scopes, damage boosters.

---

## 📝 How to Say in an Interview

> The Decorator pattern helps me **dynamically add behavior** to objects by wrapping them. For example, in a coffee ordering system, I can decorate a base coffee with milk, whip, or sugar **without modifying** the base class. It's flexible, follows the **Open/Closed Principle**, and avoids class explosion caused by subclassing every combination.

