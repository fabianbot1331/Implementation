#include <bits/stdc++.h>
using namespace std;

struct Node {
        int dato;
        Node* prev;
        Node* next;

        Node(int dato) {
            this->dato = dato;
            prev = nullptr;
            next = nullptr;
        }
    };

class Lista {
private:
    Node* head;
    Node* tail;
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

    Node* gethead(){
        return head;
    }
    
    Node* gettail(){
        return tail;
    }
    
    bool empty() const {
        return tam == 0;
    }

    void push_front(int valor) {
        Node* nuevo = new Node(valor);

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

    void push_back(int valor) {
        Node* nuevo = new Node(valor);

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

        Node* aux = head;

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

        Node* aux = tail;

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

    void print_reverse() const {
        Node* actual = tail;

        while(actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->prev;
        }

        cout << endl;
    }
    
    void erase(int x) {
    if(x < 0 || x >= tam) {
        return;
    }

    Node* actual = head;

    for(int i = 0; i < x; i++) {
        actual = actual->next;
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
    
    void erase(Node* actual) {
    if(actual == nullptr) return;

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

    void clear() {
        while(head != nullptr) {
            pop_front();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Lista lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_front(5);

    lista.print();

    lista.print_reverse();

    lista.pop_front();
    lista.pop_back();

    lista.print();

    return 0;
}
