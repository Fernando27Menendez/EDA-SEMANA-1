#include <iostream>

using namespace std;

class Pila 
{
    private:
    
        int arr[5]; 
        int top;      
    
    public:
        // Constructor
        Pila() 
        {
            top = -1; 
        }
    
        
        bool estaVacia() {
            return (top < 0);
        }
    
       
        bool estaLlena() 
        {
            return (top >= 4);
        }
    
        
        void push(int valor) 
        {
            if (estaLlena()) 
            {
                cout << "Error: La pila esta llena. No cabe el valor " << valor << endl;
            } 
            else 
            {
                top++;
                arr[top] = valor;
                cout << "Insertado: " << valor << endl;
            }
        }
    
       
        int pop() 
        {
            if (estaVacia()) 
            {
                cout << "Error: La pila esta vacia" << endl;
                return -1; 
            } else {
                int valor = arr[top];
                top--;
                return valor;
            }
        }
    
        
        void clean() 
        {
            top = -1; 
            cout << "La pila ha sido limpiada." << endl;
        }
    
    
        void imprimir() 
        {
            if (estaVacia()) 
            {
                cout << "[ Pila Vacia ]" << endl;
                return;
            }
    
            cout << "\n--- Pila ---" << endl;
            
            for (int i = top; i >= 0; i--) 
            {
                cout <<  arr[i]  << endl;
            }
            
        }
};

int main() 
{
    Pila miPila;

    
    cout << "--- Insertando elementos ---" << endl;
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);
    miPila.push(40);
    miPila.push(50); 

    miPila.push(60); 

    miPila.imprimir();

    cout << "\nSacando el: " << miPila.pop() << endl;
    miPila.imprimir();

    miPila.clean();
    miPila.imprimir();

    return 0;
}