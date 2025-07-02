## ✅ Definition

The **Iterator Pattern** is a **behavioral design pattern** that:

> Provides a way to **access elements of a collection sequentially** without exposing its internal structure.

It lets clients **traverse** a collection without knowing how it's implemented.

---

## 🎯 Analogy

📚 *Think of a bookshelf*:

* A shelf holds books (internally, an array or list).
* You don’t need to know **how** they’re stored — you use a **bookmark or your finger** to move from one book to the next.

The bookmark is your **iterator** — a tool to **sequentially access elements**.

---

## 👨‍💻 Java Code Example – Book Collection

We’ll create:

* `Book`: Element class
* `BookCollection`: Custom collection
* `BookIterator`: Iterator
* `Client`: Uses iterator to loop through books

---

### 1. Book (Element)

```java
public class Book {
    private String name;

    public Book(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
```

---

### 2. Iterator Interface

```java
public interface Iterator<T> {
    boolean hasNext();
    T next();
}
```

---

### 3. Collection Interface

```java
public interface BookCollection {
    void addBook(Book book);
    Iterator<Book> createIterator();
}
```

---

### 4. Concrete Collection

```java
import java.util.ArrayList;
import java.util.List;

public class Library implements BookCollection {
    private List<Book> books = new ArrayList<>();

    public void addBook(Book book) {
        books.add(book);
    }

    public Iterator<Book> createIterator() {
        return new LibraryIterator(books);
    }
}
```

---

### 5. Concrete Iterator

```java
import java.util.List;

public class LibraryIterator implements Iterator<Book> {
    private List<Book> books;
    private int index = 0;

    public LibraryIterator(List<Book> books) {
        this.books = books;
    }

    public boolean hasNext() {
        return index < books.size();
    }

    public Book next() {
        return books.get(index++);
    }
}
```

---

### 6. Client

```java
public class IteratorClient {
    public static void main(String[] args) {
        Library library = new Library();
        library.addBook(new Book("Design Patterns"));
        library.addBook(new Book("Clean Code"));
        library.addBook(new Book("Effective Java"));

        Iterator<Book> iterator = library.createIterator();

        while (iterator.hasNext()) {
            Book book = iterator.next();
            System.out.println("Reading: " + book.getName());
        }
    }
}
```

---

## 🌟 Key Benefits

✅ Provides **uniform way to traverse** different collections
✅ **Hides internal structure** of the collection
✅ Makes code **more reusable** and **cleaner**
✅ Allows multiple **simultaneous iterations**

---

## 📌 When to Use

* You want to **access elements without exposing internal structure**
* You want to **support multiple types of traversal** (forward, backward, etc.)
* You need to **iterate over custom collections**

---

## ⚠️ Limitations or Caveats

* May **slow performance** slightly due to abstraction
* Can add **extra classes** and complexity in small projects
* Iterators must be kept in sync with the underlying collection

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Iterator and collection responsibilities are separate
* ✅ **O – OCP**: Add new traversal logic without changing existing code
* ✅ **L – LSP**: Iterator can replace collection access
* ✅ **I – ISP**: Simple, focused interfaces (`Iterator<T>`)
* ✅ **D – DIP**: Code uses abstractions (`Iterator<T>`, not List)

---

## 📐 UML Diagram

```plaintext
      +-------------------+
      |   Book            |
      +-------------------+
      | - name            |
      | +getName()        |
      +-------------------+

             ▲
             |
      +-------------------+       +------------------+
      |  BookCollection   |<------+    Library       |
      +-------------------+       +------------------+
      | +addBook()        |       | - List<Book>     |
      | +createIterator() |       | +addBook()       |
      +-------------------+       | +createIterator()|
                                  +------------------+

      +-------------------+       +----------------------+
      |   Iterator<T>     |<------+   LibraryIterator    |
      +-------------------+       +----------------------+
      | +hasNext()        |       | - List<Book> books   |
      | +next()           |       | - int index          |
      +-------------------+       | +hasNext(), next()   |
                                  +----------------------+

                       ▲
                       |
              +-------------------+
              |  IteratorClient   |
              +-------------------+
```

---

## 🌍 Real-World Use Cases

* **Java Collections Framework**: `List`, `Set`, `Map` use built-in `Iterator`
* **DOM Tree Traversal**: Iterate over child nodes
* **Custom Game Engines or GUI Frameworks**: Traverse scenes, UI elements
* **Database ResultSet**: Cursor/iterator for result rows

---

## ✅ Summary (Interview Ready)

* **Pattern Name**: Iterator
* **Type**: Behavioral
* **Use When**: You want to **traverse a collection without exposing its structure**
* **Java Example**: `Iterator<T>` in `java.util`
* **Key Benefit**: Clean, uniform access to collections
