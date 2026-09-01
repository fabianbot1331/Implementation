#include <bits/stdc++.h>
using namespace std;

class Vector{
    private:
    int* datos;
    int tam;
    int capacidad;
    public:
    int* begin(){
        return datos;
    }

    int* end(){
        return datos + tam;
    }
    
    Vector(){
        tam = 0;
        capacidad = 0;
        datos = nullptr;
    }
    Vector(int capacidad_){
        capacidad = capacidad_;
        tam = 0;
        datos = new int[capacidad_];
    }
    
    ~Vector(){
        delete[] datos;
    }
    
    int& operator[](int x){
        return datos[x];
    }
    
    const int& operator[](int x) const{
        return datos[x];
    }
    int size() const{
        return tam;
    }
    
    int capacity() const{
        return capacidad;
    }
    
    void push_back(int valor){
        if(tam < capacidad){
            datos[tam] = valor;
            tam +=1;
        }
        else{
            if(capacidad == 0) capacidad = 1;
            else capacidad*=2;
            int* ndatos = new int[capacidad];
            for(int i=0; i<tam;i++){
                ndatos[i] = datos[i];
            }
                ndatos[tam] = valor;
                delete[] datos;
                datos = ndatos;
                tam+=1;
            }
        }
    
    void pop_back(){
        if(tam>0) tam = tam -1;
        
    }
    
    Vector(const Vector& other){
        tam = other.tam;
        capacidad = other.capacidad;
        datos = new int[capacidad];
        for(int i=0; i<tam; i++){
            datos[i] = other.datos[i];
        }
    }
    
    Vector& operator=(const Vector& other){
        if(this == &other){
            return *this;
        }
        delete[] datos;
        tam = other.tam;
        capacidad = other.capacidad;
        datos = new int[capacidad];
        for(int i=0; i<tam; i++){
            datos[i] = other.datos[i];
        }
        return *this;
    }
    void reverse(){
        int i=0;
        int j = tam-1;
        while(i<j){
            swap(datos[i],datos[j]);
            i++;
            j--;
        }
    }
    
    void sort(){
        if (tam>1) quicksort(0, tam-1);
    }
    
    int partition(int izquierda, int derecha) {
        int pivote = datos[derecha];
        int i = izquierda;

        for (int j = izquierda; j < derecha; j++) {
            if (datos[j] < pivote) {
                swap(datos[i], datos[j]);
                i++;
            }
        }

        swap(datos[i], datos[derecha]);

        return i;
    }

    void quicksort(int izquierda, int derecha) {
        if (izquierda >= derecha) {
            return;
        }

        int posicionPivote = partition(izquierda, derecha);

        quicksort(izquierda, posicionPivote - 1);
        quicksort(posicionPivote + 1, derecha);
    }
    
};

int main(){
    Vector v;

    v.push_back(5);
    v.push_back(2);
    v.push_back(8);
    v.push_back(1);

    cout << "Vector: ";
    for(auto x: v) cout << x << " ";

    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();

    v.sort();

    cout << "\nOrdenado: ";
    for(auto x: v) cout << x << " ";

    v.reverse();

    cout << "\nInvertido: ";
    for(auto x: v) cout << x << " ";

    return 0;
}