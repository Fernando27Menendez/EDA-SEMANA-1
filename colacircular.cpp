#include <iostream>
using namespace std;
//#define MAX 5
class ColaCircular 
{
    private:
        int arr[5]; 
        int inicio;  // Apunta al primer elemento
        int final;   // Apunta al último elemento agregado
        int max;    // Tamaño máximo

    public:
        ColaCircular() 
        {
            inicio = -1;
            final = -1;
            max = 5;
        }

        
        bool estaLlena() 
        {
            return ( (final + 1) % max == inicio);
        }

        bool estaVacia() 
        {
            return (inicio == -1);
        }

        void push(int valor) 
        {
            if (estaLlena()) 
            {
                cout << "La Cola Circular llena. No se pudo insertar el: " << valor << endl;
            } 
            else 
            {
                
                if (inicio == -1) 
                {
                    inicio = 0;
                    final = 0;
                }
                else 
                {
                    final = (final + 1) % max;
                }
                
                arr[final] = valor;
                cout << "Insertado: " << valor << " en pos " << final << endl;
            }
        }

        int pop() 
        {
            if (estaVacia()) 
            {
                cout << "La Cola esta vacia" << endl;
                return -1;
            } 
            
            int valor = arr[inicio];
            
            
            if (inicio == final) 
            {
                inicio = -1;
                final = -1;
            } 
            else 
            {
                inicio = (inicio + 1) % max;
            }
            
            return valor;
        }

        void imprimir() 
        {
            if (estaVacia()) 
            {
                cout << "[ Cola Vacia ]" << endl;
                return;
            }

            cout << "\n--- Estado Cola Circular ---" << endl;
            cout << "Frente: " << inicio << " | Final: " << final << endl;
            
            int i = inicio;
            while (true) 
            {
                cout << "Pos[" << i << "]: " << arr[i] << endl;
                
                if (i == final) break; 
                
                i = (i + 1) % max; 
            }
            cout << "----------------------------" << endl;
        }
};

int main() 
{
    ColaCircular cc;

    cout << "--- Llenando la cola ---" << endl;
    cc.push(10);
    cc.push(20);
    cc.push(30);
    cc.push(40);
    cc.push(50); // Aquí 'final' es 4

    cc.imprimir();

    cout << "\n--- Sacando dos elementos ---" << endl;
    cout << "Atendiendo a: " << cc.pop() << endl; // Sale el 10, 'frente' avanza a 1
    cout << "Atendiendo a: " << cc.pop() << endl; // Sale el 20, 'frente' avanza a 2

    cc.imprimir();

    cout << "\n--- Insertando nuevo ---" << endl;
    
    cc.push(60); 
    cc.push(70);

    cc.imprimir();

    return 0;
}