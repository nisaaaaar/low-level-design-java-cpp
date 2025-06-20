# 🧠 Singleton Design Pattern in C++

## 📌 Overview

The **Singleton Design Pattern** ensures that a class has **only one instance** and provides a **global point of access** to it. It's commonly used in C++ for shared resources like loggers, configuration managers, or device drivers.

---

## 🧰 Real-World Examples

* Logger
* Configuration manager
* Thread pool
* Cache
* Device driver objects

---

## 🛠️ Methods to Implement Singleton in C++

### 1. Eager Initialization

```cpp
class EagerSingleton {
private:
    static EagerSingleton instance;
    EagerSingleton() {}

public:
    EagerSingleton(const EagerSingleton&) = delete;
    EagerSingleton& operator=(const EagerSingleton&) = delete;

    static EagerSingleton& getInstance() {
        return instance;
    }
};

EagerSingleton EagerSingleton::instance; // Static instance
```

**✅ Pros:**

* Thread-safe
* Simple to implement

**❌ Cons:**

* Instance is created even if unused
* No lazy loading

---

### 2. Lazy Initialization (Not Thread-Safe)

```cpp
class LazySingleton {
private:
    static LazySingleton* instance;
    LazySingleton() {}

public:
    LazySingleton(const LazySingleton&) = delete;
    LazySingleton& operator=(const LazySingleton&) = delete;

    static LazySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        return instance;
    }
};

LazySingleton* LazySingleton::instance = nullptr;
```

**✅ Pros:**

* Lazy initialization

**❌ Cons:**

* Not thread-safe
* Risk of multiple instances in multithreaded environments

---

### 3. Thread-Safe Singleton Using `std::mutex`

```cpp
#include <mutex>

class ThreadSafeSingleton {
private:
    static ThreadSafeSingleton* instance;
    static std::mutex mtx;
    ThreadSafeSingleton() {}

public:
    ThreadSafeSingleton(const ThreadSafeSingleton&) = delete;
    ThreadSafeSingleton& operator=(const ThreadSafeSingleton&) = delete;

    static ThreadSafeSingleton* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new ThreadSafeSingleton();
        }
        return instance;
    }
};

ThreadSafeSingleton* ThreadSafeSingleton::instance = nullptr;
std::mutex ThreadSafeSingleton::mtx;
```

**✅ Pros:**

* Thread-safe
* Lazy-loaded

**❌ Cons:**

* Performance overhead due to locking

---

### 4. Double-Checked Locking (C++11 and later)

```cpp
#include <mutex>

class DCLSingleton {
private:
    static DCLSingleton* instance;
    static std::mutex mtx;
    DCLSingleton() {}

public:
    DCLSingleton(const DCLSingleton&) = delete;
    DCLSingleton& operator=(const DCLSingleton&) = delete;

    static DCLSingleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new DCLSingleton();
            }
        }
        return instance;
    }
};

DCLSingleton* DCLSingleton::instance = nullptr;
std::mutex DCLSingleton::mtx;
```

**✅ Pros:**

* Thread-safe
* Efficient
* Lazy initialization

**❌ Cons:**

* Slightly complex
* Manual memory management

---

### 5. Meyers Singleton (Recommended)

```cpp
class MeyersSingleton {
private:
    MeyersSingleton() {}

public:
    MeyersSingleton(const MeyersSingleton&) = delete;
    MeyersSingleton& operator=(const MeyersSingleton&) = delete;

    static MeyersSingleton& getInstance() {
        static MeyersSingleton instance;
        return instance;
    }
};
```

**✅ Pros:**

* Thread-safe (since C++11)
* Lazy-loaded
* No locking overhead
* Simple syntax

**❌ Cons:**

* Less control over destruction order in multithreaded context

---

### 6. Singleton with Smart Pointer (optional pattern)

```cpp
#include <memory>

class SmartSingleton {
private:
    static std::unique_ptr<SmartSingleton> instance;
    SmartSingleton() {}

public:
    SmartSingleton(const SmartSingleton&) = delete;
    SmartSingleton& operator=(const SmartSingleton&) = delete;

    static SmartSingleton* getInstance() {
        if (!instance) {
            instance = std::make_unique<SmartSingleton>();
        }
        return instance.get();
    }
};

std::unique_ptr<SmartSingleton> SmartSingleton::instance = nullptr;
```

**✅ Pros:**

* Uses smart pointer for memory safety
* Lazy-loaded

**❌ Cons:**

* Not thread-safe unless wrapped with `std::mutex`

---

## 📊 Comparison Table

| Method                  | Lazy | Thread-Safe       | Performance | Memory Safety | Simplicity |
| ----------------------- | ---- | ----------------- | ----------- | ------------- | ---------- |
| Eager Initialization    | ❌    | ✅                 | ✅           | ✅             | ✅          |
| Lazy Initialization     | ✅    | ❌                 | ✅           | ❌             | ✅          |
| Thread-Safe (`mutex`)   | ✅    | ✅                 | ❌           | ❌             | ✅          |
| Double-Checked Locking  | ✅    | ✅                 | ✅           | ❌             | ❌          |
| Meyers Singleton        | ✅    | ✅                 | ✅           | ✅             | ✅          |
| Smart Pointer Singleton | ✅    | ❌ (unless locked) | ✅           | ✅             | ✅          |

---

## 🎯 When to Use Which?

| Scenario                                 | Recommended Method      |
| ---------------------------------------- | ----------------------- |
| Always-needed simple instance            | Eager Initialization    |
| Lazy + safe + simple                     | Meyers Singleton (✅)    |
| Performance-sensitive multithreaded apps | Double-Checked Locking  |
| Prefer RAII & memory safety              | Smart Pointer Singleton |
| Learning or demo purposes                | Lazy or Thread-Safe     |

---

## ⚠️ Pitfalls to Avoid

* Forgetting to delete copy constructor and assignment operator
* Ignoring thread safety in multithreaded scenarios
* Manual memory leaks if using `new` without smart pointers
* Complicated logic in Singleton class (violates SRP)

---

## ✅ Best Practices

* Use Meyers Singleton for most cases
* Prefer smart pointers for memory safety
* Ensure thread safety if accessed concurrently
* Keep Singleton focused on *only one* responsibility

---

## 📚 References

* *Design Patterns: Elements of Reusable Object-Oriented Software* (GoF)
* *Effective Modern C++* by Scott Meyers
* cppreference.com – [Singleton Pattern](https://en.cppreference.com)
* C++ Core Guidelines by ISO/CPP