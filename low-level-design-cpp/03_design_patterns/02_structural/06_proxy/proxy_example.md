## ✅ Definition

**Proxy Pattern** is a **structural design pattern** that:

> “**Provides a surrogate or placeholder** for another object to **control access** to it.”

The Proxy acts as a stand-in for the **Real Object** and can perform actions **before or after** delegating to the actual object.

---

## 🎯 Analogy

> Think of a **receptionist** in an office:

* You don’t go directly to the CEO.
* You first go through the **receptionist** (proxy), who checks if you're allowed in, schedules your time, etc.

---

## 💻 Real-World Code Example in C++

Let’s model a **Secure Document Viewer**:

* Only **authorized users** can access confidential documents.
* A proxy controls access to the real document.

### ✅ Classes:

* `IDocument` (Interface)
* `RealDocument` (Performs the actual action)
* `DocumentProxy` (Controls access to `RealDocument`)
* `Client` (Uses the proxy)

```cpp
#include <iostream>
#include <string>
#include <memory>

// Subject Interface
class IDocument {
public:
    virtual void display() const = 0;
    virtual ~IDocument() = default;
};

// Real Subject
class RealDocument : public IDocument {
private:
    std::string filename;

public:
    RealDocument(const std::string& file) : filename(file) {
        loadFromDisk();
    }

    void loadFromDisk() const {
        std::cout << "Loading document: " << filename << std::endl;
    }

    void display() const override {
        std::cout << "Displaying document: " << filename << std::endl;
    }
};

// Proxy
class DocumentProxy : public IDocument {
private:
    std::string filename;
    std::string userRole;
    mutable std::shared_ptr<RealDocument> realDocument;

public:
    DocumentProxy(const std::string& file, const std::string& role)
        : filename(file), userRole(role), realDocument(nullptr) {}

    void display() const override {
        if (userRole == "Admin") {
            if (!realDocument) {
                realDocument = std::make_shared<RealDocument>(filename);
            }
            realDocument->display();
        } else {
            std::cout << "Access denied. You do not have permission to view this document.\n";
        }
    }
};

// Client Code
int main() {
    std::shared_ptr<IDocument> adminView = std::make_shared<DocumentProxy>("classified.pdf", "Admin");
    std::shared_ptr<IDocument> guestView = std::make_shared<DocumentProxy>("classified.pdf", "Guest");

    adminView->display();
    std::cout << "----\n";
    guestView->display();

    return 0;
}
```

---

## ✅ Output

```
Loading document: classified.pdf
Displaying document: classified.pdf
----
Access denied. You do not have permission to view this document.
```

---

## ✅ UML Diagram

```
         +-------------+
         |  IDocument  |<<interface>>
         +-------------+
         | +display()  |
         +-------------+
              /_\
               |
      ---------------------
      |                   |
+----------------+  +-----------------+
|  RealDocument  |  |  DocumentProxy  |
+----------------+  +-----------------+
| - filename     |  | - filename      |
| +display()     |  | - userRole      |
|                |  | - realDocument  |
+----------------+  | +display()      |
                    +-----------------+
```

---

## ✅ Key Benefits

* **Access control**: Restrict access based on roles or logic.
* **Lazy initialization**: Delay creation of expensive objects.
* **Logging, caching, or validation**: Easily added in the proxy.

---

## ✅ When to Use

* When you need **controlled access** to an object.
* When an object is **expensive to create**, and you want to **delay** its creation (Virtual Proxy).
* When you need **remote access**, logging, or **permission checks**.

---

## ❗ Limitations or Caveats

* Adds **extra layer of abstraction**, increasing complexity.
* Can **hide side effects** if not documented clearly.
* If overused, may lead to **performance overhead**.

---

## ✅ SOLID Principles Followed

* ✅ **S**ingle Responsibility: Proxy handles access; RealDocument handles business logic.
* ✅ **O**pen/Closed: New types of proxies (e.g., logging) can be added without changing the core classes.
* ✅ **L**iskov: Proxy and RealDocument can be used interchangeably.
* ✅ **I**nterface Segregation: Interface is minimal and focused.
* ✅ **D**ependency Inversion: Client depends on the `IDocument` abstraction.

---

## 🌍 Real-World Use Cases

* **Access control systems**: Role-based access to resources.
* **Database connection pooling**: Proxy manages access to real DB objects.
* **Remote proxy**: Accessing objects in different address spaces (RPC, CORBA).
* **Virtual proxy**: Loading large images/documents only when needed (e.g., in IDEs or games).

---

## 📝 Interview-Ready Summary

> The **Proxy Pattern** is used when I want to **control access to a real object**. For example, if only Admins can open a secure document, I can use a `DocumentProxy` to check roles before allowing access to the actual `RealDocument`. It’s useful for **access control**, **lazy loading**, and **monitoring**, and it **follows SOLID principles** well by decoupling responsibility and hiding complexity from the client.
