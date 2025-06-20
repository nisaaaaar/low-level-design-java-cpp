class MeyersSingleton {
private:
    MeyersSingleton() {}

public:
    MeyersSingleton(const MeyersSingleton&) = delete;
    MeyersSingleton& operator=(const MeyersSingleton&) = delete;

    static MeyersSingleton& getInstance() {
        static MeyersSingleton instance;
        return instance;
    }
};