#include <bits/stdc++.h>
using namespace std;

class ListaCircular {
private:
    struct Node {
        int dato;
        Node* next;

        Node(int dato) {
            this->dato = dato;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int tam;

public:
    ListaCircular() {
        head = nullptr;
        tail = nullptr;
        tam = 0;
    }

    ~ListaCircular() {
        clear();
    }

    int size() const {
        return tam;
    }

    bool empty() const {
        return tam == 0;
    }

    void push_front(int valor) {
        Node* nuevo = new Node(valor);

        if(head == nullptr) {
            head = nuevo;
            tail = nuevo;
            tail->next = head;
        }
        else {
            nuevo->next = head;
            head = nuevo;
            tail->next = head;
        }

        tam++;
    }

    void push_back(int valor) {
        Node* nuevo = new Node(valor);

        if(head == nullptr) {
            head = nuevo;
            tail = nuevo;
            tail->next = head;
        }
        else {
            nuevo->next = head;
            tail->next = nuevo;
            tail = nuevo;
        }

        tam++;
    }

    void pop_front() {
        if(head == nullptr) {
            return;
        }

        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* aux = head;
            head = head->next;
            tail->next = head;
            delete aux;
        }

        tam--;
    }

    void pop_back() {
        if(head == nullptr) {
            return;
        }

        if(head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* actual = head;

            while(actual->next != tail) {
                actual = actual->next;
            }

            actual->next = head;
            delete tail;
            tail = actual;
        }

        tam--;
    }

    bool contains(int valor) const {
        if(head == nullptr) {
            return false;
        }

        Node* actual = head;

        do {
            if(actual->dato == valor) {
                return true;
            }

            actual = actual->next;
        } while(actual != head);

        return false;
    }

    void print() const {
        if(head == nullptr) {
            return;
        }

        Node* actual = head;

        do {
            cout << actual->dato << " ";
            actual = actual->next;
        } while(actual != head);

        cout << endl;
    }

    void clear() {
        while(head != nullptr) {
            pop_front();
        }
    }
};

int main() {
    ListaCircular lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_front(5);

    lista.print();

    lista.pop_front();
    lista.pop_back();

    lista.print();

    return 0;
}