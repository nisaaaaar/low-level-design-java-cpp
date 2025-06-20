## ✅ Definition

The **Flyweight Pattern** is a **structural design pattern** that:

> **Minimizes memory usage** by **sharing objects** that are **identical in structure** and can be **reused**, instead of creating many similar objects.

It distinguishes between:

* **Intrinsic state**: Shared, immutable, stored in the flyweight object.
* **Extrinsic state**: Context-specific, passed in from the outside.

---

## 🎯 Analogy

✏️ *Text Editor Fonts*:

* Each character on the screen might use the same **font object** (size, style).
* Instead of creating a new font object for every letter, the system **reuses a shared font object** for all letters with the same style.

So, **each character doesn't store its own font**—it refers to a **shared Flyweight**.

---

## 👨‍💻 Java Code Example – Drawing Circles

Let’s create an app that draws **colored circles**:

* All circles of the same **color** are shared (`Flyweight`)
* Position (`x`, `y`) is external (extrinsic) and passed at runtime

---

### 1. Flyweight Interface

```java
public interface Shape {
    void draw(int x, int y);
}
```

---

### 2. Concrete Flyweight

```java
public class Circle implements Shape {
    private String color; // Intrinsic (shared)

    public Circle(String color) {
        this.color = color;
        System.out.println("Creating a " + color + " circle");
    }

    public void draw(int x, int y) {
        System.out.println("Drawing " + color + " circle at (" + x + ", " + y + ")");
    }
}
```

---

### 3. Flyweight Factory

```java
import java.util.HashMap;
import java.util.Map;

public class ShapeFactory {
    private static final Map<String, Shape> circleMap = new HashMap<>();

    public static Shape getCircle(String color) {
        Shape circle = circleMap.get(color);

        if (circle == null) {
            circle = new Circle(color);
            circleMap.put(color, circle);
        }
        return circle;
    }
}
```

---

### 4. Client

```java
public class FlyweightClient {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            String color = i % 2 == 0 ? "Red" : "Blue";
            Shape circle = ShapeFactory.getCircle(color);
            int x = (int) (Math.random() * 100);
            int y = (int) (Math.random() * 100);
            circle.draw(x, y);
        }
    }
}
```

---

## 🌟 Key Benefits

✅ Saves memory and resources when working with a **large number of similar objects**
✅ Supports **object sharing** for better performance
✅ Enforces **object reusability**

---

## 📌 When to Use

* When you have a **large number of similar objects**
* When object creation is **expensive in memory**
* When many objects share the **same intrinsic state** (e.g., color, font, type)

---

## ⚠️ Limitations or Caveats

* Code becomes **more complex** (separating intrinsic and extrinsic state)
* **Thread-safety** needs to be ensured when sharing mutable flyweights
* **Flyweight objects must be immutable** to avoid side effects

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Each class does one thing (e.g., Circle draws, Factory creates)
* ✅ **O – OCP**: You can add new shape types without modifying others
* ✅ **L – LSP**: Clients use `Shape` without caring if it's shared
* ✅ **I – ISP**: Interface `Shape` is minimal
* ✅ **D – DIP**: Client depends on `Shape` interface, not concrete classes

---

## 📐 UML Diagram

```plaintext
      +-------------+
      |   Shape     |<--------------------+
      +-------------+                     |
      | +draw(x, y) |                     |
      +-------------+                     |
            ▲                             |
      +-------------+             +------------------+
      |   Circle     |            |  ShapeFactory     |
      +-------------+            +------------------+
      | - color      |            | - circleMap       |
      | +draw(x, y)  |            | +getCircle(color) |
      +-------------+            +------------------+
                                        ▲
                                        |
                                +-------------------+
                                |   FlyweightClient  |
                                +-------------------+
```

---

## 🌍 Real-World Use Cases

* **Java String Pool**: Reuses identical string literals (e.g., `"abc"`)
* **Java `Integer.valueOf(int)`**: Caches small integers (-128 to 127)
* **Game development**: Same tree, rock, or enemy model used in many places
* **Font rendering**: Reuse font styles instead of creating new ones for each letter

---

## ✅ Summary (for Interview)

* **Pattern Name**: Flyweight
* **Type**: Structural
* **Use When**: You have **lots of similar objects** and want to **save memory**
* **Key Benefit**: **Reuse objects**, reduce memory footprint
* **Java Example**: `String.intern()`, `Integer.valueOf()`, UI elements in games

