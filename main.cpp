#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds\n";
            return;
        }

        if (size == capacity) {
            resize(capacity * 2);
        }

        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    void delete_at(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return;
        }

        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        size--;

        if (size <= capacity / 4 && capacity > 2) {
            resize(max(capacity / 2, 2));
        }
    }

    void pop_back() {
        if (size == 0) {
            cout << "Array is already empty\n";
            return;
        }

        size--;

        if (size <= capacity / 4 && capacity > 2) {
            resize(max(capacity / 2, 2));
        }
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return -1;
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            cout << arr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]\n";
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.print();

    arr.insert(1, 15);
    arr.print();

    arr.delete_at(2);
    arr.print();

    arr.pop_back();
    arr.print();

    cout << "Value at index 1: " << arr.get(1) << endl;
    cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;

    return 0;
}
