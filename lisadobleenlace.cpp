#include <iostream>
using namespace std;

class Nodo 
{
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) 
    {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
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
        nuevoNodo->anterior = nullptr;       
        
        if (inicio != nullptr) 
        {
            inicio->anterior = nuevoNodo;    
        }
        
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
            nuevoNodo->anterior = actual;
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

        // Avanzamos hasta uno antes de la posición deseada
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
            // El nuevo nodo apunta al puntero siguiente del actual(1 pos antes del nuevo)
            nuevoNodo->siguiente = actual->siguiente;
            
            // El nuevo nodo con su puntero anterior apunta hacia atrás al actual
            nuevoNodo->anterior = actual;

            // Si hay un nodo después, ese nodo debe apuntar hacia atrás al nuevo
            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = nuevoNodo;
            }

            // El nodo actual apunta al nuevo
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
        
        if (inicio != nullptr) {
            inicio->anterior = nullptr; // El nuevo inicio no debe tener anterior
        }
        
        delete temp; 
    }

    void eliminar_derecha() 
    {
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
        
        
        while (actual->siguiente != nullptr) 
        {
            actual = actual->siguiente;
        }

        
        actual->anterior->siguiente = nullptr;
        delete actual;  
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

        
        while (actual != nullptr && contador < pos) 
        {
            actual = actual->siguiente;
            contador++;
        }

        if (actual == nullptr) 
        {
            cout << "Posicion fuera de rango." << endl;
            return;
        }

       
        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        }
        
        if (actual->siguiente != nullptr) 
        {
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;          
    }
    
    //-------------------------------------------------------------------------------------------------------
    
    void mostrar() 
    {
        Nodo* actual = inicio;
        cout << "Ida: NULL <- ";
        while (actual != nullptr) 
        {
            cout << actual->dato;
            if(actual->siguiente != nullptr) cout << " <-> ";
            else cout << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
    void mostrar_invertido()
    {
        if (inicio == nullptr) return;

    
        Nodo* actual = inicio;
        while(actual->siguiente != nullptr) 
        {
            actual = actual->siguiente;
        }

        cout << "Vuelta: NULL <- ";

        while (actual != nullptr) 
        {
            cout << actual->dato;
            if(actual->anterior != nullptr) cout << " <-> ";
            else cout << " -> ";
            actual = actual->anterior;
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


class Pila {
private:
    Lista listaInterna;

public:
    void push(int valor) 
    {
        listaInterna.agregar_izquierda(valor);
    }

    void pop() 
    {
        listaInterna.eliminar_izquierda();
    }

    void mostrar() 
    {
        cout << "Tope -> ";
        listaInterna.mostrar();
    }
};

class Cola {
private:

    Lista listaInterna;

public:
    void encolar(int valor) 
    {
        
        listaInterna.agregar_derecha(valor);
    }

    void desencolar() 
    {
    
        listaInterna.eliminar_izquierda();
    }

    void mostrar() 
    {
        cout << "Inicio Fila -> ";
        listaInterna.mostrar();
    }
};

int main() 
{
    Lista lst;

    lst.agregar_derecha(20);
    lst.agregar_derecha(30);
    cout << "Inicio normal: " << endl;
    lst.mostrar();

    cout << "Agregando 10 a la izquierda: " << endl;
    lst.agregar_izquierda(10); 
    lst.mostrar(); 

    cout << "Insertando 25 en posicion 2: " << endl;
    lst.agregar_posicion(25, 2);
    lst.mostrar();
    lst.mostrar_invertido(); 

    cout << "Eliminando de la izquierda: " << endl;
    lst.eliminar_izquierda();
    lst.mostrar();

    cout << "Eliminando de la derecha: " << endl;
    lst.eliminar_derecha();
    lst.mostrar();

    cout << "Eliminando en posicion 1: " << endl;
    lst.eliminar_posicion(0);   
    lst.mostrar();

    // --- PRUEBA DE PILA ---
    cout << "================ PILA  ================" << endl;
    Pila miPila;
    miPila.push(10); 
    miPila.push(20); 
    miPila.push(30); 
    miPila.mostrar(); 
    
    cout << "Haciendo Pop (sacar plato)..." << endl;
    miPila.pop();    
    miPila.mostrar(); 

    cout << endl;

    // --- PRUEBA DE COLA ---
    cout << "================== COLA=====================" << endl;
    Cola miCola;
    miCola.encolar(100);
    miCola.encolar(200);
    miCola.encolar(300); 
    miCola.mostrar();    

    cout << "Atendiendo cliente (desencolar)..." << endl;
    miCola.desencolar(); 
    miCola.mostrar();   
    
    
    cin.get();
    return 0; 

}