#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int grade;
};

void addStudToFile(Student&stud) {
    ofstream outFile("students.bin", ios::binary | ios::app);
    if (!outFile) {
        cout << "Ошибка открытия файла для записи"<<endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&stud), sizeof(Student));
}

void printAllStudents() {
    ifstream inFile("students.bin", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия для чтения." << endl;
        return;
    }

    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        cout << "Имя: " << temp.name << ", Оценка: " << temp.grade << endl;
    }
}

Student findStudByName(const char name[]) {
    ifstream inFile("students.bin", ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия для чтения." << endl;
        return {};
    }

    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        if (strcmp(temp.name, name) == 0) {
            return temp;
        }
    }
    cout << "Студент с именем '" << name << "' не найден" << endl;
    return {};
}

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream outFile("students.bin", ios::binary);
    if (!outFile) {
        cout << "Ошибка создания файла";
        return 1;
    }
    outFile.close();

    Student stud1 = {"Roma1",9};
    Student stud2 = { "Roma2", 7 };
    Student stud3 = { "Roma3", 10 }; 
    addStudToFile(stud1);
    addStudToFile(stud2);
    addStudToFile(stud3);

    cout << "Все студенты:" << endl;
    printAllStudents();

    Student studFind = findStudByName("Roma2");
    cout << "Найденный студент: " << endl;
    cout << "Имя: " << studFind.name << ", Оценка: " << studFind.grade << endl;
    return 0;
}
