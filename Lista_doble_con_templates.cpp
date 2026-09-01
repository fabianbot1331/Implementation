#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
    T dato;
    Node<T>* prev;
    Node<T>* next;

    Node(T dato) {
        this->dato = dato;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class Lista {
private:
    Node<T>* head;
    Node<T>* tail;
    int tam;

public:
    Lista() {
        head = nullptr;
        tail = nullptr;
        tam = 0;
    }

    ~Lista() {
        clear();
    }

    int size() const {
        return tam;
    }

    bool empty() const {
        return tam == 0;
    }

    Node<T>* gethead() const {
        return head;
    }

    Node<T>* gettail() const {
        return tail;
    }

    T& front() {
        return head->dato;
    }

    T& back() {
        return tail->dato;
    }

    const T& front() const {
        return head->dato;
    }

    const T& back() const {
        return tail->dato;
    }

    void push_front(const T& valor) {
        Node<T>* nuevo = new Node<T>(valor);

        if(head == nullptr) {
            head = nuevo;
            tail = nuevo;
        }
        else {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }

        tam++;
    }

    void push_back(const T& valor) {
        Node<T>* nuevo = new Node<T>(valor);

        if(tail == nullptr) {
            head = nuevo;
            tail = nuevo;
        }
        else {
            nuevo->prev = tail;
            tail->next = nuevo;
            tail = nuevo;
        }

        tam++;
    }

    void pop_front() {
        if(head == nullptr) {
            return;
        }

        Node<T>* aux = head;

        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete aux;
        tam--;
    }

    void pop_back() {
        if(tail == nullptr) {
            return;
        }

        Node<T>* aux = tail;

        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete aux;
        tam--;
    }

    bool contains(const T& valor) const {
        Node<T>* actual = head;

        while(actual != nullptr) {
            if(actual->dato == valor) {
                return true;
            }

            actual = actual->next;
        }

        return false;
    }

    void erase(Node<T>* actual) {
        if(actual == nullptr) {
            return;
        }

        if(actual == head) {
            pop_front();
            return;
        }

        if(actual == tail) {
            pop_back();
            return;
        }

        actual->prev->next = actual->next;
        actual->next->prev = actual->prev;

        delete actual;
        tam--;
    }

    void erase(int x) {
        if(x < 0 || x >= tam) {
            return;
        }

        Node<T>* actual = head;

        for(int i = 0; i < x; i++) {
            actual = actual->next;
        }

        erase(actual);
    }

    void clear() {
        while(head != nullptr) {
            pop_front();
        }
    }

    void print() const {
        Node<T>* actual = head;

        while(actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->next;
        }

        cout << endl;
    }

    void print_reverse() const {
        Node<T>* actual = tail;

        while(actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->prev;
        }

        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Lista<int> lista;
    Node<int>* now = lista.gethead();

    lista.push_back(10);
    lista.push_back(20);
    lista.push_front(5);

    lista.print();

    cout << lista.front() << endl;
    cout << lista.back() << endl;
    cout << lista.size() << endl;

    lista.pop_front();
    lista.pop_back();

    lista.print();

    cout << lista.contains(10) << endl;

    Lista<string> nombres;

    nombres.push_back("Fabian");
    nombres.push_back("Juan");
    nombres.push_front("Pedro");

    nombres.print();

    nombres.pop_back();

    nombres.print();

    return 0;
}