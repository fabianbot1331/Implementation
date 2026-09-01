#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int size) {
        this->size = size;
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    int getSize() {
        return size;
    }

    int get(int index) {
        return data[index];
    }

    void set(int index, int value) {
        data[index] = value;
    }

    int& operator[](int index) {
        return data[index];
    }

    void fill(int value) {
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - 1 - i]);
        }
    }
};

int main() {
    Array a(5);

    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    a.set(3, 40);
    a.set(4, 50);

    cout << a.get(2) << endl;

    a[2] = 100;

    a.print();

    a.reverse();

    a.print();

    return 0;
}