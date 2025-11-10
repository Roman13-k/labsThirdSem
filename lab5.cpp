#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U>
class Pair {
private:
    T first;
    U second;
public:
    Pair(T a, U b) : first(a), second(b) {}

    T getFirst() const { return first; }
    U getSecond() const { return second; }

    void setFirst(T newFirst) { first = newFirst; }
    void setSecond(U newSecond) { second = newSecond; }

    void printPair() const {
        cout << "First: " << first << ", Second: " << second;
    }
};

template<typename T, typename U>
bool isEqual(const Pair<T, U>& p1, const Pair<T, U>& p2) {
    return (p1.getFirst() == p2.getFirst() && p1.getSecond() == p2.getSecond());
}

int main() {
    Pair<int, double> pair1(1, 24.4);
    Pair<int, double> pair2(1, 24.4);
    Pair<int, double> pair3(2, 30.5);

    Pair<double, const char*> pair4(3.5, "Hello");
    Pair<double, const char*> pair5(3.5, "World");

    cout << "pair1: "; pair1.printPair(); cout << endl;
    cout << "pair2: "; pair2.printPair(); cout << endl;
    cout << "pair3: "; pair3.printPair(); cout << endl;
    cout << "pair4: "; pair4.printPair(); cout << endl;
    cout << "pair5: "; pair5.printPair(); cout << endl << endl;

    cout << boolalpha;
    cout << "pair1 == pair2? " << isEqual(pair1, pair2) << endl;
    cout << "pair1 == pair3? " << isEqual(pair1, pair3) << endl;
    cout << "pair4 == pair5? " << isEqual(pair4, pair5) << endl;

    return 0;
}
