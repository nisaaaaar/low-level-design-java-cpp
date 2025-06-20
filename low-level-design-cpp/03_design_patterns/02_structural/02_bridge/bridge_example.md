## 🧩 **Bridge Design Pattern in C++**

---

### ✅ **Definition**

The **Bridge Pattern** is a **structural design pattern** that decouples an abstraction from its implementation so that the two can vary independently.

---

### 🎯 **Analogy**

> A **remote control** (abstraction) can work with different **TV brands** (implementations). You can change the remote or the TV without changing the other.

---

## 💻 **Code Example: Remote Control & TV**

---

### 1️⃣ `TV` Interface – Implementor

```cpp
#include <iostream>
#include <memory>

class TV {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void setChannel(int channel) = 0;
    virtual ~TV() = default;
};
```

---

### 2️⃣ Concrete Implementations – `SonyTV`, `SamsungTV`

```cpp
class SonyTV : public TV {
public:
    void on() override {
        std::cout << "Sony TV is ON\n";
    }

    void off() override {
        std::cout << "Sony TV is OFF\n";
    }

    void setChannel(int channel) override {
        std::cout << "Sony TV: Channel set to " << channel << "\n";
    }
};

class SamsungTV : public TV {
public:
    void on() override {
        std::cout << "Samsung TV is ON\n";
    }

    void off() override {
        std::cout << "Samsung TV is OFF\n";
    }

    void setChannel(int channel) override {
        std::cout << "Samsung TV: Channel set to " << channel << "\n";
    }
};
```

---

### 3️⃣ `RemoteControl` – Abstraction

```cpp
class RemoteControl {
protected:
    std::shared_ptr<TV> tv;

public:
    RemoteControl(std::shared_ptr<TV> tv) : tv(tv) {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int channel) = 0;
    virtual ~RemoteControl() = default;
};
```

---

### 4️⃣ `BasicRemote` – Refined Abstraction

```cpp
class BasicRemote : public RemoteControl {
public:
    BasicRemote(std::shared_ptr<TV> tv) : RemoteControl(tv) {}

    void turnOn() override {
        tv->on();
    }

    void turnOff() override {
        tv->off();
    }

    void setChannel(int channel) override {
        tv->setChannel(channel);
    }
};
```

---

### 5️⃣ Client Code – Bridge in Action

```cpp
int main() {
    std::shared_ptr<TV> sonyTV = std::make_shared<SonyTV>();
    BasicRemote sonyRemote(sonyTV);

    sonyRemote.turnOn();
    sonyRemote.setChannel(5);
    sonyRemote.turnOff();

    std::cout << "----\n";

    std::shared_ptr<TV> samsungTV = std::make_shared<SamsungTV>();
    BasicRemote samsungRemote(samsungTV);

    samsungRemote.turnOn();
    samsungRemote.setChannel(10);
    samsungRemote.turnOff();

    return 0;
}
```

---

### ✅ Output

```
Sony TV is ON
Sony TV: Channel set to 5
Sony TV is OFF
----
Samsung TV is ON
Samsung TV: Channel set to 10
Samsung TV is OFF
```

---

## 📐 UML Diagram (Text-Based)

```
        +---------------------+          uses          +---------------------+
        |   RemoteControl     |----------------------->|        TV           |
        +---------------------+                        +---------------------+
                 ^                                                  ^
                 |                                                  |
        +----------------+                                 +------------------+
        |  BasicRemote    |                                 |  SonyTV          |
        +----------------+                                 |  SamsungTV       |
                                                           +------------------+
```

---

## ✅ Benefits

| Benefit                  | Description                                                         |
| ------------------------ | ------------------------------------------------------------------- |
| ✅ Decoupling             | Abstraction (`Remote`) and implementation (`TV`) vary independently |
| ✅ Flexibility            | Easily add new remotes or TVs without changes to each other         |
| ✅ Avoids Class Explosion | No need for SonyAdvancedRemote, SamsungBasicRemote, etc.            |
| ✅ Clean Code             | Separation of concern between interface and implementation          |

---

## ⏱️ When to Use Bridge Pattern

* When both abstraction and implementation may change independently
* To avoid multiplying subclasses for combinations of abstraction/implementation
* When you want to switch implementations at runtime

---

## ⚠️ Caveats

| Limitation               | Why?                                        |
| ------------------------ | ------------------------------------------- |
| Extra complexity         | More interfaces and indirection introduced  |
| Overkill for simple apps | Simpler inheritance/composition may suffice |

---

## ✅ SOLID Principles Followed

| Principle | Applied? | Why?                                                           |
| --------- | -------- | -------------------------------------------------------------- |
| ✅ SRP     | Yes      | TV and Remote have independent responsibilities                |
| ✅ OCP     | Yes      | Easily extend with new TVs or remotes                          |
| ✅ DIP     | Yes      | RemoteControl depends on abstraction (`TV`), not concrete type |
| ✅ LSP     | Yes      | Subclasses substitute base types safely                        |
| ✅ ISP     | Yes      | TV interface is small and focused                              |

---

## 🌍 Real-World Use Case

> A cross-platform graphics app can have a `Shape` (abstraction) and `Renderer` (implementation) to decouple UI from platform-specific drawing APIs.

---

## 📌 Interview Summary

> The **Bridge Pattern** lets you separate abstraction (e.g., Remote) from implementation (e.g., TV). It helps scale code in two dimensions independently and avoids subclass explosion. I used it to model universal remotes that work across multiple TV brands without hard coupling.


