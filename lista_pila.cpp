#include <iostream>
using namespace std;

class Nodo 
{
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) 
    {
        dato = valor;
        siguiente = nullptr;
    }
};

class Lista 
{
private:
    Nodo* inicio;

public:
    Lista() 
    {
        inicio = nullptr;
    }

    //---------------------------------METODOS AGREGAR-------------------------------------------------
    void agregar(int valor)
    {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = inicio; 
        inicio = nuevoNodo;            
    }

    


    //------------------------------------------------------------------------------------------------------
    // -------------------------------------METODOS ELIMINAR------------------------------------------------
    
    void eliminar() 
    {
        
        if (inicio == nullptr) 
        {
            cout << "Lista vacia, no se puede eliminar." << endl;
            return;
        }

        Nodo* temp = inicio;  
        inicio = inicio->siguiente;
        delete temp; 
    }
    
    //-------------------------------------------------------------------------------------------------------
    
    void mostrar() 
    {
        Nodo* actual = inicio;
        while (actual != nullptr) 
        {
            cout << actual->dato << " - ";
            actual = actual->siguiente;
        }
        cout << "BASE" << endl;
    }

    ~Lista() 
    {
        Nodo* actual = inicio;
        while (actual != nullptr) 
        {
            Nodo* siguienteTemp = actual->siguiente;
            delete actual;                           
            actual = siguienteTemp;            
        }
    }
};

int main() 
{
    Lista lst;
    
    cout << "Anadiendo un elemento a la Pila ";
    lst.agregar(10);
    lst.agregar(20);
    lst.agregar(30);
    lst.mostrar(); 

    cout << "Eliminando un elemento de la Pila ";
    lst.eliminar();
    lst.mostrar();
    cin.get();
    return 0; 
}