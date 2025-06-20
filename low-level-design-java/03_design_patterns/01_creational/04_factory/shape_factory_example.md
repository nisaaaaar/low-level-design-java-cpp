## 🏭 Factory Design Pattern – Overview

* **Problem**: When you have a superclass with multiple subclasses and you need to return one of the subclasses based on input.
* **Solution**: Use a **Factory** to create objects instead of calling the constructor directly.
* **Goal**: Delegate the instantiation logic to a separate method or class.

---

## 🎯 Real-Life Example Scenario: Shape Factory

You want to create different `Shape` objects (`Circle`, `Rectangle`, `Square`) without exposing the instantiation logic to the client.

---

### 🔹 1. `Shape` Interface

```java
public interface Shape {
    void draw();
}
```

---

### 🔹 2. Concrete Shape Classes

#### `Circle.java`

```java
public class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Circle");
    }
}
```

#### `Rectangle.java`

```java
public class Rectangle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle");
    }
}
```

#### `Square.java`

```java
public class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Square");
    }
}
```

---

### 🔹 3. Factory Class: `ShapeFactory.java`

```java
public class ShapeFactory {
    // Returns object based on input
    public Shape getShape(String shapeType) {
        if (shapeType == null) return null;
        switch (shapeType.toLowerCase()) {
            case "circle": return new Circle();
            case "rectangle": return new Rectangle();
            case "square": return new Square();
            default: return null;
        }
    }
}
```

---

### 🔹 4. Client Code: `FactoryPatternDemo.java`

```java
public class FactoryPatternDemo {
    public static void main(String[] args) {
        ShapeFactory shapeFactory = new ShapeFactory();

        Shape shape1 = shapeFactory.getShape("circle");
        shape1.draw();

        Shape shape2 = shapeFactory.getShape("rectangle");
        shape2.draw();

        Shape shape3 = shapeFactory.getShape("square");
        shape3.draw();
    }
}
```

---

### ✅ Output:

```
Drawing a Circle
Drawing a Rectangle
Drawing a Square
```

---

## ✅ Benefits of Factory Pattern

| Benefit               | Description                                           |
| --------------------- | ----------------------------------------------------- |
| Loose Coupling        | Client does not need to know the exact class name.    |
| Single Responsibility | Object creation is separated from usage logic.        |
| Scalability           | Easy to add new subclasses with minimal code changes. |
| Code Reusability      | Centralizes object creation logic.                    |

---

## 🧠 When to Use Factory Pattern

* When the object creation is **complex** or requires **logic**.
* When you want to **hide object instantiation** from client.
* When the code has **multiple subclasses** of a common interface.
* When adding **new types of objects** should require minimal change.
