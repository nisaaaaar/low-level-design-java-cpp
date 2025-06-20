## ✅ Definition

The **Composite Design Pattern** is a **structural pattern** used to treat **individual objects** and **compositions of objects** uniformly.

> It allows clients to work with **individual objects (leaf)** and **groups of objects (composites)** in the **same way**, making your code tree-structure-friendly.

---

## 🎯 Analogy

🪴 *Think of a tree.*

* A **leaf** is a single leaf — a terminal element.
* A **branch** is a composite — it can contain many leaves or even other branches.

When you want to **water** a tree, you just call `water()` on the tree. You don’t care whether it's a leaf or branch—it gets handled.

---

## 👨‍💻 Code Example in Java

We’ll model a **file system**:

* `File` = leaf
* `Folder` = composite

```java
// 1. Component
interface FileSystemComponent {
    void showDetails();
}

// 2. Leaf
class File implements FileSystemComponent {
    private String name;

    public File(String name) {
        this.name = name;
    }

    public void showDetails() {
        System.out.println("File: " + name);
    }
}

// 3. Composite
class Folder implements FileSystemComponent {
    private String name;
    private List<FileSystemComponent> components = new ArrayList<>();

    public Folder(String name) {
        this.name = name;
    }

    public void addComponent(FileSystemComponent component) {
        components.add(component);
    }

    public void showDetails() {
        System.out.println("Folder: " + name);
        for (FileSystemComponent component : components) {
            component.showDetails();
        }
    }
}

// 4. Client
public class FileSystemClient {
    public static void main(String[] args) {
        File file1 = new File("Resume.pdf");
        File file2 = new File("Photo.png");

        Folder folder1 = new Folder("Documents");
        folder1.addComponent(file1);

        Folder folder2 = new Folder("Pictures");
        folder2.addComponent(file2);

        Folder root = new Folder("Root");
        root.addComponent(folder1);
        root.addComponent(folder2);

        root.showDetails();
    }
}
```

---

## 🌟 Key Benefits

✅ **Tree structure support** (recursive compositions)
✅ **Uniformity**: Treat objects and groups of objects the same
✅ **Open-Closed Principle**: Easy to add new types of components
✅ Simplifies **client code** (no need to differentiate leaf/composite)

---

## 📌 When to Use

* You need to represent a **part-whole hierarchy**
* You want to **treat individual and composite objects uniformly**
* Common in **GUI**, **file systems**, **organization structures**, etc.

---

## ⚠️ Limitations or Caveats

* Can make the design overly general
* Makes type checks harder if specific behavior is only applicable to leaves
* Might violate **Liskov Substitution Principle** if leaf doesn’t support all methods in interface

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Each class has one responsibility (leaf or composite behavior)
* ✅ **O – OCP**: You can add new component types without changing code
* ⚠️ **L – LSP**: If not all components support operations (e.g., add), can break substitution
* ✅ **I – ISP**: Interface is minimal (`showDetails()`)
* ✅ **D – DIP**: High-level code (like `Folder`) depends on abstractions (`FileSystemComponent`)

---

## 📐 UML Diagram

```plaintext
           +--------------------------+
           | FileSystemComponent (interface) |
           +--------------------------+
                    ▲
     +--------------+---------------+
     |                              |
+-------------+            +------------------+
|   File      |            |     Folder       |
+-------------+            +------------------+
| - name      |            | - name           |
|             |            | - List<Component>|
+-------------+            +------------------+
| +showDetails()|          | +addComponent()  |
|               |          | +showDetails()   |
+---------------+          +------------------+
```

---

## 🌍 Real-World Use Case

* **GUI components**: A `Panel` (Folder) can contain other `Buttons`, `Labels`, or other `Panels`. When rendering, you call `render()` on the top panel.
* **Company hierarchy**: `Employee` can be a manager or individual contributor. You can call `getDetails()` on any employee.

---

## ✅ Summary (for Interview)

* **Pattern Name**: Composite Pattern
* **Type**: Structural
* **Use When**: You have a tree structure (e.g., files, GUI, org chart)
* **Key Benefit**: Treat leaf and composite objects uniformly
* **Java Tip**: Interface + recursion + composition is the key
