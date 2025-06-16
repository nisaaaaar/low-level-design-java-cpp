## 🧱 **Abstract Factory Pattern** – Overview

* **Abstract Factory** is a creational design pattern that provides an interface for creating **families of related or dependent objects** without specifying their concrete classes.
* It is essentially a **factory of factories**.

---

## 🎯 Real-World Scenario: GUI Toolkit Factory

Imagine building a cross-platform UI system where:

* On **Windows**, you want to create `WindowsButton` and `WindowsCheckbox`.
* On **Mac**, you want to create `MacButton` and `MacCheckbox`.

Instead of tightly coupling the code to Windows/Mac classes, use an **Abstract Factory** to produce the correct family of objects.

---

## 🧩 Step-by-Step Code Example

---

### 🔹 1. Product Interfaces

```java
public interface Button {
    void render();
}

public interface Checkbox {
    void render();
}
```

---

### 🔹 2. Concrete Products

#### ✅ Windows Family

```java
public class WindowsButton implements Button {
    public void render() {
        System.out.println("Rendering Windows Button");
    }
}

public class WindowsCheckbox implements Checkbox {
    public void render() {
        System.out.println("Rendering Windows Checkbox");
    }
}
```

#### 🍎 Mac Family

```java
public class MacButton implements Button {
    public void render() {
        System.out.println("Rendering Mac Button");
    }
}

public class MacCheckbox implements Checkbox {
    public void render() {
        System.out.println("Rendering Mac Checkbox");
    }
}
```

---

### 🔹 3. Abstract Factory

```java
public interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
```

---

### 🔹 4. Concrete Factories

```java
public class WindowsFactory implements GUIFactory {
    public Button createButton() {
        return new WindowsButton();
    }

    public Checkbox createCheckbox() {
        return new WindowsCheckbox();
    }
}

public class MacFactory implements GUIFactory {
    public Button createButton() {
        return new MacButton();
    }

    public Checkbox createCheckbox() {
        return new MacCheckbox();
    }
}
```

---

### 🔹 5. Client Code

```java
public class Application {
    private Button button;
    private Checkbox checkbox;

    public Application(GUIFactory factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    public void renderUI() {
        button.render();
        checkbox.render();
    }
}
```

---

### 🔹 6. Main Class

```java
public class AbstractFactoryDemo {
    public static void main(String[] args) {
        // Choose your OS/environment
        GUIFactory factory = new WindowsFactory();  // or new MacFactory()
        
        Application app = new Application(factory);
        app.renderUI();
    }
}
```

---

### ✅ Output (if using WindowsFactory)

```
Rendering Windows Button
Rendering Windows Checkbox
```

### ✅ Output (if using MacFactory)

```
Rendering Mac Button
Rendering Mac Checkbox
```

---

## 🧠 When to Use Abstract Factory

| Use Case                                            | Why?                                              |
| --------------------------------------------------- | ------------------------------------------------- |
| Need to create **families of related objects**      | Like GUI components that vary by OS               |
| Want to enforce **consistency among products**      | E.g., all components look and behave per OS style |
| Want to isolate concrete class creation from client | Clean decoupling and easy to extend               |

---

## 🟩 Difference: Factory Method vs Abstract Factory

| Factory Method       | Abstract Factory                    |
| -------------------- | ----------------------------------- |
| Creates one object   | Creates families of related objects |
| Involves inheritance | Involves composition                |
| Usually one product  | Multiple related products           |
