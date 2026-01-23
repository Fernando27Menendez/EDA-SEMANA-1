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
    void agregar_izquierda(int valor)
    {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = inicio; 
        inicio = nuevoNodo;            
    }

    void agregar_derecha(int valor)
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

    
    void agregar_posicion(int valor, int pos)
    {

        if (pos < 0) 
        {
            cout << "Posicion no valida." << endl;
            return;
        }

        if (pos == 0) {
            agregar_izquierda(valor);
            return;
        }

        Nodo* nuevoNodo = new Nodo(valor);
        Nodo* actual = inicio;
        int contador = 0;

        
        while (actual != nullptr && contador < pos - 1) 
        {
            actual = actual->siguiente;
            contador++;
        }

        
        if (actual == nullptr) 
        {
            cout << "Posicion fuera de rango. No se agrego el nodo." << endl;
            delete nuevoNodo;
        } 
        else 
        {
            
            nuevoNodo->siguiente = actual->siguiente; 
            actual->siguiente = nuevoNodo;            
        }
    }


    //------------------------------------------------------------------------------------------------------
    // -------------------------------------METODOS ELIMINAR------------------------------------------------
    
    void eliminar_izquierda() 
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

    void eliminar_derecha() 
    {
        // Caso A: Lista vacía
        if (inicio == nullptr) 
        {
            cout << "Lista vacia." << endl;
            return;
        }

        if (inicio->siguiente == nullptr) 
        {
            delete inicio;
            inicio = nullptr;
            return;
        }

        Nodo* actual = inicio;
        
        while (actual->siguiente->siguiente != nullptr) 
        {
            actual = actual->siguiente;
        }

        delete actual->siguiente;  
        actual->siguiente = nullptr;
    }

    
    void eliminar_posicion(int pos) 
    {
    
        if (inicio == nullptr) 
        {
            cout << "Lista vacia." << endl;
            return;
        }
        if (pos < 0) 
        {
            cout << "Posicion invalida." << endl;
            return;
        }

        if (pos == 0) 
        {
            eliminar_izquierda();
            return;
        }

        Nodo* actual = inicio;
        int contador = 0;

        while (actual != nullptr && contador < pos - 1) 
        {
            actual = actual->siguiente;
            contador++;
        }

        if (actual == nullptr || actual->siguiente == nullptr) 
        {
            cout << "Posicion fuera de rango." << endl;
            return;
        }


        Nodo* aBorrar = actual->siguiente;      
        actual->siguiente = aBorrar->siguiente; 
        delete aBorrar;           
    }
    
    //-------------------------------------------------------------------------------------------------------
    
    void mostrar() 
    {
        Nodo* actual = inicio;
        while (actual != nullptr) 
        {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
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

    lst.agregar_derecha(20);
    lst.agregar_derecha(30);
    cout << "Inicio normal: ";
    lst.mostrar();

    
    cout << "Agregando 10 a la izquierda: ";
    lst.agregar_izquierda(10); 
    lst.mostrar(); 

    
    cout << "Insertando 25 en posicion 2: ";
    lst.agregar_posicion(25, 2);
    lst.mostrar();

    
    cout << "Intentando insertar en posicion 99: ";
    lst.agregar_posicion(99, 99);

    cout << "Eliminando de la izquierda: ";
    lst.eliminar_izquierda();
    lst.mostrar();

    cout << "Eliminando de la derecha: ";
    lst.eliminar_derecha();
    lst.mostrar();

    cout << "Eliminando en posicion 1: ";
    lst.eliminar_posicion(0);
    lst.mostrar();

    return 0; 
}