## 🧱 **Builder Pattern Overview**

The **Builder Pattern** is used to construct a complex object step by step. It separates the construction of an object from its representation, allowing the same construction process to create different representations.

---

## 📦 Example Scenario: Building a `Computer`

You want to create a `Computer` object with optional parameters like `GPU`, `Bluetooth`, etc. Instead of a long constructor with many parameters, we use a **Builder**.

---

### 🔹 1. The Product Class: `Computer.java`

```java
public class Computer {
    // Required parameters
    private String CPU;
    private String RAM;

    // Optional parameters
    private boolean hasGraphicsCard;
    private boolean hasBluetooth;

    // Private constructor
    private Computer(Builder builder) {
        this.CPU = builder.CPU;
        this.RAM = builder.RAM;
        this.hasGraphicsCard = builder.hasGraphicsCard;
        this.hasBluetooth = builder.hasBluetooth;
    }

    public String toString() {
        return "Computer [CPU=" + CPU + ", RAM=" + RAM +
                ", GraphicsCard=" + hasGraphicsCard + ", Bluetooth=" + hasBluetooth + "]";
    }

    // Static nested Builder class
    public static class Builder {
        // Required
        private String CPU;
        private String RAM;

        // Optional
        private boolean hasGraphicsCard;
        private boolean hasBluetooth;

        public Builder(String CPU, String RAM) {
            this.CPU = CPU;
            this.RAM = RAM;
        }

        public Builder setGraphicsCard(boolean hasGraphicsCard) {
            this.hasGraphicsCard = hasGraphicsCard;
            return this;
        }

        public Builder setBluetooth(boolean hasBluetooth) {
            this.hasBluetooth = hasBluetooth;
            return this;
        }

        public Computer build() {
            return new Computer(this);
        }
    }
}
```

---

### 🔹 2. Client Code: `BuilderPatternDemo.java`

```java
public class BuilderPatternDemo {
    public static void main(String[] args) {
        Computer gamingPC = new Computer.Builder("Intel i9", "32GB")
                                .setGraphicsCard(true)
                                .setBluetooth(true)
                                .build();

        Computer officePC = new Computer.Builder("Intel i5", "16GB")
                                .setGraphicsCard(false)
                                .setBluetooth(true)
                                .build();

        System.out.println(gamingPC);
        System.out.println(officePC);
    }
}
```

---

### ✅ Output

```
Computer [CPU=Intel i9, RAM=32GB, GraphicsCard=true, Bluetooth=true]
Computer [CPU=Intel i5, RAM=16GB, GraphicsCard=false, Bluetooth=true]
```

---

## 🧠 Benefits of Builder Pattern

| Benefit                     | Explanation                                   |
| --------------------------- | --------------------------------------------- |
| Readable & maintainable     | Clear and fluent object construction          |
| No telescoping constructors | Avoids constructor with 5-6+ parameters       |
| Immutable object            | Final object is immutable after construction  |
| Flexible object creation    | Optional parameters can be set only if needed |

---

## ✅ When to Use Builder Pattern

* Object has **many optional parameters**.
* You want to avoid **constructor overload hell**.
* Object creation should be **step-by-step** and **controlled**.
* You want to make the object **immutable** after creation.