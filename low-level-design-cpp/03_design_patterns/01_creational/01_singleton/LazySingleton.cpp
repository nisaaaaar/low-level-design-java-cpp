class LazySingleton {
private:
    static LazySingleton* instance;
    LazySingleton() {}

public:
    LazySingleton(const LazySingleton&) = delete;
    LazySingleton& operator=(const LazySingleton&) = delete;

    static LazySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        return instance;
    }
};

LazySingleton* LazySingleton::instance = nullptr;