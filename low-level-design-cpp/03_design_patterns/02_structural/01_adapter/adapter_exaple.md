## 🧩 **Adapter Design Pattern in C++ (with Factory Integration)**

---

### ✅ **Definition**

The **Adapter Pattern** allows you to **adapt** an existing class to a new interface. It helps incompatible types work together by wrapping one of the types in an adapter class.

---

## 🎯 Scenario

You have an e-commerce app that expects a `PaymentGateway` interface. Your new partner uses PayPal, which doesn't follow that interface. You use an **Adapter** to make it compatible and wrap this logic inside a **Factory**.

---

## 🧱 Implementation in C++

---

### 🔹 1. Target Interface (`PaymentGateway`)

```cpp
#include <iostream>
#include <memory>
#include <string>

class PaymentGateway {
public:
    virtual void pay(const std::string& amount) const = 0;
    virtual ~PaymentGateway() = default;
};
```

---

### 🔹 2. Adaptee (`PayPalGateway`)

```cpp
class PayPalGateway {
public:
    void makePayment(const std::string& amountInDollars) const {
        std::cout << "Payment done via PayPal: $" << amountInDollars << std::endl;
    }
};
```

---

### 🔹 3. Adapter (`PayPalAdapter`)

```cpp
class PayPalAdapter : public PaymentGateway {
private:
    std::unique_ptr<PayPalGateway> payPalGateway;

public:
    PayPalAdapter() {
        payPalGateway = std::make_unique<PayPalGateway>();
    }

    void pay(const std::string& amount) const override {
        payPalGateway->makePayment(amount);
    }
};
```

---

### 🔹 4. Concrete Implementation (`CreditCardPaymentGateway`)

```cpp
class CreditCardPaymentGateway : public PaymentGateway {
public:
    void pay(const std::string& amount) const override {
        std::cout << "Payment done via Credit Card: $" << amount << std::endl;
    }
};
```

---

### 🔹 5. Enum to Choose Payment Type

```cpp
enum class PaymentType {
    CREDIT_CARD,
    PAYPAL
};
```

---

### 🔹 6. Factory to Hide Adapter Details

```cpp
class PaymentGatewayFactory {
public:
    static std::unique_ptr<PaymentGateway> getPaymentGateway(PaymentType type) {
        switch (type) {
            case PaymentType::CREDIT_CARD:
                return std::make_unique<CreditCardPaymentGateway>();
            case PaymentType::PAYPAL:
                return std::make_unique<PayPalAdapter>();
            default:
                return nullptr;
        }
    }
};
```

---

### 🔹 7. Client Code (`main()`)

```cpp
int main() {
    auto creditCard = PaymentGatewayFactory::getPaymentGateway(PaymentType::CREDIT_CARD);
    creditCard->pay("100");

    auto paypal = PaymentGatewayFactory::getPaymentGateway(PaymentType::PAYPAL);
    paypal->pay("250");

    return 0;
}
```

---

### ✅ Output

```
Payment done via Credit Card: $100
Payment done via PayPal: $250
```

---

## ✅ Benefits

| Benefit                      | Explanation                                   |
| ---------------------------- | --------------------------------------------- |
| Interface compatibility      | You don’t change PayPal SDK to fit your code. |
| Clean separation             | Adapter handles translation logic.            |
| Client is unaware of changes | Uses abstraction and factory.                 |
| Open/Closed Principle        | You can add new payment types easily.         |

---

## 🧠 When to Use Adapter Pattern

* To reuse legacy or third-party code with a different interface
* To keep **existing client logic untouched**
* When integrating systems with **mismatched contracts**

---

## ✅ SOLID Principle Support

| Principle | Applied? | Why?                                             |
| --------- | -------- | ------------------------------------------------ |
| SRP       | ✅        | Adapter handles conversion logic only            |
| OCP       | ✅        | Can extend new adapters without changing client  |
| LSP       | ✅        | All `PaymentGateway` objects are interchangeable |
| ISP       | ✅        | `PaymentGateway` has minimal interface           |
| DIP       | ✅        | Client depends on abstraction via factory        |

