## ✅ Definition

The **Decorator Pattern** is a **structural design pattern** that:

> **Adds new behavior** to an object **dynamically** without modifying its existing structure or class.

It wraps the original object in a new class (called a **decorator**) that adds extra responsibilities.

---

## 🎯 Analogy

☕ *Think of a coffee shop order.*

You order a **base coffee**, and then you can **add milk, sugar, or caramel** on top.
Each add-on wraps your original coffee and adds its **own cost and description**.

You don’t subclass Coffee for every combination—you just decorate it!

---

## 👨‍💻 Java Code Example

We’ll model a **Coffee shop** where:

* `SimpleCoffee` is the base object (concrete component)
* `MilkDecorator`, `SugarDecorator` are decorators

### 1. Component

```java
public interface Coffee {
    String getDescription();
    double getCost();
}
```

### 2. Concrete Component

```java
public class SimpleCoffee implements Coffee {
    public String getDescription() {
        return "Simple Coffee";
    }

    public double getCost() {
        return 5.0;
    }
}
```

### 3. Abstract Decorator

```java
public abstract class CoffeeDecorator implements Coffee {
    protected Coffee decoratedCoffee;

    public CoffeeDecorator(Coffee coffee) {
        this.decoratedCoffee = coffee;
    }

    public String getDescription() {
        return decoratedCoffee.getDescription();
    }

    public double getCost() {
        return decoratedCoffee.getCost();
    }
}
```

### 4. Concrete Decorators

```java
public class MilkDecorator extends CoffeeDecorator {
    public MilkDecorator(Coffee coffee) {
        super(coffee);
    }

    public String getDescription() {
        return decoratedCoffee.getDescription() + ", Milk";
    }

    public double getCost() {
        return decoratedCoffee.getCost() + 1.5;
    }
}

public class SugarDecorator extends CoffeeDecorator {
    public SugarDecorator(Coffee coffee) {
        super(coffee);
    }

    public String getDescription() {
        return decoratedCoffee.getDescription() + ", Sugar";
    }

    public double getCost() {
        return decoratedCoffee.getCost() + 0.5;
    }
}
```

### 5. Client

```java
public class CoffeeShop {
    public static void main(String[] args) {
        Coffee myCoffee = new SimpleCoffee();                       // Simple Coffee
        myCoffee = new MilkDecorator(myCoffee);                    // + Milk
        myCoffee = new SugarDecorator(myCoffee);                   // + Sugar

        System.out.println(myCoffee.getDescription());             // Simple Coffee, Milk, Sugar
        System.out.println("Total Cost: $" + myCoffee.getCost());  // Total Cost: $7.0
    }
}
```

---

## 🌟 Key Benefits

✅ Add behavior **dynamically at runtime**
✅ **Avoid class explosion** from subclassing every combination
✅ Follows **Open/Closed Principle** (open for extension, closed for modification)
✅ Works with existing objects without modifying them

---

## 📌 When to Use

* When you want to add features to objects **without altering their structure**
* When **inheritance is not flexible enough** (e.g., too many subclasses)
* When you want to apply responsibilities **selectively and dynamically**

---

## ⚠️ Limitations or Caveats

* Can lead to **many small classes** if not managed well
* Debugging can be harder due to many layers of wrappers
* Requires careful design to avoid violating **Liskov Substitution Principle**

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Each class has one responsibility
* ✅ **O – OCP**: You can add new decorators without modifying existing code
* ✅ **L – LSP**: Decorators should maintain the behavior of original object (be careful!)
* ✅ **I – ISP**: The `Coffee` interface is minimal
* ✅ **D – DIP**: High-level code depends on abstraction (`Coffee`)

---

## 📐 UML Diagram

```plaintext
         +-------------+
         |   Coffee    |<--------------------------+
         +-------------+                           |
         | +getCost()  |                           |
         | +getDesc()  |                           |
         +-------------+                           |
             ▲                                     |
   +----------------+                     +----------------------+
   | SimpleCoffee   |                     |  CoffeeDecorator     |
   +----------------+                     +----------------------+
   | +getCost()     |                     | - decoratedCoffee    |
   | +getDesc()     |                     | +getCost()           |
   +----------------+                     | +getDesc()           |
                                          +----------------------+
                                                  ▲
                      +--------------------+      +-------------------+
                      |  MilkDecorator     |      |  SugarDecorator   |
                      +--------------------+      +-------------------+
                      | +getCost()         |      | +getCost()        |
                      | +getDesc()         |      | +getDesc()        |
                      +--------------------+      +-------------------+
```

---

## 🌍 Real-World Use Case

* **Java I/O Library**:

  * `BufferedInputStream`, `DataInputStream` decorate a `FileInputStream`.
  * Each adds new behavior like buffering or reading types (int, float) without modifying the base stream.

* **UI Toolkits**:

  * A `BorderDecorator` can add a border to a UI element.
  * A `ScrollDecorator` can add scrolling capability.

---

## ✅ Summary (for Interview)

* **Pattern Name**: Decorator Pattern
* **Type**: Structural
* **Use When**: You need to **add functionality without changing the class**
* **Key Benefit**: Behavior added at **runtime**, avoids subclassing
* **Java Example**: `InputStream` family (`FileInputStream`, `BufferedInputStream`)

