#include <iostream>

using namespace std;

class ColaLineal 
{
    private:
        int arr[5]; 
        int frente; 
        int final;  
        int max;

    public:
        ColaLineal() 
        {
            frente = -1;
            final = -1;
            max = 5;
        }

        
        bool estaLlena() 
        {
            return (final == max - 1);
        }

        bool estaVacia() 
        {
            return (frente == -1 || frente > final);
        }

        void push(int valor) 
        {
            if (estaLlena()) 
            {
                cout << " Cola llena (final alcanzo el limite). No entra: " << valor << endl;
            } 
            else 
            {
                
                if (frente == -1) frente = 0;

                final++;
                arr[final] = valor;
                cout << "Insertado: " << valor << " en pos " << final << endl;
            }
        }

        int pop() 
        {
            if (estaVacia()) 
            {
                cout << " Cola vacia" << endl;
                return -1;
            } 
            else 
            {
                int valor = arr[frente];
                frente++; 
                
                
                if (frente > final) 
                {
                    frente = -1;
                    final = -1;
                    cout << " Cola vaciada completamente. Indices reseteados." << endl;
                }
                
                return valor;
            }
        }

        void clean() 
        {
            frente = -1;
            final = -1;
            cout << "La cola ha sido limpiada." << endl;
        }

        void imprimir() 
        {
            if (estaVacia()) 
            {
                cout << "[ Cola Vacia ]" << endl;
                return;
            }

            cout << "\n--- Cola Lineal ---" << endl;
            for (int i = frente; i <= final; i++) 
            {
                cout << "Pos[" << i << "]: " << arr[i] << endl;
            }
            cout << "-------------------" << endl;
        }
};

int main() 
{
    ColaLineal cl;

    

    cout << "--- Llenando la cola ---" << endl;
    cl.push(10);
    cl.push(20);
    cl.push(30);
    cl.push(40);
    cl.push(50); 

    cl.imprimir();

    cout << "\n--- Sacando elementos ---" << endl;
    cout << "Atendiendo a: " << cl.pop() << endl; 
    cout << "Atendiendo a: " << cl.pop() << endl; 

    cl.imprimir();

    cout << "\n--- Intentando insertar (Problema de la Lineal) ---" << endl;
    cl.push(60); 
    
    return 0;
}