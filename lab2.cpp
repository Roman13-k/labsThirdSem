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

void addNewAnimal(vector<Animal>& animals) {
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
}

void displayAllAnimals(const vector<Animal>& animals) {
    for (const Animal& a : animals) {
        cout << "ID: " << a.id << ", Type: " << a.type << ", Breeds: ";
        for (const auto& b : a.breed) cout << b << " ";
        cout << endl;
    }
}

void displayBreedsOfAnimal(const Animal& animal) {
    if (animal.breed.empty()) {
        cout << "No breeds";
    }
    else {
        for (const string& b : animal.breed) {
            cout << b << " ";
        }
    }
    cout << endl;
}

void findAnimalByBreed(const vector<Animal>& animals, const string& breedName) {
    bool found = false;

    for (const Animal& animal : animals) {
        for (string breed : animal.breed) {
            if (breed == breedName) {
                cout << "Found animal: ID=" << animal.id << ", Type=" << animal.type << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "No animal found with breed: " << breedName << endl;
    }
}

void findAnimalById(const map<int, Animal>& animalMap, int id) {
    auto it = animalMap.find(id);
    if (it != animalMap.end()) {
        cout << "Animal found: ID=" << it->second.id << ", Type=" << it->second.type << endl;
        displayBreedsOfAnimal(it->second);
    }
    else {
        cout << "No animal found with ID: " << id << endl;
    }
}

void addBreedToAnimal(map<int, Animal>& animalMap, int id, const string& newBreed) {
    auto it = animalMap.find(id);
    if (it != animalMap.end()) {
        it->second.breed.push_back(newBreed);
        cout << "Breed '" << newBreed << "' added to animal ID " << id << endl;
    }
    else {
        cout << "No animal with ID " << id << " found!" << endl;
    }
}

int main() {
    vector<Animal> animals = {
      {1, "Dog", {"Labrador", "Retriever"}},
      {2, "Cat", {"Siamese"}},
      {3, "Bird", {"Parrot"}}
    };
    addNewAnimal(animals);
    addNewAnimal(animals);
    displayAllAnimals(animals);

    Animal& animalToDisplayBreeds= animals.front();
    cout << "Display all breeds for aimal type: " << animalToDisplayBreeds.type<<endl;
    displayBreedsOfAnimal(animalToDisplayBreeds);

    string breedToFind = "Labrador";
    cout << "Searching for animal of breed: " << breedToFind << endl;
    findAnimalByBreed(animals, breedToFind);

    map<int, Animal> animalMap;
    for (const auto& a : animals) {
        animalMap[a.id] = a;
    }
    cout << "Searching by ID=2:"<<endl;
    findAnimalById(animalMap, 2);

    cout << "Adding new breed to ID=1:"<<endl;
    addBreedToAnimal(animalMap, 1, "Bulldog");
    findAnimalById(animalMap, 1);

	return 0;
}