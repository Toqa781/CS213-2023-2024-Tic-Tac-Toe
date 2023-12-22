// File: A3_SheetPb04_20220051.cpp
//author: Adham Salah Ezzat
//ID: 20220051
//section:S7
//Date:9/12/2023

#include <iostream>
using namespace std;
template <typename T>
class Set {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    Set() : head(nullptr), size(0) {}

    ~Set() {
        clear();
    }

    void add(const T& item) {
        if (!contains(item)) {
            Node* newNode = new Node(item);
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    void remove(const T& item) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data == item) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }

                delete current;
                size--;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    int getSize() const {
        return size;
    }

    bool contains(const T& item) const { //function checks if a given item is present in the set
        Node* current = head;

        while (current != nullptr) {
            if (current->data == item) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    T* toArray() const { // function returns a dynamically created array containing all items in the set
        T* array = new T[size];
        Node* current = head;

        for (int i = 0; i < size; i++) {
            array[i] = current->data;
            current = current->next;
        }

        return array;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }
};

int main() {
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);
    intSet.add(2); // Should not add, as 2 is already in the set

    cout << "Size of intSet: " << intSet.getSize() << endl;

    intSet.remove(2);

    cout << "Size of intSet after removing 2: " << intSet.getSize() << endl;

    if (intSet.contains(1)) {
        cout << "intSet contains 1." << endl;
    }

    int* intArray = intSet.toArray();
    cout << "Contents of intSet: ";
    for (int i = 0; i < intSet.getSize(); i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    delete[] intArray; //   deallocate the memory

    Set<string> stringSet;
    stringSet.add("apple");
    stringSet.add("banana");
    stringSet.add("orange");

    cout << "Size of stringSet: " << stringSet.getSize() << endl;



    return 0;
}
