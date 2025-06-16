### ✅ `01_prerequisites/README.md`

# 📘 Java Prerequisites for Low-Level Design (LLD)

This document covers the essential Java concepts you must be comfortable with before diving into Low-Level Design (LLD). Each section includes explanations and examples to help reinforce your understanding.


## ✅ 1. Java Basics

### Topics:
- Variables and data types
- Control flow: `if`, `switch`, loops
- Arrays, Strings

```java
int[] arr = {1, 2, 3};
for (int num : arr) {
    System.out.println(num);
}
````

---

## ✅ 2. Object-Oriented Programming (OOP) Concepts

### Concepts:

* Class and Object
* Inheritance
* Polymorphism
* Encapsulation
* Abstraction

```java
class Animal {
    void speak() {
        System.out.println("Animal speaks");
    }
}

class Dog extends Animal {
    void speak() {
        System.out.println("Dog barks");
    }
}
```

---

## ✅ 3. Access Modifiers & Keywords

### Access Modifiers:

* `public`, `private`, `protected`, default

### Keywords:

* `this`, `super`, `final`, `static`

```java
public class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }
}
```

---

## ✅ 4. Interfaces and Abstract Classes

```java
interface Vehicle {
    void start();
}

abstract class Engine {
    abstract void ignite();
}

class Car implements Vehicle {
    public void start() {
        System.out.println("Car starting...");
    }
}
```

---

## ✅ 5. Enums, Static Blocks, and Inner Classes

```java
enum Role {
    ADMIN, USER, GUEST
}

class Example {
    static {
        System.out.println("Static block executed");
    }

    class Inner {
        void display() {
            System.out.println("Inner class");
        }
    }
}
```

---

## ✅ 6. Java Collections Framework

### Key Interfaces & Classes:

* `List`, `Set`, `Map`, `Queue`
* `ArrayList`, `HashMap`, `HashSet`, `LinkedList`

```java
List<String> names = new ArrayList<>();
names.add("Alice");
System.out.println(names.get(0));
```

---

## ✅ 7. Method Overriding (`equals`, `hashCode`, `toString`)

```java
@Override
public boolean equals(Object obj) {
    if (this == obj) return true;
    if (!(obj instanceof MyClass)) return false;
    MyClass other = (MyClass) obj;
    return this.id == other.id;
}
```

---

## ✅ 8. Exception Handling

```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero!");
}
```

---

## ✅ 9. Design Patterns Introduction

Start learning with:

* Singleton
* Factory
* Builder
* Strategy
* Observer

Example (Singleton):

```java
class Singleton {
    private static Singleton instance;
    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == null)
            instance = new Singleton();
        return instance;
    }
}
```

---

## ✅ 10. Best Practices in Java

* Use meaningful class and variable names
* Favor **composition over inheritance**
* Write **modular** and **testable** code
* Keep classes **single-responsibility**
* Use **interfaces** for extensibility

---