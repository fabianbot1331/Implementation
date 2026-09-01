#include <bits/stdc++.h>
using namespace std;

class ListaArray {
private:
    int* datos;
    int* next;
    int capacidad;
    int head;
    int libre;
    int tam;

public:
    ListaArray(int capacidad_) {
        capacidad = capacidad_;
        datos = new int[capacidad];
        next = new int[capacidad];

        head = -1;
        tam = 0;

        libre = 0;

        for(int i = 0; i < capacidad - 1; i++) {
            next[i] = i + 1;
        }

        next[capacidad - 1] = -1;
    }

    ~ListaArray() {
        delete[] datos;
        delete[] next;
    }

    int size() const {
        return tam;
    }

    bool empty() const {
        return tam == 0;
    }

    void push_front(int valor) {
        if(libre == -1) {
            return;
        }

        int nuevo = libre;
        libre = next[libre];

        datos[nuevo] = valor;
        next[nuevo] = head;
        head = nuevo;

        tam++;
    }

    void push_back(int valor) {
        if(libre == -1) {
            return;
        }

        int nuevo = libre;
        libre = next[libre];

        datos[nuevo] = valor;
        next[nuevo] = -1;

        if(head == -1) {
            head = nuevo;
        }
        else {
            int actual = head;

            while(next[actual] != -1) {
                actual = next[actual];
            }

            next[actual] = nuevo;
        }

        tam++;
    }

    void pop_front() {
        if(head == -1) {
            return;
        }

        int aux = head;
        head = next[head];

        next[aux] = libre;
        libre = aux;

        tam--;
    }

    bool contains(int valor) const {
        int actual = head;

        while(actual != -1) {
            if(datos[actual] == valor) {
                return true;
            }

            actual = next[actual];
        }

        return false;
    }

    void print() const {
        int actual = head;

        while(actual != -1) {
            cout << datos[actual] << " ";
            actual = next[actual];
        }

        cout << endl;
    }
};

int main() {
    ListaArray lista(10);

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    lista.push_front(5);

    lista.print();

    lista.pop_front();

    lista.print();

    cout << lista.contains(20) << endl;

    return 0;
}