## 🧩 **Adapter Design Pattern in Java**

---

### ✅ **Definition**

The **Adapter Pattern** is a **structural design pattern** that allows objects with **incompatible interfaces to work together**. It **wraps an existing class** with a new interface so that it becomes compatible with the client.

---

### 🎯 **Analogy**

> Imagine a **memory card** and a **laptop**.
> The laptop only supports **USB**, but your memory card is **SD format**.
> You use an **SD card reader (adapter)** to connect it via USB.
> → The adapter **translates** the SD card interface to USB, making it usable.

---

## 💻 **Code Example**

### 👇 **Scenario**:

You have a `CreditCardPaymentGateway` in your system, but now a client wants to use `PayPal`. Their interfaces are different.

---

### 1️⃣ **Target Interface**

```java
public interface PaymentGateway {
    void pay(String amount);
}
```

---

### 2️⃣ **Adaptee (Incompatible Class)**

```java
public class PayPalGateway {
    public void makePayment(String amountInDollars) {
        System.out.println("Payment done via PayPal: $" + amountInDollars);
    }
}
```

---

### 3️⃣ **Adapter**

```java
public class PayPalAdapter implements PaymentGateway {
    private PayPalGateway payPalGateway;

    public PayPalAdapter(PayPalGateway payPalGateway) {
        this.payPalGateway = payPalGateway;
    }

    @Override
    public void pay(String amount) {
        payPalGateway.makePayment(amount);
    }
}
```

---

### 4️⃣ **Another Compatible Class**

```java
public class CreditCardPaymentGateway implements PaymentGateway {
    @Override
    public void pay(String amount) {
        System.out.println("Payment done via Credit Card: $" + amount);
    }
}
```

---

### 5️⃣ **Client Code**

```java
public class PaymentProcessor {
    public static void main(String[] args) {
        PaymentGateway creditCardPayment = new CreditCardPaymentGateway();
        creditCardPayment.pay("100");

        PaymentGateway paypalPayment = new PayPalAdapter(new PayPalGateway());
        paypalPayment.pay("250");
    }
}
```

---

### ✅ **Output**

```
Payment done via Credit Card: $100
Payment done via PayPal: $250
```

---

## 📈 **Key Benefits**

* ✅ **Reusability** of existing classes (like PayPal SDK).
* ✅ Enables **interfacing with legacy or third-party code**.
* ✅ Promotes **Open/Closed Principle**—you can add adapters without changing client code.
* ✅ **Clean separation** of responsibilities.

---

## ⏱️ **When to Use**

* When you need to **integrate legacy or third-party classes**.
* When the interface of an existing class **doesn't match** what the client expects.
* When you want to **reuse existing code** without modifying it.

---

## ⚠️ **Limitations / Caveats**

* ❌ Adds an **extra layer of abstraction** (may affect performance slightly).
* ❌ Can cause **design clutter** if overused.
* ❌ Doesn’t work well when **interfaces are deeply incompatible**.

---

## 📐 **UML Diagram**

```plaintext
+---------------------+       uses       +-------------------+
|     Client          |---------------->|  PaymentGateway    |
+---------------------+                 +-------------------+
                                              /\
                                              |
                   +--------------------------+--------------------------+
                   |                                                     |
       +--------------------------+                        +-----------------------+
       | CreditCardPaymentGateway |                        |     PayPalAdapter     |
       +--------------------------+                        +-----------------------+
                                                            |
                                                  +---------------------+
                                                  |    PayPalGateway    |
                                                  +---------------------+
```

---

## 🌍 **Real-World Software Use Case**

### ▶️ **Payment Integration**

Suppose you're building an **e-commerce platform** that already supports credit card payments via `PaymentGateway`.
Now you need to integrate **PayPal**, which uses a different interface.
Using an **Adapter**, you can wrap the PayPal SDK so that it matches the existing `PaymentGateway` interface—**no need to change client logic**.

---

## 📏 **SOLID Principle Mapping**

| Principle | Applied? | Why?                                                            |
| --------- | -------- | --------------------------------------------------------------- |
| ✅ SRP     | Yes      | Adapter only translates interfaces                              |
| ✅ OCP     | Yes      | You can add new payment types without changing existing code    |
| ✅ LSP     | Yes      | Adapter can be substituted for any `PaymentGateway`             |
| ✅ ISP     | Yes      | Interface (`PaymentGateway`) is minimal                         |
| ✅ DIP     | Yes      | `PaymentProcessor` depends on abstraction, not a concrete class |

---

## ✅ **Interview Summary (What to Say)**

> The Adapter Pattern lets incompatible classes work together by wrapping one interface into another.
> I used it in an e-commerce scenario to adapt PayPal's interface to our internal `PaymentGateway` system without modifying existing code.
> It supports SOLID principles, especially OCP and DIP, and is commonly used in payment integrations, legacy code handling, and library bridging.


Yes, you're absolutely right — **in the current implementation**, the **client (`PaymentProcessor`) needs to know**:

* Which payment gateway works directly (`CreditCardPaymentGateway`)
* Which one needs an adapter (`PayPalAdapter(new PayPalGateway())`)

This creates a **tight coupling between the client and the adapter logic**, which violates the **Open/Closed Principle** and can make the client messy as more payment methods are added.

---

## ✅ How to Improve This?

### 💡 Use a **Factory** or **Strategy** pattern to **hide adapter logic** from the client.

Let’s update the design to **delegate the adapter creation to a factory** so the client simply asks for a `PaymentGateway` by type.

---

## 🔄 Updated Design with Factory

### 1️⃣ Add Enum for Payment Types

```java
public enum PaymentType {
    CREDIT_CARD,
    PAYPAL
}
```

---

### 2️⃣ PaymentGatewayFactory

```java
public class PaymentGatewayFactory {
    public static PaymentGateway getPaymentGateway(PaymentType type) {
        return switch (type) {
            case CREDIT_CARD -> new CreditCardPaymentGateway();
            case PAYPAL -> new PayPalAdapter(new PayPalGateway());
        };
    }
}
```

---

### 3️⃣ Simplified Client

```java
public class PaymentProcessor {
    public static void main(String[] args) {
        PaymentGateway creditCardPayment = PaymentGatewayFactory.getPaymentGateway(PaymentType.CREDIT_CARD);
        creditCardPayment.pay("100");

        PaymentGateway paypalPayment = PaymentGatewayFactory.getPaymentGateway(PaymentType.PAYPAL);
        paypalPayment.pay("250");
    }
}
```

---

## ✅ Now the client:

* Doesn’t need to know which payment type needs an adapter.
* Only relies on abstraction (`PaymentGateway`).
* Follows **Open/Closed** and **Dependency Inversion Principles**.

---

### 📌 Summary

Yes, your observation is correct — **without abstraction**, the client becomes tightly coupled to adapter logic.

✅ **Solution**: Hide this logic in a **factory** or **service layer** so the client deals only with high-level abstractions like `PaymentGateway`.

