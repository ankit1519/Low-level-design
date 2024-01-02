
#include<bits/stdc++.h>
using namespace std;

// Abstraction (Interface)
class IAnimal {
public:
    virtual void makeSound() = 0;
};

// Low-level module implementing the abstraction
class Dog : public IAnimal {
public:
    void makeSound() override {
        cout << "Dog barks" << std::endl;
    }
};

// Low-level module implementing the abstraction
class Cat : public IAnimal {
public:
    void makeSound() override {
        cout << "Cat meows" << std::endl;
    }
};

// High-level module depending on the abstraction
class AnimalSound {
private:
    IAnimal* animal;

public:
    // Dependency is injected through constructor
    AnimalSound(IAnimal* animal) : animal(animal) {}

    void produceSound() {
        animal->makeSound();
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // Dependency Injection: Creating objects and injecting dependencies
    Dog myDog;
    Cat myCat;

    AnimalSound dogSound(&myDog);
    AnimalSound catSound(&myCat);

    // Using the high-level module
    dogSound.produceSound();
    catSound.produceSound();

    return 0;
}
