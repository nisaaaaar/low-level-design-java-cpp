## 🏭 Factory Design Pattern – Overview (C++)

* **Problem**: You have a base class (`Shape`) and several derived classes. You want to instantiate them based on input without exposing object creation logic.
* **Solution**: Use a **factory class** that returns the correct object based on input.
* **Goal**: Promote **loose coupling** and centralize instantiation logic.

---

## 🎯 Example: Shape Factory

You want to create different `Shape` objects (`Circle`, `Rectangle`, `Square`) via a **factory** class.

---

### 🔹 1. `Shape` Interface

```cpp
#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};
```

---

### 🔹 2. Concrete Shape Classes

#### `Circle`

```cpp
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};
```

#### `Rectangle`

```cpp
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};
```

#### `Square`

```cpp
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square" << std::endl;
    }
};
```

---

### 🔹 3. Factory Class: `ShapeFactory`

```cpp
class ShapeFactory {
public:
    std::unique_ptr<Shape> getShape(const std::string& shapeType) {
        if (shapeType == "circle")
            return std::make_unique<Circle>();
        else if (shapeType == "rectangle")
            return std::make_unique<Rectangle>();
        else if (shapeType == "square")
            return std::make_unique<Square>();
        else
            return nullptr;
    }
};
```

---

### 🔹 4. Client Code: `main`

```cpp
int main() {
    ShapeFactory factory;

    auto shape1 = factory.getShape("circle");
    if (shape1) shape1->draw();

    auto shape2 = factory.getShape("rectangle");
    if (shape2) shape2->draw();

    auto shape3 = factory.getShape("square");
    if (shape3) shape3->draw();

    return 0;
}
```

---

### ✅ Output

```
Drawing a Circle
Drawing a Rectangle
Drawing a Square
```

---

## ✅ Benefits of Factory Pattern

| Benefit            | Description                                         |
| ------------------ | --------------------------------------------------- |
| Loose Coupling     | Client is decoupled from concrete classes           |
| Centralized Logic  | Object creation is in one place                     |
| Scalable           | New shapes can be added with minimal client changes |
| Easier Maintenance | Changes to creation logic don’t affect client code  |

---

## 🧠 When to Use Factory Pattern in C++

* When object creation logic is **complex** or **repetitive**
* When you want to **hide class instantiation**
* When there are **multiple subclasses** of a base class
* When you want to adhere to **Open/Closed Principle**

