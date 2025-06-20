## ✅ Definition

The **Facade Pattern** is a **structural design pattern** that:

> **Provides a simplified interface** to a complex subsystem of classes, libraries, or APIs.

It hides the complexities of the subsystem and provides a **high-level interface** to the client.

---

## 🎯 Analogy

🎬 *Think of a TV remote.*

* Behind the scenes: the TV has circuits, processors, tuners, and settings.
* But you only need a **remote** to turn it on, change channels, and adjust volume.

The **remote control is the facade**—a simple interface over a complex system.

---

## 👨‍💻 Java Code Example

Let’s model a **Home Theater System**:

* Subsystems: `DVDPlayer`, `Projector`, `Amplifier`
* `HomeTheaterFacade` is the high-level class used by the client

### 1. Subsystem Classes

```java
public class DVDPlayer {
    public void on() { System.out.println("DVD Player ON"); }
    public void play(String movie) { System.out.println("Playing movie: " + movie); }
    public void off() { System.out.println("DVD Player OFF"); }
}
```

```java
public class Projector {
    public void on() { System.out.println("Projector ON"); }
    public void setInput(String input) { System.out.println("Projector input set to: " + input); }
    public void off() { System.out.println("Projector OFF"); }
}
```

```java
public class Amplifier {
    public void on() { System.out.println("Amplifier ON"); }
    public void setVolume(int level) { System.out.println("Volume set to: " + level); }
    public void off() { System.out.println("Amplifier OFF"); }
}
```

### 2. Facade Class

```java
public class HomeTheaterFacade {
    private DVDPlayer dvd;
    private Projector projector;
    private Amplifier amp;

    public HomeTheaterFacade(DVDPlayer dvd, Projector projector, Amplifier amp) {
        this.dvd = dvd;
        this.projector = projector;
        this.amp = amp;
    }

    public void watchMovie(String movie) {
        System.out.println("Get ready to watch a movie...");
        dvd.on();
        projector.on();
        projector.setInput("DVD");
        amp.on();
        amp.setVolume(5);
        dvd.play(movie);
    }

    public void endMovie() {
        System.out.println("Shutting down the movie theater...");
        dvd.off();
        projector.off();
        amp.off();
    }
}
```

### 3. Client

```java
public class MovieNight {
    public static void main(String[] args) {
        DVDPlayer dvd = new DVDPlayer();
        Projector projector = new Projector();
        Amplifier amp = new Amplifier();

        HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvd, projector, amp);
        homeTheater.watchMovie("Inception");
        homeTheater.endMovie();
    }
}
```

---

## 🌟 Key Benefits

✅ Simplifies complex subsystems
✅ Reduces dependencies between client and many subsystem classes
✅ Promotes **loose coupling**
✅ Easy to use and maintain

---

## 📌 When to Use

* You have a **complex system** with many interdependent classes
* You want to provide a **simple API** to clients
* You want to **encapsulate** a system behind a cleaner interface

---

## ⚠️ Limitations or Caveats

* May become a **God object** if not designed carefully
* Doesn’t eliminate complexity—just **hides it**
* Can reduce flexibility if too much functionality is hidden

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Facade has a single role—to simplify usage of a subsystem
* ✅ **O – OCP**: You can extend subsystem behavior without changing the facade
* ✅ **L – LSP**: Not very relevant, but respected if all subsystems behave predictably
* ✅ **I – ISP**: Facade provides only needed methods, hiding verbose APIs
* ✅ **D – DIP**: Facade depends on abstractions (e.g., interfaces), not concrete subsystems (if applied well)

---

## 📐 UML Diagram

```plaintext
                 +---------------------+
                 |   MovieNight (Client)|
                 +---------------------+
                            |
                            v
                 +----------------------+
                 | HomeTheaterFacade    |
                 +----------------------+
                 | +watchMovie()        |
                 | +endMovie()          |
                 +----------------------+
                    /     |       \
                   v      v        v
         +-----------+  +----------+  +-----------+
         | DVDPlayer |  | Projector|  | Amplifier |
         +-----------+  +----------+  +-----------+
```

---

## 🌍 Real-World Use Case

* **Spring’s JdbcTemplate** is a facade over raw JDBC logic (open connection, create statement, execute query, handle exceptions, etc.)
* **Java Servlet API** uses `HttpServletRequest` and `HttpServletResponse` to simplify complex request-handling logic.
* **Build tools** like Maven or Gradle provide a simple command-line interface but internally perform complex dependency resolution and compilation.

---

## ✅ Summary (for Interview)

* **Pattern Name**: Facade Pattern
* **Type**: Structural
* **Use When**: You want to **simplify a complex system**
* **Key Benefit**: Provides a **unified interface** to a set of subsystems
* **Java Example**: `JdbcTemplate`, `HttpServletRequest`

