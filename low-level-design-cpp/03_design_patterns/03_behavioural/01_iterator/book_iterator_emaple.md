## ✅ Definition

The **Iterator Pattern** is a **behavioral design pattern** that:

> “Provides a way to **access elements of a collection sequentially** without exposing its underlying representation.”

---

## 🎯 Analogy

📚 *Think of a bookshelf*:

* You use a **bookmark** (iterator) to move from book to book.
* You don’t care if the books are stored in a list, array, or stack — the bookmark gives you **sequential access**.

---

## 👨‍💻 C++ Code Example – Book Library

### ✅ Classes:

* `Book` – Element
* `Iterator` – Abstract Iterator Interface
* `BookIterator` – Concrete Iterator
* `BookCollection` – Abstract Aggregate
* `Library` – Concrete Collection
* `Client` – Uses the iterator

---

### 1. Book

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Book {
    std::string name;
public:
    Book(std::string name) : name(name) {}
    std::string getName() const { return name; }
};
```

---

### 2. Iterator Interface

```cpp
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};
```

---

### 3. Collection Interface

```cpp
template<typename T>
class BookCollection {
public:
    virtual void addBook(const T& book) = 0;
    virtual std::shared_ptr<Iterator<T>> createIterator() const = 0;
    virtual ~BookCollection() = default;
};
```

---

### 4. Concrete Collection (Library)

```cpp
class Library : public BookCollection<Book> {
    std::vector<Book> books;
public:
    void addBook(const Book& book) override {
        books.push_back(book);
    }

    std::shared_ptr<Iterator<Book>> createIterator() const override;
    const std::vector<Book>& getBooks() const { return books; }
};
```

---

### 5. Concrete Iterator (BookIterator)

```cpp
class BookIterator : public Iterator<Book> {
    const std::vector<Book>& books;
    mutable size_t index = 0;

public:
    BookIterator(const std::vector<Book>& books) : books(books) {}

    bool hasNext() const override {
        return index < books.size();
    }

    Book next() override {
        return books.at(index++);
    }
};

std::shared_ptr<Iterator<Book>> Library::createIterator() const {
    return std::make_shared<BookIterator>(books);
}
```

---

### 6. Client Code

```cpp
int main() {
    Library library;
    library.addBook(Book("Design Patterns"));
    library.addBook(Book("Clean Code"));
    library.addBook(Book("Effective C++"));

    auto iterator = library.createIterator();

    while (iterator->hasNext()) {
        Book book = iterator->next();
        std::cout << "Reading: " << book.getName() << std::endl;
    }

    return 0;
}
```

---

## ✅ Output

```
Reading: Design Patterns
Reading: Clean Code
Reading: Effective C++
```

---

## ✅ UML Diagram

```
      +------------+             
      |   Book     |
      +------------+
      | - name     |
      | +getName() |
      +------------+

            ▲
            |
     +-----------------+     +---------------+
     | BookCollection  |<----|   Library      |
     +-----------------+     +---------------+
     | +addBook()      |     | - books        |
     | +createIterator()|    | +addBook()     |
     +-----------------+     | +createIterator|
                             +---------------+

     +----------------+      +-------------------+
     | Iterator<T>    |<-----|   BookIterator     |
     +----------------+      +-------------------+
     | +hasNext()     |      | - books           |
     | +next()        |      | - index           |
     +----------------+      | +hasNext(), next()|
                             +-------------------+

                      ▲
                      |
              +----------------+
              |    Client      |
              +----------------+
```

---

## 🌟 Key Benefits

✅ **Sequential access** without exposing structure
✅ Works with **custom containers**
✅ Enables **multiple simultaneous iterations**
✅ Makes code **cleaner and more maintainable**

---

## 📌 When to Use

* To **traverse** a custom data structure
* To support **forward/backward/multiple** traversal strategies
* To avoid exposing internal collection logic to the client

---

## ⚠️ Limitations or Caveats

* Adds **extra classes**
* Slight **performance overhead**
* Need to keep iterators in **sync with collection modifications**

---

## ✅ SOLID Principles

* **S – SRP**: Collection and traversal logic are separate
* **O – OCP**: New iterator strategies (reverse, filter) can be added easily
* **L – LSP**: Iterator abstraction can be replaced with any concrete type
* **I – ISP**: Focused, clean interface
* **D – DIP**: Client depends on `Iterator<T>` abstraction, not concrete types

---

## 🌍 Real-World Use Cases

* **C++ STL iterators**: `begin()`, `end()` loops over containers
* **Game engines**: Iterating over game entities
* **Custom GUI components**: Traversing UI elements
* **Tree/Graph traversal**: BFS/DFS with custom containers

---

## ✅ Interview Summary

> The **Iterator Pattern** allows me to **access elements in a collection sequentially** without exposing how they’re stored. In C++, this is similar to STL iterators. It helps **decouple collection logic from traversal logic**, making it easier to support **multiple traversal strategies**, and follows **SOLID principles** well.
