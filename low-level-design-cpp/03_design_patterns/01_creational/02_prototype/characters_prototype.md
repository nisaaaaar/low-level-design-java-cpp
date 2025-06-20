## 🎮 Scenario (C++ Version)

* You have enemy types like **Orc** and **Troll**.
* Each enemy has attributes like `name`, `weapon`, and `health`.
* Instead of creating new enemies from scratch, you **clone a prototype** and tweak attributes as needed.

---

### 📦 Step-by-Step C++ Code

---

### 🔹 1. Enemy Prototype Interface

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Enemy {
public:
    virtual void attack() const = 0;
    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual ~Enemy() = default;
};
```

---

### 🔹 2. Concrete Class: Orc

```cpp
class Orc : public Enemy {
private:
    std::string name;
    std::string weapon;
    int health;

public:
    Orc(const std::string& name, const std::string& weapon, int health)
        : name(name), weapon(weapon), health(health) {}

    void attack() const override {
        std::cout << name << " attacks with " << weapon << "! (Health: " << health << ")\n";
    }

    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Orc>(*this);
    }

    void setName(const std::string& newName) { name = newName; }
    void setHealth(int newHealth) { health = newHealth; }
};
```

---

### 🔹 3. Concrete Class: Troll

```cpp
class Troll : public Enemy {
private:
    std::string name;
    std::string weapon;
    int health;

public:
    Troll(const std::string& name, const std::string& weapon, int health)
        : name(name), weapon(weapon), health(health) {}

    void attack() const override {
        std::cout << name << " smashes with " << weapon << "! (Health: " << health << ")\n";
    }

    std::unique_ptr<Enemy> clone() const override {
        return std::make_unique<Troll>(*this);
    }

    void setName(const std::string& newName) { name = newName; }
    void setHealth(int newHealth) { health = newHealth; }
};
```

---

### 🔹 4. Enemy Factory (Prototype Registry)

```cpp
class EnemyFactory {
private:
    static std::unordered_map<std::string, std::unique_ptr<Enemy>> prototypes;

public:
    static void initialize() {
        prototypes["orc"] = std::make_unique<Orc>("Orc Warrior", "Axe", 100);
        prototypes["troll"] = std::make_unique<Troll>("Troll Brute", "Club", 150);
    }

    static std::unique_ptr<Enemy> getEnemy(const std::string& type) {
        auto it = prototypes.find(type);
        if (it != prototypes.end()) {
            return it->second->clone();
        }
        return nullptr;
    }
};

// Static member definition
std::unordered_map<std::string, std::unique_ptr<Enemy>> EnemyFactory::prototypes;
```

---

### 🔹 5. Client Code: Game Simulator

```cpp
int main() {
    EnemyFactory::initialize();

    // Clone orc and customize
    auto orc1 = std::unique_ptr<Orc>(static_cast<Orc*>(EnemyFactory::getEnemy("orc").release()));
    orc1->setName("Orc Grunt");
    orc1->setHealth(80);
    orc1->attack();

    // Clone troll and customize
    auto troll1 = std::unique_ptr<Troll>(static_cast<Troll*>(EnemyFactory::getEnemy("troll").release()));
    troll1->setName("Troll King");
    troll1->setHealth(200);
    troll1->attack();

    // Clone default prototype again
    auto orc2 = EnemyFactory::getEnemy("orc");
    orc2->attack();

    return 0;
}
```

---

### ✅ Output

```
Orc Grunt attacks with Axe! (Health: 80)
Troll King smashes with Club! (Health: 200)
Orc Warrior attacks with Axe! (Health: 100)
```

---

## 🧠 Notes

* `EnemyFactory` stores prototype objects.
* Each call to `getEnemy()` returns a **deep clone**.
* You can **tweak** the clone’s attributes independently.
* Useful in performance-sensitive applications like games, where object creation is costly.
