## 🎮 Scenario:

* You have enemy types like **Orc** and **Troll**.
* Each enemy has attributes like `name`, `weapon`, and `health`.
* Instead of creating new enemies from scratch, you **clone a prototype** and tweak attributes as needed.

---

### 📦 Step-by-Step Java Code

---

### 🔹 1. Enemy Prototype Interface

```java
public interface Enemy extends Cloneable {
    Enemy clone();
    void attack();
}
```

---

### 🔹 2. Concrete Class: Orc

```java
public class Orc implements Enemy {
    private String name;
    private String weapon;
    private int health;

    public Orc(String name, String weapon, int health) {
        this.name = name;
        this.weapon = weapon;
        this.health = health;
    }

    @Override
    public void attack() {
        System.out.println(name + " attacks with " + weapon + "! (Health: " + health + ")");
    }

    @Override
    public Enemy clone() {
        try {
            return (Orc) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException("Clone not supported!");
        }
    }

    // Setters to tweak after cloning
    public void setName(String name) {
        this.name = name;
    }

    public void setHealth(int health) {
        this.health = health;
    }
}
```

---

### 🔹 3. Concrete Class: Troll

```java
public class Troll implements Enemy {
    private String name;
    private String weapon;
    private int health;

    public Troll(String name, String weapon, int health) {
        this.name = name;
        this.weapon = weapon;
        this.health = health;
    }

    @Override
    public void attack() {
        System.out.println(name + " smashes with " + weapon + "! (Health: " + health + ")");
    }

    @Override
    public Enemy clone() {
        try {
            return (Troll) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException("Clone not supported!");
        }
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setHealth(int health) {
        this.health = health;
    }
}
```

---

### 🔹 4. Enemy Factory (Prototype Registry)

```java
import java.util.HashMap;
import java.util.Map;

public class EnemyFactory {
    private static Map<String, Enemy> prototypes = new HashMap<>();

    static {
        prototypes.put("orc", new Orc("Orc Warrior", "Axe", 100));
        prototypes.put("troll", new Troll("Troll Brute", "Club", 150));
    }

    public static Enemy getEnemy(String type) {
        Enemy prototype = prototypes.get(type.toLowerCase());
        return prototype != null ? prototype.clone() : null;
    }
}
```

---

### 🔹 5. Client Code: Game Simulator

```java
public class GameSimulator {
    public static void main(String[] args) {
        // Clone orc and customize
        Orc orc1 = (Orc) EnemyFactory.getEnemy("orc");
        orc1.setName("Orc Grunt");
        orc1.setHealth(80);
        orc1.attack();

        // Clone troll and customize
        Troll troll1 = (Troll) EnemyFactory.getEnemy("troll");
        troll1.setName("Troll King");
        troll1.setHealth(200);
        troll1.attack();

        // Clone default prototype again
        Orc orc2 = (Orc) EnemyFactory.getEnemy("orc");
        orc2.attack(); // Still has original prototype values
    }
}
```

---

### ✅ Output:

```
Orc Grunt attacks with Axe! (Health: 80)
Troll King smashes with Club! (Health: 200)
Orc Warrior attacks with Axe! (Health: 100)
```

---

## 🧠 Notes:

* `EnemyFactory` stores prototype objects.
* Each time you request an enemy, a **clone** is returned.
* You can **tweak** the clone's attributes without affecting the original prototype.
* Efficient when spawning many similar objects (e.g., game entities).
