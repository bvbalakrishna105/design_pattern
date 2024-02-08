#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    
    // Private constructor to prevent instantiation
    Singleton() {}

public:
    // Static method to get the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Example method
    void doSomething() {
        std::cout << "Singleton instance is doing something.\n";
    }
};

// Initialize the static instance pointer
Singleton* Singleton::instance = nullptr;

void exampleSingleTon() {
        // Access the singleton instance
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->doSomething();

    // Try to access the instance again
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->doSomething();

    // The addresses should be the same
    std::cout << "Address of singleton1: " << singleton1 << std::endl;
    std::cout << "Address of singleton2: " << singleton2 << std::endl;
}

int main() {
    exampleSingleTon();
    return 0;
}
