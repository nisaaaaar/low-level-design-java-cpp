### ✅ `02_principles/README.md`

# 📏 SOLID, DRY, and KISS Principles in Java

This document explains key design principles for writing clean, maintainable, and scalable Java code used in Low-Level Design (LLD).


## 🔹 1. SOLID Principles

The **SOLID** acronym stands for:

### ✅ S — Single Responsibility Principle (SRP)

A class should have only one reason to change.

**Java Example:**
```java
class Invoice {
    double calculateTotal() { /* logic */ }
}

class InvoicePrinter {
    void print(Invoice invoice) { /* logic */ }
}
````

**✅ Benefit:** Easier maintenance and better separation of concerns.

---

### ✅ O — Open/Closed Principle (OCP)

Software entities should be open for extension, but closed for modification.

**Java Example:**

```java
interface Discount {
    double apply(double price);
}

class PercentageDiscount implements Discount {
    public double apply(double price) {
        return price * 0.9;
    }
}

class Checkout {
    double calculatePrice(Discount discount, double price) {
        return discount.apply(price);
    }
}
```

**✅ Benefit:** Supports new functionality without altering existing code.

---

### ✅ L — Liskov Substitution Principle (LSP)

Subtypes must be substitutable for their base types.

**Java Example:**

```java
class Bird {
    void fly() { System.out.println("Flying"); }
}

class Crow extends Bird {}

class Ostrich extends Bird {
    // Violates LSP if it can't fly
}
```

**✅ Benefit:** Polymorphism works as expected without breaking behavior.

---

### ✅ I — Interface Segregation Principle (ISP)

Clients should not be forced to depend on methods they do not use.

**Java Example:**

```java
interface Printer {
    void print();
}

interface Scanner {
    void scan();
}

class LaserPrinter implements Printer {}
class Photocopier implements Printer, Scanner {}
```

**✅ Benefit:** Smaller, role-specific interfaces improve clarity.

---

### ✅ D — Dependency Inversion Principle (DIP)

Depend on abstractions, not concrete implementations.

**Java Example:**

```java
interface MessageService {
    void send(String msg);
}

class EmailService implements MessageService {
    public void send(String msg) {
        System.out.println("Email: " + msg);
    }
}

class Notification {
    private MessageService service;

    Notification(MessageService service) {
        this.service = service;
    }

    void alert(String msg) {
        service.send(msg);
    }
}
```

**✅ Benefit:** Promotes decoupling and testability.

---

## 🔹 2. DRY Principle — Don’t Repeat Yourself

**Definition:** Avoid code duplication; extract common logic into reusable methods or classes.

**Java Example:**

```java
// ❌ Bad (repeated logic)
if (user.role.equals("admin")) { /* check */ }
if (admin.role.equals("admin")) { /* check */ }

// ✅ Good
boolean isAdmin(User user) {
    return user.getRole().equals("admin");
}
```

**✅ Benefit:** Reduces bugs, improves reusability, easier refactoring.

---

## 🔹 3. KISS Principle — Keep It Simple, Stupid

**Definition:** Simpler solutions are easier to understand and maintain.

**Java Example:**

```java
// ❌ Overcomplicated
public boolean isEven(int n) {
    return (n % 2 == 0) ? true : false;
}

// ✅ Simple
public boolean isEven(int n) {
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
