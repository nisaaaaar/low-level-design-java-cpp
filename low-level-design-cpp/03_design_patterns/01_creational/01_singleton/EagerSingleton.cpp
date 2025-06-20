class EagerSingleton {
private:
    static EagerSingleton instance;
    EagerSingleton() {}

public:
    EagerSingleton(const EagerSingleton&) = delete;
    EagerSingleton& operator=(const EagerSingleton&) = delete;

    static EagerSingleton& getInstance() {
        return instance;
    }
};

EagerSingleton EagerSingleton::instance; // Static instance