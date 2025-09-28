#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 
#include <typeinfo>

using namespace std;

// Base class
class Animal {
protected:
    string name;
    int age;

public:
    Animal(const string& name, int age) : name(name), age(age) {
        if (age < 0) throw invalid_argument("Age cannot be negative.");
    }

    virtual void makeSound() const {
        cout << "Animal sound!" << endl;
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Animal() {} // Virtual destructor
};

// Derived class Dog
class Dog : public Animal {
private:
    string breed;

public:
    Dog(const string& name, int age, const string& breed)
        : Animal(name, age), breed(breed) {
    }

    void makeSound() const override {
        cout << "Bark!" <<  endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Breed: " << breed << endl;
    }
};

// Derived class Cat
class Cat : public Animal {
private:
    string color;

public:
    Cat(const string& name, int age, const string& color)
        : Animal(name, age), color(color) {
    }

    void makeSound() const override {
        cout << "Meow!" << endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Color: " << color << endl;
    }
};

// Derived class Bird
class Bird : public Animal {
private:
    string species;

public:
    Bird(const string& name, int age, const string& species)
        : Animal(name, age), species(species) {
    }

    void makeSound() const override {
        cout << "Chirp!" << endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Species: " << species << endl;
    }
};

// Zoo class
class Zoo {
private:
    vector<Animal*> animals;

public:
    ~Zoo() {
        for (Animal* animal : animals) {
            delete animal;
        }
    }

    void addAnimal(Animal*animal) {
        animals.push_back(animal);
    }

    void makeSoundAllAnimals() const {
        for (Animal* animal : animals) {
            animal->makeSound();
        }
    }

    void displayInfoAllAnimals() const {
        for (Animal* animal : animals) {
            animal->displayInfo();
        }
    }

    int getAnimalsCount() const {
        return animals.size();
    }

    void getTypesOfAnimals() {
        for (Animal* animal : animals) {
            cout << typeid(*animal).name() << endl;
        }
    }
};

int main() {
    Zoo zoo;
    
    try {
        zoo.addAnimal(new Dog("Buddy", 3, "Golden Retriever"));
        zoo.addAnimal(new Cat("Whiskers", 2, "Black"));
        zoo.addAnimal(new Bird("Tweety", 1, "Canary"));

        cout << "Animals in the zoo:" << endl;
        zoo.displayInfoAllAnimals();

        cout << "Animal sounds:" << endl;
        zoo.makeSoundAllAnimals();

        cout << "Count of animals: "<< zoo.getAnimalsCount()<<endl;
        

        cout << "Types of Animals: "<<endl;
        zoo.getTypesOfAnimals();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}