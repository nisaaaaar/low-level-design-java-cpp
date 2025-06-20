## 🧩 Bridge Design Pattern in Java

---

### ✅ **Definition**

The **Bridge Pattern** is a **structural design pattern** that:

> “**Decouples** an abstraction from its implementation so that the two can vary independently.”

This is useful when both the **abstraction (what to do)** and the **implementation (how to do it)** are likely to change.

---

### 🎯 **Analogy**

> Imagine a **TV remote control** (the abstraction) that can operate different brands of **TVs** (the implementation).
> The remote control defines operations like `turnOn()`, `turnOff()`, and `setChannel()` but how each brand implements those may differ.
> The **bridge** allows the same remote to work with multiple TV brands **without changing its code**.

---

## 💻 **Real-World Code Example**

### 🧵 Scenario: A `RemoteControl` should control any brand of `TV` (e.g., Sony, Samsung).

---

### 1️⃣ `TV` Interface – The Implementation Side (Bridge)

```java
public interface TV {
    void on();
    void off();
    void setChannel(int channel);
}
```

---

### 2️⃣ Concrete Implementations – Sony and Samsung TVs

```java
public class SonyTV implements TV {
    public void on() {
        System.out.println("Sony TV is ON");
    }
    public void off() {
        System.out.println("Sony TV is OFF");
    }
    public void setChannel(int channel) {
        System.out.println("Sony TV: Channel set to " + channel);
    }
}
```

```java
public class SamsungTV implements TV {
    public void on() {
        System.out.println("Samsung TV is ON");
    }
    public void off() {
        System.out.println("Samsung TV is OFF");
    }
    public void setChannel(int channel) {
        System.out.println("Samsung TV: Channel set to " + channel);
    }
}
```

---

### 3️⃣ `RemoteControl` – The Abstraction

```java
public abstract class RemoteControl {
    protected TV tv;

    public RemoteControl(TV tv) {
        this.tv = tv;
    }

    public abstract void turnOn();
    public abstract void turnOff();
    public abstract void setChannel(int channel);
}
```

---

### 4️⃣ `BasicRemote` – Refined Abstraction

```java
public class BasicRemote extends RemoteControl {
    public BasicRemote(TV tv) {
        super(tv);
    }

    public void turnOn() {
        tv.on();
    }

    public void turnOff() {
        tv.off();
    }

    public void setChannel(int channel) {
        tv.setChannel(channel);
    }
}
```

---

### 5️⃣ Client Code – Using Bridge Pattern

```java
public class BridgePatternDemo {
    public static void main(String[] args) {
        TV sony = new SonyTV();
        RemoteControl sonyRemote = new BasicRemote(sony);
        sonyRemote.turnOn();
        sonyRemote.setChannel(5);
        sonyRemote.turnOff();

        System.out.println("----");

        TV samsung = new SamsungTV();
        RemoteControl samsungRemote = new BasicRemote(samsung);
        samsungRemote.turnOn();
        samsungRemote.setChannel(10);
        samsungRemote.turnOff();
    }
}
```

---

## ✅ **Output**

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

## 📐 UML Diagram (Textual)

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

* `RemoteControl` → **Abstraction**
* `TV` → **Implementor**
* `BasicRemote` → **Refined Abstraction**
* `SonyTV`, `SamsungTV` → **Concrete Implementors**

---

## 📈 Key Benefits

| Benefit         | Description                                                                          |
| --------------- | ------------------------------------------------------------------------------------ |
| ✅ Decoupling    | Abstraction and implementation evolve independently                                  |
| ✅ Flexibility   | Mix and match different remotes and TVs at runtime                                   |
| ✅ Extensibility | Add new remotes or devices without affecting existing ones                           |
| ✅ Cleaner Code  | Avoids explosion of subclasses like `SonyBasicRemote`, `SamsungAdvancedRemote`, etc. |

---

## ⏱️ When to Use It

Use Bridge Pattern when:

* You want to **separate abstraction and implementation**.
* Both may change independently.
* You want to avoid a **class explosion** due to combinations of implementations and abstractions.
* You need **runtime flexibility** to switch implementations.

---

## ⚠️ Limitations / Caveats

* ❌ Slightly more **complex** design (more layers/abstractions).
* ❌ Can be **overkill** for small or simple systems.
* ❌ Introduces **indirection**, which may affect performance or readability.

---

## 🧠 Follows SOLID Principles

| Principle | Applied? | Explanation                                                       |
| --------- | -------- | ----------------------------------------------------------------- |
| ✅ SRP     | Yes      | Remote and TV classes have separate responsibilities              |
| ✅ OCP     | Yes      | Add new TV or Remote without modifying existing code              |
| ✅ DIP     | Yes      | `RemoteControl` depends on abstraction (`TV`), not concrete class |
| ✅ LSP     | Yes      | Subclasses can substitute base classes safely                     |
| ✅ ISP     | Yes      | Interfaces (`TV`) are minimal and focused                         |

---

## 🌍 Real-World Use Case

### ✅ Example: **Cross-platform UI Toolkits**

Imagine building a **drawing application** that must support different **operating systems** like Windows, Mac, Linux.
You define an abstraction like `Shape` and bridge it with implementations like `WindowsRenderer`, `MacRenderer`.

* `Shape` = Abstraction (`RemoteControl`)
* `Renderer` = Implementation (`TV`)

This way, `Shape` (abstraction) and `Renderer` (implementation) can be developed and changed independently.

---

## 📝 Summary for Interview

> The **Bridge Pattern** helps you **separate abstraction from implementation**, making it easier to change either without affecting the other.
> A good example is a `RemoteControl` (abstraction) controlling multiple types of `TV` (implementations).
> It helps manage complexity when both dimensions grow independently and aligns well with **SOLID principles** like DIP and OCP.
