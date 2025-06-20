## 🧱 **Abstract Factory Pattern** – Overview (C++)

* The **Abstract Factory** pattern provides an interface for creating **families of related objects** without specifying their concrete classes.
* It allows for **cross-platform UI/toolkits**, **theme engines**, and other scenarios where consistency is key.

---

## 🎯 Scenario: GUI Toolkit Factory

You want to support GUI rendering for both **Windows** and **Mac** platforms by creating:

* `WindowsButton` and `WindowsCheckbox`
* `MacButton` and `MacCheckbox`

Using abstract factories, the client remains decoupled from the concrete classes.

---

## 🔧 Step-by-Step C++ Implementation

---

### 🔹 1. Product Interfaces

```cpp
#include <iostream>
#include <memory>

// Abstract Product: Button
class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};

// Abstract Product: Checkbox
class Checkbox {
public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};
```

---

### 🔹 2. Concrete Products – Windows

```cpp
class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Windows Button" << std::endl;
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering Windows Checkbox" << std::endl;
    }
};
```

---

### 🔹 3. Concrete Products – Mac

```cpp
class MacButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Mac Button" << std::endl;
    }
};

class MacCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering Mac Checkbox" << std::endl;
    }
};
```

---

### 🔹 4. Abstract Factory Interface

```cpp
class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};
```

---

### 🔹 5. Concrete Factories

```cpp
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};
```

---

### 🔹 6. Client Application

```cpp
class Application {
private:
    std::unique_ptr<Button> button;
    std::unique_ptr<Checkbox> checkbox;

public:
    Application(const GUIFactory& factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    void renderUI() const {
        button->render();
        checkbox->render();
    }
};
```

---

### 🔹 7. Main Function

```cpp
int main() {
    // Change factory here to switch platforms
    WindowsFactory factory;  // or MacFactory
    Application app(factory);
    app.renderUI();

    return 0;
}
```

---

### ✅ Output (if using `WindowsFactory`)

```
Rendering Windows Button  
Rendering Windows Checkbox
```

### ✅ Output (if using `MacFactory`)

```
Rendering Mac Button  
Rendering Mac Checkbox
```

---

## ✅ When to Use Abstract Factory

| Use Case                                 | Benefit                                   |
| ---------------------------------------- | ----------------------------------------- |
| Need to create **families of objects**   | Ensures consistent object creation        |
| Want to **decouple client from classes** | Code is cleaner and easier to maintain    |
| Need **cross-platform support**          | Switch factories to change implementation |

---

## 🟩 Factory Method vs Abstract Factory (C++)

| Factory Method          | Abstract Factory                 |
| ----------------------- | -------------------------------- |
| Returns a single object | Returns multiple related objects |
| Uses **inheritance**    | Uses **composition + interface** |
| One product             | Family of products               |

