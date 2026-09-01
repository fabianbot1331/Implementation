#include <bits/stdc++.h>
using namespace std;

class String {
private:
    char* datos;
    int tam;
    int capacidad;

public:
    String() {
        tam = 0;
        capacidad = 1;
        datos = new char[capacidad];
        datos[0] = '\0';
    }

    String(const char* texto) {
        tam = strlen(texto);
        capacidad = tam + 1;
        datos = new char[capacidad];

        for(int i = 0; i < tam; i++) {
            datos[i] = texto[i];
        }

        datos[tam] = '\0';
    }

    ~String() {
        delete[] datos;
    }

    int size() const {
        return tam;
    }

    bool empty() const {
        return tam == 0;
    }

    char& operator[](int index) {
        return datos[index];
    }

    const char& operator[](int index) const {
        return datos[index];
    }

    const char* c_str() const {
        return datos;
    }

    void push_back(char c) {
        if(tam + 1 >= capacidad) {
            capacidad *= 2;

            char* ndatos = new char[capacidad];

            for(int i = 0; i < tam; i++) {
                ndatos[i] = datos[i];
            }

            delete[] datos;
            datos = ndatos;
        }

        datos[tam] = c;
        tam++;
        datos[tam] = '\0';
    }

    void pop_back() {
        if(tam > 0) {
            tam--;
            datos[tam] = '\0';
        }
    }

    void clear() {
        tam = 0;
        datos[0] = '\0';
    }

    void reverse() {
        int i = 0;
        int j = tam - 1;

        while(i < j) {
            swap(datos[i], datos[j]);
            i++;
            j--;
        }
    }

    String(const String& other) {
        tam = other.tam;
        capacidad = other.capacidad;
        datos = new char[capacidad];

        for(int i = 0; i <= tam; i++) {
            datos[i] = other.datos[i];
        }
    }

    String& operator=(const String& other) {
        if(this == &other) {
            return *this;
        }

        delete[] datos;

        tam = other.tam;
        capacidad = other.capacidad;
        datos = new char[capacidad];

        for(int i = 0; i <= tam; i++) {
            datos[i] = other.datos[i];
        }

        return *this;
    }

    String& operator+=(const String& other) {
        for(int i = 0; i < other.tam; i++) {
            push_back(other.datos[i]);
        }

        return *this;
    }

    String operator+(const String& other) const {
        String resultado(*this);
        resultado += other;
        return resultado;
    }

    bool operator==(const String& other) const {
        if(tam != other.tam) {
            return false;
        }

        for(int i = 0; i < tam; i++) {
            if(datos[i] != other.datos[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const String& s) {
        out << s.datos;
        return out;
    }

    friend istream& operator>>(istream& in, String& s) {
        char buffer[1000];
        in >> buffer;

        s.clear();

        for(int i = 0; buffer[i] != '\0'; i++) {
            s.push_back(buffer[i]);
        }

        return in;
    }
};

int main() {
    String s("Hola");

    s.push_back('!');

    cout << s << endl;

    s.pop_back();

    cout << s << endl;

    s += String(" mundo");

    cout << s << endl;

    s.reverse();

    cout << s << endl;

    return 0;
}