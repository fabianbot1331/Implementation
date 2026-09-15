#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
private:
    T* datos;
    int capacidad;
    int tam;
    int inicio;

    void resize() {
        int nuevaCapacidad;

        if(capacidad == 0)
            nuevaCapacidad = 1;
        else
            nuevaCapacidad = capacidad * 2;

        T* nuevos = new T[nuevaCapacidad];

        for(int i = 0; i < tam; i++) {
            nuevos[i] = datos[(inicio + i) % capacidad];
        }

        delete[] datos;

        datos = nuevos;
        capacidad = nuevaCapacidad;
        inicio = 0;
    }

public:
    Queue() {
        datos = nullptr;
        capacidad = 0;
        tam = 0;
        inicio = 0;
    }
    Queue(const Queue<T>& otra) {
        capacidad = otra.capacidad;
        tam = otra.tam;
        inicio = 0;

        if(capacidad == 0) {
            datos = nullptr;
        }
        else {
            datos = new T[capacidad];

            for(int i = 0; i < tam; i++) {
                datos[i] = otra.datos[(otra.inicio + i) % otra.capacidad];
            }
        }
    }
    Queue(Queue<T>&& otra) {
        datos = otra.datos;
        capacidad = otra.capacidad;
        tam = otra.tam;
        inicio = otra.inicio;

        otra.datos = nullptr;
        otra.capacidad = 0;
        otra.tam = 0;
        otra.inicio = 0;
    }
    ~Queue() {
        delete[] datos;
    }
    Queue<T>& operator=(const Queue<T>& otra) {
        if(this == &otra)
            return *this;

        delete[] datos;

        capacidad = otra.capacidad;
        tam = otra.tam;
        inicio = 0;

        if(capacidad == 0) {
            datos = nullptr;
        }
        else {
            datos = new T[capacidad];

            for(int i = 0; i < tam; i++) {
                datos[i] = otra.datos[(otra.inicio + i) % otra.capacidad];
            }
        }

        return *this;
    }
    Queue<T>& operator=(Queue<T>&& otra) {
        if(this == &otra)
            return *this;

        delete[] datos;

        datos = otra.datos;
        capacidad = otra.capacidad;
        tam = otra.tam;
        inicio = otra.inicio;

        otra.datos = nullptr;
        otra.capacidad = 0;
        otra.tam = 0;
        otra.inicio = 0;

        return *this;
    }
    int size() const {
        return tam;
    }

    int capacity() const {
        return capacidad;
    }

    bool empty() const {
        return tam == 0;
    }

    T& front() {
        return datos[inicio];
    }

    const T& front() const {
        return datos[inicio];
    }

    T& back() {
        return datos[(inicio + tam - 1) % capacidad];
    }

    const T& back() const {
        return datos[(inicio + tam - 1) % capacidad];
    }

    void push(const T& valor) {
        if(tam == capacidad)
            resize();

        int posicion = (inicio + tam) % capacidad;

        datos[posicion] = valor;
        tam++;
    }

    void push(T&& valor) {
        if(tam == capacidad)
            resize();

        int posicion = (inicio + tam) % capacidad;

        datos[posicion] = move(valor);
        tam++;
    }

    void pop() {
        if(tam == 0)
            return;

        inicio = (inicio + 1) % capacidad;
        tam--;

        if(tam == 0)
            inicio = 0;
    }

    void clear() {
        tam = 0;
        inicio = 0;
    }

    void swap(Queue<T>& otra) {
        T* tempDatos = datos;
        datos = otra.datos;
        otra.datos = tempDatos;

        int tempCapacidad = capacidad;
        capacidad = otra.capacidad;
        otra.capacidad = tempCapacidad;

        int tempTam = tam;
        tam = otra.tam;
        otra.tam = tempTam;

        int tempInicio = inicio;
        inicio = otra.inicio;
        otra.inicio = tempInicio;
    }
};


int main() {

    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n";
    cout << "Capacity: " << q.capacity() << "\n";
    cout << "Empty: " << q.empty() << "\n";

    q.pop();

    cout << "\nDespues de pop:\n";
    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";


    Queue<int> q2(q);

    cout << "\nCopia:\n";
    cout << q2.front() << "\n";


    Queue<int> q3;

    q3 = q;

    cout << "\nAsignacion:\n";
    cout << q3.front() << "\n";


    Queue<string> nombres;

    nombres.push("Fabian");
    nombres.push("Juan");
    nombres.push("Pedro");

    cout << "\nNombres:\n";
    cout << nombres.front() << "\n";
    cout << nombres.back() << "\n";


    nombres.pop();

    cout << "\nDespues de pop:\n";
    cout << nombres.front() << "\n";


    nombres.clear();

    cout << "\nEmpty despues de clear: ";
    cout << nombres.empty() << "\n";


    return 0;
}