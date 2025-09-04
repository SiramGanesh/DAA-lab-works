#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int BUCKET;
    list<int>* table;

public:
    HashTable(int V) {
        BUCKET = V;
        table = new list<int>[BUCKET];
    }

    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool searchItem(int key) {
        int index = hashFunction(key);
        for (auto x : table[index]) {
            if (x == key)
                return true;
        }
        return false;
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    int choice, key, n;
    cout << "Enter number of buckets in hash table: ";
    cin >> n;
    HashTable h(n);

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            h.insertItem(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (h.searchItem(key))
                cout << "Key found!\n";
            else
                cout << "Key not found!\n";
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            h.deleteItem(key);
            break;
        case 4:
            h.displayHash();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
