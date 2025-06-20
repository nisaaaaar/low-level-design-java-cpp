# 📘 C++ Prerequisites for LLD – Cheatsheet with Code

This is a quick reference to all C++ concepts essential for Low-Level Design, complete with **minimal yet clear code snippets**.

---

## 🧱 1. Classes & Objects

```cpp
class Car {
public:
    void drive() { cout << "Driving"; }
};

int main() {
    Car c;
    c.drive();
}
```

---

## 🔒 2. Encapsulation & Access Specifiers

```cpp
class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) { balance += amount; }
    int getBalance() { return balance; }
};
```

---

## 🧼 3. Abstraction

```cpp
class Vehicle {
public:
    virtual void startEngine() = 0; // abstract method
};
```

---

## 🧬 4. Inheritance & Polymorphism

```cpp
class Animal {
public:
    virtual void speak() { cout << "Animal sound"; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Bark"; }
};

int main() {
    Animal* a = new Dog();
    a->speak(); // Bark
}
```

---

## 🏗️ 5. Constructors & Destructors

```cpp
class User {
public:
    User(string n) : name(n) {}
    ~User() { cout << "Destroyed"; }

private:
    string name;
};
```

---

## 🔁 6. Copy Constructor vs Assignment Operator

```cpp
class MyClass {
public:
    MyClass(const MyClass& other) { /* deep copy */ }
    MyClass& operator=(const MyClass& other) { return *this; }
};
```

---

## 🧠 7. Rule of 3 / Rule of 5

If you manage dynamic memory, define:

* Copy Constructor
* Copy Assignment
* Destructor
* (C++11) Move Constructor
* Move Assignment

---

## 💡 8. Static Members

```cpp
class Counter {
public:
    static int count;
};

int Counter::count = 0;
```

---

## 🧾 9. Virtual & Pure Virtual Functions

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual = abstract class
};
```

---

## 🔄 10. Operator Overloading

```cpp
class Point {
    int x;
public:
    Point(int x): x(x) {}
    Point operator+(const Point& other) {
        return Point(this->x + other.x);
    }
};
```

---

## 🔐 11. Friend Function (for tight access)

```cpp
class Box {
private:
    int width;
    friend void printWidth(Box);
};

void printWidth(Box b) {
    cout << b.width;
}
```

---

## 💾 12. Memory Management (`new` / `delete`)

```cpp
Car* c = new Car();
// use the object
delete c;
```

---

## 🚀 13. Smart Pointers (RAII)

```cpp
#include <memory>

std::unique_ptr<Car> car1 = std::make_unique<Car>();
std::shared_ptr<Car> car2 = std::make_shared<Car>();
```

---

## 🧰 14. Namespaces

```cpp
namespace Logger {
    void log() { cout << "Logging"; }
}

Logger::log();
```

---

## 🧵 15. Exception Handling (Basic)

```cpp
try {
    throw std::runtime_error("Error!");
} catch (const std::exception& e) {
    cout << e.what();
}
```

---

## 🔁 16. Templates (Generic Programming – optional)

```cpp
template<typename T>
class Box {
    T value;
public:
    Box(T v): value(v) {}
    T get() { return value; }
};
```

---

## 📦 17. STL Containers (Optional for LLD)

```cpp
std::vector<int> v = {1, 2, 3};
std::map<string, int> m;
```

---

## ✅ Summary Table

| Concept                    | Description                              |
| -------------------------- | ---------------------------------------- |
| Classes / Objects          | Core building blocks                     |
| OOP Principles             | Encapsulation, Inheritance, Polymorphism |
| Constructors / Destructors | Lifecycle control                        |
| Virtual / Pure Virtual     | Abstraction & polymorphism               |
| Copy vs Assignment         | Object copying semantics                 |
| Static Members             | Shared among all instances               |
| Smart Pointers             | Safer memory management                  |
| Operator Overloading       | Make classes more usable                 |
| Rule of 3 / 5              | Resource-safe design                     |
| Templates                  | Reusable class/function templates        |
| Namespaces                 | Avoid name conflicts                     |
| STL Containers             | Built-in data structures                 |
| Exception Handling         | Robust error management                  |

