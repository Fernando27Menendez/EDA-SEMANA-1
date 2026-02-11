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

        
        if (inicio == nullptr) 
        {
            inicio = nuevoNodo;
        } 
        else 
        {
            Nodo* actual = inicio;
            
            while (actual->siguiente != nullptr) 
            {
                actual = actual->siguiente;
            }
            
            actual->siguiente = nuevoNodo;
        }
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
        cout <<"FIN"<< endl;
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

    lst.agregar(20);
    lst.agregar(30);
    cout << "ESTADO DE LA COLA: ";
    lst.mostrar();
 
    cout << "ATENDIENDO AL PRIMERO DE LA COLA ";
    lst.eliminar();
    lst.mostrar();

    cin.get();
    return 0; 
}