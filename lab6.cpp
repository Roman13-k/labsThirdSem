#include <iostream>
#include <deque>
#include <string>
using namespace std;

void reverseDeque(deque<string>& dq) {
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        reverse(rit->begin(), rit->end()); 
    }
}

string getStringFromEnd(const deque<string>& dq, int indexFromEnd) {
    if (indexFromEnd >= 0 && indexFromEnd < dq.size()) {
        auto rit = dq.rbegin() + indexFromEnd;
        return *rit;
    }
    return "";
}

void moveFirstToLast(deque<string>& dq) {
    if (dq.size() > 1) {
        auto first = dq.begin();      
        string temp = *first;            

        for (auto it = dq.begin(); it != dq.end() - 1; ++it) {
            *it = *(it + 1);             
        }
        *(dq.end() - 1) = temp;          
    }
}

void displayDeque(deque<string>& dq) {
    for (const auto& w : dq) {
        cout << w << " ";
    }
    cout << endl << endl;
}

void reverseDisplay(deque<string>& dq) {
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    deque<string> words = { "apple", "banana", "cherry", "date" };
    cout << "Содержимое в прямом порядке" << endl;
    displayDeque(words);

    cout << "Содержимое в обратном порядке:" << endl;
    reverseDisplay(words);

    int indexFromEnd = 2;
    string selected = getStringFromEnd(words, indexFromEnd);
    if (!selected.empty())
        cout << "Строка с индексом " << indexFromEnd << " с конца: " << selected << endl << endl;

    moveFirstToLast(words);
    cout << "После перемещения первого элемента в конец:" << endl;
    displayDeque(words);

    reverseDeque(words);
    cout << "После переворота строк:" << endl;
    displayDeque(words);
    return 0;
}
