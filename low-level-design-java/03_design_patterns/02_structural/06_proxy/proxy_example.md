## ✅ Definition

The **Proxy Design Pattern** is a **structural pattern** that:

> Provides a **placeholder (proxy)** for another object to **control access** to it.

The proxy typically acts as an **intermediary**, adding extra behavior (e.g., logging, access control, lazy loading) **without changing the original object**.

---

## 🎯 Analogy

🔐 *Think of a security guard outside a vault.*

* The **vault** holds the valuable items.
* You don’t go directly to the vault—you go through the **guard**, who checks your access and then allows or denies entry.

The **guard is the proxy** controlling access to the real object (vault).

---

## 👨‍💻 Java Code Example

Let’s simulate a **Video Streaming Service**:

* Real object: `RealVideoDownloader`
* Proxy: `VideoDownloaderProxy` adds **access control** and **caching**

---

### 1. Subject Interface

```java
public interface VideoDownloader {
    void downloadVideo(String url);
}
```

---

### 2. Real Subject

```java
public class RealVideoDownloader implements VideoDownloader {
    public void downloadVideo(String url) {
        System.out.println("Downloading video from: " + url);
    }
}
```

---

### 3. Proxy

```java
import java.util.HashSet;
import java.util.Set;

public class VideoDownloaderProxy implements VideoDownloader {
    private RealVideoDownloader realDownloader = new RealVideoDownloader();
    private Set<String> cache = new HashSet<>();
    private boolean hasAccess;

    public VideoDownloaderProxy(boolean hasAccess) {
        this.hasAccess = hasAccess;
    }

    public void downloadVideo(String url) {
        if (!hasAccess) {
            System.out.println("Access Denied: You don't have permission to download videos.");
            return;
        }

        if (cache.contains(url)) {
            System.out.println("Fetching video from cache: " + url);
        } else {
            realDownloader.downloadVideo(url);
            cache.add(url);
        }
    }
}
```

---

### 4. Client

```java
public class ProxyPatternClient {
    public static void main(String[] args) {
        VideoDownloader downloader = new VideoDownloaderProxy(true);
        downloader.downloadVideo("http://youtube.com/video1");
        downloader.downloadVideo("http://youtube.com/video1"); // Will use cache

        VideoDownloader unauthorizedDownloader = new VideoDownloaderProxy(false);
        unauthorizedDownloader.downloadVideo("http://youtube.com/video2"); // Access Denied
    }
}
```

---

## 🌟 Key Benefits

✅ Add **access control, caching, logging, lazy loading**
✅ Client code doesn't know whether it’s talking to real object or proxy
✅ Enhances existing code without modifying it
✅ Improves **performance** and **security**

---

## 📌 When to Use

* **Access Control**: Restrict access to sensitive resources (e.g., database, network)
* **Caching**: Avoid repeated expensive operations
* **Lazy Initialization**: Defer object creation until needed
* **Logging / Auditing**: Log method calls without modifying real object
* **Remote Proxy**: Access object over network (RMI, gRPC)

---

## ⚠️ Limitations or Caveats

* Adds extra layer of complexity
* Can be **misused** if not clearly documented
* Needs careful maintenance if behavior of real object changes

---

## 🧱 SOLID Principles

* ✅ **S – SRP**: Proxy and real object have different responsibilities
* ✅ **O – OCP**: Easily extend behavior by adding new proxy types
* ✅ **L – LSP**: Proxy should behave the same as the real object
* ✅ **I – ISP**: Minimal interface (`VideoDownloader`)
* ✅ **D – DIP**: Client depends on interface, not implementation

---

## 📐 UML Diagram

```plaintext
              +----------------------+
              |  VideoDownloader     |  <<interface>>
              +----------------------+
                       ▲
         +---------------------+      +------------------------+
         | RealVideoDownloader |      | VideoDownloaderProxy   |
         +---------------------+      +------------------------+
         | +downloadVideo()    |      | +downloadVideo()       |
         +---------------------+      | - RealVideoDownloader  |
                                      | - Cache, AccessControl |
                                      +------------------------+

                       ▲
                       |
              +----------------------+
              |  ProxyPatternClient  |
              +----------------------+
```

---

## 🌍 Real-World Use Cases

* **Java RMI**: Remote objects are accessed through stubs (proxies)
* **Spring AOP Proxies**: Used for logging, transactions, security
* **Hibernate Lazy Loading**: Entity proxies created to defer DB calls
* **Firewall or API gateway**: Controls who can access the actual service

---

## ✅ Summary (Interview Ready)

* **Pattern Name**: Proxy Pattern
* **Type**: Structural
* **Use When**: You want to **control access** to an object
* **Common Uses**: Logging, security, lazy loading, caching
* **Real Java Example**: RMI, Spring AOP, Hibernate lazy loading

