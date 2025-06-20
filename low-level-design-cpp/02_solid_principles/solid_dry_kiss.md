### ✅ `02_principles/README.md`

# 📏 SOLID, DRY, and KISS Principles in C++

This document explains key design principles for writing clean, maintainable, and scalable **C++** code used in Low-Level Design (LLD).

---

## 🔹 1. SOLID Principles

The **SOLID** acronym stands for:

---

### ✅ S — Single Responsibility Principle (SRP)

A class should have only **one reason to change**.

**C++ Example:**

```cpp
class Invoice {
public:
    double calculateTotal() {
        // calculation logic
        return 100.0;
    }
};

class InvoicePrinter {
public:
    void print(const Invoice& invoice) {
        std::cout << "Total: " << invoice.calculateTotal();
    }
};
```

**✅ Benefit:** Easier maintenance and better separation of concerns.

---

### ✅ O — Open/Closed Principle (OCP)

Software entities should be **open for extension**, but **closed for modification**.

**C++ Example:**

```cpp
class Discount {
public:
    virtual double apply(double price) = 0;
    virtual ~Discount() = default;
};

class PercentageDiscount : public Discount {
public:
    double apply(double price) override {
        return price * 0.9;
    }
};

class Checkout {
public:
    double calculatePrice(Discount* discount, double price) {
        return discount->apply(price);
    }
};
```

**✅ Benefit:** Supports new functionality without altering existing code.

---

### ✅ L — Liskov Substitution Principle (LSP)

Subtypes must be **substitutable** for their base types.

**C++ Example:**

```cpp
class Bird {
public:
    virtual void fly() {
        std::cout << "Flying\n";
    }
    virtual ~Bird() = default;
};

class Crow : public Bird {};

class Ostrich : public Bird {
public:
    void fly() override {
        throw std::logic_error("Ostrich can't fly");  // ❌ Violates LSP
    }
};
```

**✅ Benefit:** Polymorphism works as expected without breaking behavior.

---

### ✅ I — Interface Segregation Principle (ISP)

Clients should not be forced to depend on methods they do not use.

**C++ Example:**

```cpp
class Printer {
public:
    virtual void print() = 0;
    virtual ~Printer() = default;
};

class Scanner {
public:
    virtual void scan() = 0;
    virtual ~Scanner() = default;
};

class LaserPrinter : public Printer {
public:
    void print() override {
        std::cout << "Laser printing...\n";
    }
};

class Photocopier : public Printer, public Scanner {
public:
    void print() override {
        std::cout << "Photocopier printing...\n";
    }
    void scan() override {
        std::cout << "Photocopier scanning...\n";
    }
};
```

**✅ Benefit:** Smaller, role-specific interfaces improve clarity.

---

### ✅ D — Dependency Inversion Principle (DIP)

Depend on **abstractions**, not **concrete implementations**.

**C++ Example:**

```cpp
class MessageService {
public:
    virtual void send(const std::string& msg) = 0;
    virtual ~MessageService() = default;
};

class EmailService : public MessageService {
public:
    void send(const std::string& msg) override {
        std::cout << "Email: " << msg << '\n';
    }
};

class Notification {
    MessageService* service;
public:
    Notification(MessageService* s) : service(s) {}

    void alert(const std::string& msg) {
        service->send(msg);
    }
};
```

**✅ Benefit:** Promotes decoupling and testability.

---

## 🔹 2. DRY Principle — Don’t Repeat Yourself

**Definition:** Avoid code duplication; extract common logic into reusable methods or classes.

**C++ Example:**

```cpp
// ❌ Bad (repeated logic)
if (user.role == "admin") { /* check */ }
if (admin.role == "admin") { /* check */ }

// ✅ Good
bool isAdmin(const User& user) {
    return user.role == "admin";
}
```

**✅ Benefit:** Reduces bugs, improves reusability, easier refactoring.

---

## 🔹 3. KISS Principle — Keep It Simple, Stupid

**Definition:** Simpler solutions are easier to understand and maintain.

**C++ Example:**

```cpp
// ❌ Overcomplicated
bool isEven(int n) {
    return (n % 2 == 0) ? true : false;
}

// ✅ Simple
bool isEven(int n) {
    return n % 2 == 0;
}
```

**✅ Benefit:** Easier code reviews, better readability, faster debugging.

---

## 📌 Summary Table

| Principle | Focus                        | Key Benefit                    |
| --------- | ---------------------------- | ------------------------------ |
| SRP       | One responsibility per class | Easier maintenance             |
| OCP       | Extend without changing code | Scalability                    |
| LSP       | Replace parent with child    | Reliable polymorphism          |
| ISP       | Role-specific interfaces     | Cleaner dependencies           |
| DIP       | Abstraction over concrete    | Flexibility, testability       |
| DRY       | Avoid code duplication       | Reduces bugs and redundancy    |
| KISS      | Simplicity over complexity   | Easier to understand and debug |