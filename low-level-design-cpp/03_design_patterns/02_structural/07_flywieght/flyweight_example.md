## ✅ Definition

**Flyweight Pattern** is a **structural design pattern** that:

> “Reduces memory usage by sharing common parts of state between multiple objects instead of keeping all data in each object.”

It introduces **shared objects** to support a **large number of fine-grained objects efficiently**.

---

## 🎯 Analogy

> Think of **characters in a document editor**:

* Every time you type a letter, an object is created.
* But instead of creating a new object for every "a", "b", etc., the editor **reuses shared flyweight objects** for characters and only stores **position** separately.

---

## 💻 Real-World Code Example (C++)

Let’s model a **Character rendering system** (like in a text editor).

### ✅ Classes:

* `Character` (Flyweight Interface)
* `ConcreteCharacter` (Shared object)
* `CharacterFactory` (Manages flyweights)
* `CharacterContext` (Holds extrinsic state like position)
* `Client` (Uses the flyweights)

```cpp
#include <iostream>
#include <unordered_map>
#include <memory>

// Flyweight Interface
class Character {
public:
    virtual void display(int position) const = 0;
    virtual ~Character() = default;
};

// Concrete Flyweight
class ConcreteCharacter : public Character {
private:
    char symbol; // intrinsic state (shared)

public:
    ConcreteCharacter(char c) : symbol(c) {}

    void display(int position) const override {
        std::cout << "Character '" << symbol << "' at position " << position << std::endl;
    }
};

// Flyweight Factory
class CharacterFactory {
private:
    std::unordered_map<char, std::shared_ptr<Character>> characters;

public:
    std::shared_ptr<Character> getCharacter(char c) {
        if (characters.find(c) == characters.end()) {
            characters[c] = std::make_shared<ConcreteCharacter>(c);
        }
        return characters[c];
    }
};

// Client
int main() {
    CharacterFactory factory;

    std::shared_ptr<Character> a1 = factory.getCharacter('a');
    std::shared_ptr<Character> a2 = factory.getCharacter('a');
    std::shared_ptr<Character> b1 = factory.getCharacter('b');

    // Even though we request multiple 'a's, only one object is created
    a1->display(1); // Character 'a' at position 1
    a2->display(2); // Character 'a' at position 2
    b1->display(3); // Character 'b' at position 3

    std::cout << "Are a1 and a2 the same object? " << (a1 == a2 ? "Yes" : "No") << std::endl;

    return 0;
}
```

---

## ✅ Output

```
Character 'a' at position 1
Character 'a' at position 2
Character 'b' at position 3
Are a1 and a2 the same object? Yes
```

---

## ✅ UML Diagram

```
         +----------------+
         |   Character    |<<interface>>
         +----------------+
         | +display(pos)  |
         +----------------+
                 /_\
                  |
         +---------------------+
         |  ConcreteCharacter  |
         +---------------------+
         | -symbol             |
         | +display(pos)       |
         +---------------------+

         +---------------------+
         |  CharacterFactory   |
         +---------------------+
         | -map<char,Character>|
         | +getCharacter(char) |
         +---------------------+
```

---

## ✅ Key Benefits

* **Memory efficient**: Reduces memory footprint when many similar objects are needed.
* **Performance boost** in systems with large data sets.
* Follows **object sharing**, avoiding duplication.

---

## ✅ When to Use

* You have **a large number of similar objects** (e.g., characters, icons, tiles).
* Most of the object data is **shared (intrinsic)**, and only a small part is **unique (extrinsic)**.
* You want to **optimize memory usage**.

---

## ❗ Limitations or Caveats

* Adds **complexity** in separating intrinsic/extrinsic data.
* May **not help** if objects are too distinct or frequently modified.
* Requires **careful design** to avoid unintended shared state issues.

---

## ✅ SOLID Principles

* ✅ **S**ingle Responsibility: Each class has a clear, focused purpose.
* ✅ **O**pen/Closed: Add new characters without modifying factory or existing code.
* ✅ **L**iskov Substitution: Clients use `Character` interface for real or shared characters.
* ✅ **I**nterface Segregation: `Character` interface is simple and focused.
* ✅ **D**ependency Inversion: Client depends on `Character` abstraction, not implementation.

---

## 🌍 Real-World Use Cases

* **Text rendering**: Characters, fonts, symbols (e.g., MS Word, PDF viewers).
* **Game development**: Repeating game tiles (grass, water), trees in forests.
* **CAD software**: Reusing visual elements like bolts or nuts.
* **Document editors**: Reusing formatting styles or emojis.

---

## 📝 Interview Summary

> The **Flyweight pattern** helps reduce memory usage by **sharing objects** that have **common intrinsic state**, while separating out the varying extrinsic data. For example, a text editor may only create one `Character` object per symbol and reuse it for different positions. It’s great when we need to create **millions of similar objects efficiently**, like in games or rendering engines.


