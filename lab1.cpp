#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    int age;
    string name;
public:
    Animal(int age, const string& name) : age(age), name(name) {}

    virtual void makeSound() const {
        cout << "Animal sound" << endl;
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << " Age: " << age << endl;
    }

    virtual ~Animal() {
        cout << "Animal delete" << endl;
    };
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(int age, const string& name, const string& breed)
        : Animal(age, name), breed(breed) {
    }

    void makeSound() const override {
        cout << "Bark!" << endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Breed: " << breed << endl;
    }
};

class Cat : public Animal {
private:
    string color;

public:
    Cat(int age, const string& name, const string& color)
        : Animal(age, name), color(color) {
    }

    void makeSound() const override {
        cout << "Meow!" << endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Color: " << color << endl;
    }
};

class Bird : public Animal {
private:
    bool canFly;

public:
    Bird(int age, const string& name, bool canFly)
        : Animal(age, name), canFly(canFly) {
    }

    void makeSound() const override {
        cout << "Chik Chirik!" << endl;
    }

    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Can fly: " << (canFly ? "Yes" : "No") << endl;
    }
};

int main() {
	Animal* animals[] = {
	new Dog(5, "Labrador","Golden Retriever"),
	new Cat(2,"Whiskers","black"),
	new Bird(3,"Tweety",false)
	};
\
	for (Animal* animal : animals) {
		animal->displayInfo();
		animal->makeSound();
		std::cout << "----------------------" << std::endl;
	}

for (Animal* animal : animals) {
    delete animal;
}

return 0;
}