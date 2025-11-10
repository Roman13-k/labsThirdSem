#include <iostream>
using namespace std;

class Product {
protected:
    int productID;
    double price;
public:
    Product(int id = 0, double pr = 0.0) : productID(id), price(pr) {}
    virtual ~Product() {};
};

class Item : public Product {
private:
    static int itemsCount;
    int* tags;             
    int tagCount;          

public:
    Item(int id = 0, double pr = 0.0) : Product(id, pr), tags(nullptr), tagCount(0) {
        itemsCount++;
    }

    Item(const Item& other)
        : Product(other.productID, other.price),
        tagCount(other.tagCount)
    {
        if (other.tags) {
            tags = new int[tagCount];
            for (int i = 0; i < tagCount; ++i)
                tags[i] = other.tags[i];
        }
        else {
            tags = nullptr;
        }
        itemsCount++;
    }

    void addTags(int* newTags, int count) {
        delete[] tags;
        tagCount = count;
        tags = new int[tagCount];
        for (int i = 0; i < tagCount; ++i)
            tags[i] = newTags[i];
    }

    void displayAllTags() const {
        cout << "Теги товара (ID: " << productID << "): ";
        for (int i = 0; i < tagCount; ++i)
            cout << tags[i] << " ";
        cout << endl;
    }

    static int getItemsCount() {
        return itemsCount;
    }

    ~Item() override {
        delete[] tags;
        itemsCount--;
    }
};

int Item::itemsCount = 0;

int main() {
    setlocale(LC_ALL, "Russian");

    Item item1(101, 25.5);
    int tags1[] = { 1, 2, 3 };
    item1.addTags(tags1, 3);

    Item item2(102, 40.0);
    int tags2[] = { 10, 20 };
    item2.addTags(tags2, 2);
    item1.displayAllTags();
    item2.displayAllTags();

    Item item3 = item1;
    /*
    проблема: item2=item1;
    не копирование, а присваивание, будут указывать на один и тот же объект
    для исправления нужен operator
    */

    cout << "Всего объектов Item: " << Item::getItemsCount() << endl;

    return 0;
}
