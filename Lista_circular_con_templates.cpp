#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
    T dato;
    Node<T>* next;

    Node(T dato) {
        this->dato = dato;
        next = nullptr;
    }
};

template <typename T>
class ListaCircular {
private:
    Node<T>* head;
    Node<T>* tail;
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

    void push_front(const T& valor) {
        Node<T>* nuevo = new Node<T>(valor);

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

    void push_back(const T& valor) {
        Node<T>* nuevo = new Node<T>(valor);

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
            Node<T>* aux = head;
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
            Node<T>* actual = head;

            while(actual->next != tail) {
                actual = actual->next;
            }

            actual->next = head;
            delete tail;
            tail = actual;
        }

        tam--;
    }

    bool contains(const T& valor) const {
        if(head == nullptr) {
            return false;
        }

        Node<T>* actual = head;

        do {
            if(actual->dato == valor) {
                return true;
            }

            actual = actual->next;
        } while(actual != head);

        return false;
    }

    void erase(Node<T>* actual) {
        if(actual == nullptr || head == nullptr) {
            return;
        }

        if(head == tail) {
            if(actual == head) {
                delete actual;
                head = nullptr;
                tail = nullptr;
                tam--;
            }

            return;
        }

        if(actual == head) {
            pop_front();
            return;
        }

        Node<T>* anterior = head;

        while(anterior->next != actual) {
            anterior = anterior->next;
        }

        anterior->next = actual->next;

        if(actual == tail) {
            tail = anterior;
        }

        delete actual;
        tam--;
    }

    void erase_with_anterior(Node<T>* anterior) {
        if(anterior == nullptr || head == nullptr) {
            return;
        }

        Node<T>* actual = anterior->next;

        if(actual == head && actual == tail) {
            delete actual;
            head = nullptr;
            tail = nullptr;
            tam--;
            return;
        }

        anterior->next = actual->next;

        if(actual == head) {
            head = actual->next;
        }

        if(actual == tail) {
            tail = anterior;
        }

        delete actual;
        tam--;
    }

    void print() const {
        if(head == nullptr) {
            return;
        }

        Node<T>* actual = head;

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
    ios::sync_with_stdio(false);
    cin.tie(0);

    ListaCircular<int> lista;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    lista.print();

    lista.push_front(5);
    lista.print();

    cout << lista.front() << "\n";
    cout << lista.back() << "\n";
    cout << lista.size() << "\n";
    cout << lista.empty() << "\n";

    lista.pop_front();
    lista.print();

    lista.pop_back();
    lista.print();

    cout << lista.contains(20) << "\n";
    cout << lista.contains(100) << "\n";

    Node<int>* nodo = lista.gethead();

    lista.erase(nodo);
    lista.print();

    ListaCircular<string> nombres;

    nombres.push_back("Fabian");
    nombres.push_back("Juan");
    nombres.push_front("Pedro");

    nombres.print();

    cout << nombres.front() << "\n";
    cout << nombres.back() << "\n";

    nombres.pop_front();
    nombres.print();

    nombres.pop_back();
    nombres.print();

    nombres.clear();

    cout << nombres.empty() << "\n";

    return 0;
}