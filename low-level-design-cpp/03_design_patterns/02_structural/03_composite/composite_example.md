## ✅ Definition

**Composite Design Pattern** is a **structural pattern** used to **treat individual objects and compositions of objects uniformly**.

> It allows you to build **tree structures** of objects and then work with those structures as if they were individual objects.

---

## 🎯 Analogy

> Think of a **folder** on your computer:

* A folder can contain **files** or **other folders**.
* You can **perform actions** like opening or deleting a folder, and those actions will **apply to all contents recursively**.

---

## 💻 Real-World Code Example (C++)

Let’s model a **Graphic Editor** where:

* We can draw **Shapes** like `Circle` and `Rectangle`.
* A `Group` can contain multiple `Shapes` or other `Groups`.

### ✅ Class Hierarchy

* `Graphic` (Abstract Base Class)
* `Circle` and `Rectangle` (Leaf classes)
* `Group` (Composite class)

```cpp
#include <iostream>
#include <vector>
#include <memory>

// Component
class Graphic {
public:
    virtual void draw() const = 0;
    virtual ~Graphic() = default;
};

// Leaf 1
class Circle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

// Leaf 2
class Rectangle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle\n";
    }
};

// Composite
class Group : public Graphic {
private:
    std::vector<std::shared_ptr<Graphic>> children;

public:
    void add(const std::shared_ptr<Graphic>& graphic) {
        children.push_back(graphic);
    }

    void draw() const override {
        std::cout << "Group Drawing Start:\n";
        for (const auto& child : children) {
            child->draw();
        }
        std::cout << "Group Drawing End\n";
    }
};

// Client Code
int main() {
    auto circle1 = std::make_shared<Circle>();
    auto rect1 = std::make_shared<Rectangle>();
    auto circle2 = std::make_shared<Circle>();

    auto group1 = std::make_shared<Group>();
    group1->add(circle1);
    group1->add(rect1);

    auto group2 = std::make_shared<Group>();
    group2->add(circle2);
    group2->add(group1); // nesting groups

    group2->draw();
    return 0;
}
```

---

## ✅ UML Diagram

```
         +------------------+
         |    Graphic       |<<interface>>
         +------------------+
         | +draw()          |
         +------------------+
                /_\
                 |
        ---------------------
        |        |          |
+--------------+ +---------------+ +-------------+
|   Circle     | |  Rectangle    | |   Group     |
+--------------+ +---------------+ +-------------+
| +draw()      | | +draw()       | | +draw()     |
|              | |               | | +add()      |
+--------------+ +---------------+ +-------------+
```

---

## ✅ Key Benefits

* **Uniformity**: Treat individual objects and groups the same.
* **Scalability**: Add new components without changing existing code.
* **Tree Structure**: Naturally represents hierarchies like UI elements, file systems.

---

## ✅ When to Use

* You have a **hierarchical structure** (e.g., tree of objects).
* You want to **treat leaf and composite objects uniformly**.
* When your code would otherwise be littered with `if-else` or `type-checks` for object types.

---

## ❗ Limitations or Caveats

* Can make code **harder to understand** if the hierarchy is too deep.
* Not suitable if leaf and composite need **radically different interfaces**.
* May **violate Liskov Substitution Principle** if some methods don’t make sense for certain children.

---

## ✅ SOLID Principles

* **S**ingle Responsibility: Each class has one responsibility (drawing itself or managing children).
* **O**pen/Closed: Easily extendable with new shapes.
* **L**iskov: Mostly followed, unless misuse occurs.
* **I**nterface Segregation: `Graphic` has minimal required operations.
* **D**ependency Inversion: Client depends on the `Graphic` abstraction, not concrete classes.

---

## 🌍 Real World Use Cases

* **UI Libraries**: Windows, buttons, panels are often composites.
* **File System**: Files and directories.
* **Graphic Editors**: Shapes, groups of shapes.
* **Organization Hierarchies**: Employee and Manager (who can have subordinates).

---

## 📝 In Interview — How to Say It

> The Composite pattern lets me treat **individual and composite objects uniformly**. For example, in a **graphic editor**, I can draw a `Circle` or a `Group` of shapes using the same interface. I use it when I have a **tree-like structure** and want to operate on nodes and leaves the same way.
