#include <mutex>

class DCLSingleton {
private:
    static DCLSingleton* instance;
    static std::mutex mtx;
    DCLSingleton() {}

public:
    DCLSingleton(const DCLSingleton&) = delete;
    DCLSingleton& operator=(const DCLSingleton&) = delete;

    static DCLSingleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new DCLSingleton();
            }
        }
        return instance;
    }
};

DCLSingleton* DCLSingleton::instance = nullptr;
std::mutex DCLSingleton::mtx;