# Singleton Design Pattern in Java

## 📌 Overview
The **Singleton Design Pattern** ensures that a class has **only one instance** and provides a **global point of access** to it. It is commonly used to control access to shared resources like configurations, logging, or database connections.

---

## 🧰 Real-World Examples
- Logger
- Configuration manager
- Thread pool
- Cache
- Device driver objects

---

## 🛠️ Methods to Implement Singleton in Java

### 1. Eager Initialization
```java
public class EagerSingleton {
    private static final EagerSingleton instance = new EagerSingleton();
    private EagerSingleton() {}
    public static EagerSingleton getInstance() {
        return instance;
    }
}
````

**✅ Pros:**

* Simple to implement
* Thread-safe

**❌ Cons:**

* Instance is created even if it's never used (no lazy loading)
* May lead to resource wastage if initialization is expensive

---

### 2. Lazy Initialization (Non-thread-safe)

```java
public class LazySingleton {
    private static LazySingleton instance;
    private LazySingleton() {}
    public static LazySingleton getInstance() {
        if (instance == null) {
            instance = new LazySingleton();
        }
        return instance;
    }
}
```

**✅ Pros:**

* Lazy initialization

**❌ Cons:**

* Not thread-safe
* Multiple threads can create multiple instances

---

### 3. Lazy Initialization (Thread-safe with `synchronized`)

```java
public class ThreadSafeSingleton {
    private static ThreadSafeSingleton instance;
    private ThreadSafeSingleton() {}
    public static synchronized ThreadSafeSingleton getInstance() {
        if (instance == null) {
            instance = new ThreadSafeSingleton();
        }
        return instance;
    }
}
```

**✅ Pros:**

* Thread-safe
* Lazy initialization

**❌ Cons:**

* Synchronized method leads to performance overhead

---

### 4. Double-Checked Locking

```java
public class DCLSingleton {
    private static volatile DCLSingleton instance;
    private DCLSingleton() {}
    public static DCLSingleton getInstance() {
        if (instance == null) {
            synchronized (DCLSingleton.class) {
                if (instance == null) {
                    instance = new DCLSingleton();
                }
            }
        }
        return instance;
    }
}
```

**✅ Pros:**

* Thread-safe
* Performance-optimized
* Lazy-loaded

**❌ Cons:**

* Slightly complex code
* Needs `volatile` keyword (since Java 1.5)

---

### 5. Bill Pugh Singleton (Recommended)

```java
public class BillPughSingleton {
    private BillPughSingleton() {}

    private static class SingletonHelper {
        private static final BillPughSingleton INSTANCE = new BillPughSingleton();
    }

    public static BillPughSingleton getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
```

**✅ Pros:**

* Thread-safe
* Lazy-loaded
* No synchronization overhead
* Simple and elegant

**❌ Cons:**

* Slightly more complex than eager/lazy

---

### 6. Enum Singleton

```java
public enum EnumSingleton {
    INSTANCE;
    public void someMethod() {
        // method body
    }
}
```

**✅ Pros:**

* Thread-safe
* Serialization-safe
* Protection against reflection

**❌ Cons:**

* Not flexible (can't extend other classes)
* Enum-based singletons may be less familiar to some developers

---

## 📊 Comparison Table

| Method                 | Lazy | Thread-Safe | Performance | Serialization Safe | Simplicity |
| ---------------------- | ---- | ----------- | ----------- | ------------------ | ---------- |
| Eager Initialization   | ❌    | ✅           | ✅           | ✅                  | ✅          |
| Lazy Initialization    | ✅    | ❌           | ✅           | ❌                  | ✅          |
| Synchronized Method    | ✅    | ✅           | ❌           | ❌                  | ✅          |
| Double-Checked Locking | ✅    | ✅           | ✅           | ❌ (extra work)     | ❌          |
| Bill Pugh Singleton    | ✅    | ✅           | ✅           | ❌ (extra work)     | ✅          |
| Enum Singleton         | ✅    | ✅           | ✅           | ✅                  | ✅          |

---

## 🎯 When to Use Which?

| Scenario                                         | Recommended Method         |
| ------------------------------------------------ | -------------------------- |
| Simple and always-needed instance                | Eager Initialization       |
| Lazy loading with simple code                    | Bill Pugh Singleton        |
| Performance-critical multithreaded environment   | Double-Checked Locking     |
| Need protection against reflection/serialization | Enum Singleton             |
| Learning or demo purposes                        | Synchronized Method / Lazy |

---

## ⚠️ Pitfalls to Avoid

* Not handling multithreading properly in lazy initialization
* Using reflection to break singleton (except Enum)
* Serialization issues (use `readResolve()` if not using Enum)
* Violating the Single Responsibility Principle by adding too much logic to Singleton

---

## ✅ Best Practices

* Keep constructor private
* Avoid synchronization unless necessary
* Consider Enum for high safety
* Use Bill Pugh for most cases: simple, efficient, thread-safe

---

## 📚 References

* Effective Java by Joshua Bloch
* GoF Design Patterns Book
* Oracle Java Documentation
