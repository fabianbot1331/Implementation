#include <bits/stdc++.h>
using namespace std;

class Lista {
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
    int tam;

public:
    Lista() {
        head = nullptr;
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

    void push_front(int valor) {
        Node* nuevo = new Node(valor);

        nuevo->next = head;
        head = nuevo;

        tam++;
    }

    void push_back(int valor) {
        Node* nuevo = new Node(valor);

        if(head == nullptr) {
            head = nuevo;
        }
        else {
            Node* actual = head;

            while(actual->next != nullptr) {
                actual = actual->next;
            }

            actual->next = nuevo;
        }

        tam++;
    }

    void pop_front() {
        if(head == nullptr) {
            return;
        }

        Node* aux = head;
        head = head->next;

        delete aux;
        tam--;
    }

    void pop_back() {
        if(head == nullptr) {
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* actual = head;

            while(actual->next->next != nullptr) {
                actual = actual->next;
            }

            delete actual->next;
            actual->next = nullptr;
        }

        tam--;
    }

    void clear() {
        while(head != nullptr) {
            pop_front();
        }
    }

    bool contains(int valor) const {
        Node* actual = head;

        while(actual != nullptr) {
            if(actual->dato == valor) {
                return true;
            }

            actual = actual->next;
        }

        return false;
    }

    void print() const {
        Node* actual = head;

        while(actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->next;
        }

        cout << endl;
    }
};

int main() {
    Lista lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    lista.push_front(5);

    lista.print();

    lista.pop_front();
    lista.pop_back();

    lista.print();

    cout << lista.contains(20) << endl;
    cout << lista.size() << endl;

    return 0;
}