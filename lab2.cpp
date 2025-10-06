#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Animal {
	int id;
	string type;
	vector<string> breed; 
};

void addNewAnimal(vector<Animal>& animals, map<int, Animal>& animalsMap) {
    Animal a;

    cout << "Enter animal ID: ";
    cin >> a.id;

    cout << "Enter animal type: ";
    cin >> a.type;

    cout << "How many breeds do you want to enter? ";
    int n;
    cin >> n;

    cout << "Enter " << n << " breed(s):" << endl;
    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        a.breed.push_back(b);
    }

    animals.push_back(a);
    animalsMap[a.id] = a;
    
}

void displayAllAnimals(const vector<Animal>& animals) {
    for (const Animal& a : animals) { 
        cout << "ID: " << a.id << ", Type: " << a.type << ", Breeds: ";
        for (const auto& b : a.breed)  
            cout << b << " ";
        cout << endl;
    }
}

void displayBreedsOfAnimal(const Animal& animal) {
    if (animal.breed.empty()) {
        cout << "No breeds";
    }
    else {
        for (const auto& b : animal.breed) {
            cout << b << " ";
        }
    }
    cout << endl;
}

Animal findAnimalByBreed(const vector<Animal>& animals, const string& breedName) {
    bool found = false;

    for (const Animal& animal : animals) {
        for (string breed : animal.breed) {
            if (breed == breedName) {
                cout << "Found animal: ID=" << animal.id << ", Type=" << animal.type << endl;
                found = true;
                return animal;
            }
        }
    }

    if (!found) {
        cout << "No animal found with breed: " << breedName << endl;
    }
}

Animal findAnimalById(const map<int, Animal>& animalMap, int id) {
    auto it = animalMap.find(id);
    if (it != animalMap.end()) {
        cout << "Animal found: ID=" << it->second.id << ", Type=" << it->second.type << endl;
        return it->second;
    }
    else {
        cout << "No animal found with ID: " << id << endl;
    }
}

void addBreedToAnimal(vector<Animal>& animals,map<int, Animal>& animalMap, int id, const string& newBreed) {
    auto it = animalMap.find(id);
    if (it != animalMap.end()) {
        it->second.breed.push_back(newBreed);
        for (Animal &animal : animals) {
            
            if (animal.id == id) {
                animal.breed.push_back(newBreed);
                cout << "Breed " << newBreed << " added to animal ID " << id << endl;
            }
            else cout << "Not found";
            
        }
        
    }
    else {
        cout << "No animal with ID " << id << " found!" << endl;
    }
}

void menu(vector<Animal>& animals, map<int, Animal>& animalsMap) {
    while (true) {
        int a = 7;
        cout << "---------------------------------" << endl;
        cout << "Pres 1 for add animal" << endl;
        cout << "Pres 2 for dispay all animals" << endl;
        cout << "Pres 3 for diplay all breeds of animal" << endl;
        cout << "Pres 4 for search animal by breed" << endl;
        cout << "Pres 5 for search animal by id" << endl;
        cout << "Pres 6 for add breed to animal" << endl;
        cout << "Pres 7 for quit" << endl;
        cin >> a;

        switch (a) {
        case 1: {
            addNewAnimal(animals, animalsMap);
            break;
        }
        case 2: {
            displayAllAnimals(animals);
            break;
        }
        case 3: {
            cout << "Enter ID" << endl;
            int id;
            cin >> id;
            displayBreedsOfAnimal(findAnimalById(animalsMap, id));
            break;
        }
        case 4: {
            cout << "Enter breed" << endl;
            string breed;
            cin >> breed;
            findAnimalByBreed(animals, breed);
            break;
        }
        case 5: {
            cout << "Enter ID" << endl;
            int id;
            cin >> id;
            findAnimalById(animalsMap, id);
            break;
        }
        case 6: {
            cout << "Enter breed and id" << endl;
            string breed;
            int id;
            cin >> breed>>id;
            addBreedToAnimal(animals,animalsMap, id, breed);
            break;
        }
        case 7: {
            return;
        }
        default: {
            cout << "pres 1-7" << endl;
            break;
        }
        }
    }
}

int main() {
    vector<Animal> animals;
    map<int, Animal> animalMap;
    menu(animals, animalMap);
	return 0;
}