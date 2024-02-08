#include <iostream>
#include <vector>
#include <algorithm>

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

// Forward declaration of the Observer interface
class Observer;

// Subject interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Concrete Subject class
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int state;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    void setState(int newState) {
        state = newState;
        notify();
    }

    int getState() const {
        return state;
    }
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    ConcreteSubject* subject;

public:
    ConcreteObserver(ConcreteSubject* subj) : subject(subj) {
        subject->attach(this);
    }

    ~ConcreteObserver() {
        subject->detach(this);
    }

    void update() override {
        std::cout << "Observer received update. New state: " << subject->getState() << std::endl;
    }
};


void exampleObserver() {
    ConcreteSubject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);

    subject.setState(10);
    subject.setState(20);

}

// Abstract Product A
class AbstractProductA {
public:
    virtual void use() = 0;
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA1\n";
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA2\n";
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void consume() = 0;
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void consume() override {
        std::cout << "Consuming ConcreteProductB1\n";
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void consume() override {
        std::cout << "Consuming ConcreteProductB2\n";
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

void exampleAbstractFactory() {

    // Create a factory object (choose the type of factory you need)
    AbstractFactory* factory = new ConcreteFactory1(); // Or ConcreteFactory2

    // Create products using the factory
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    // Use or consume the products
    productA->use();
    productB->consume();

    // Clean up
    delete productA;
    delete productB;
    delete factory;

}

int main() {
    exampleSingleTon();
    exampleObserver();
    exampleAbstractFactory();
    return 0;
}
