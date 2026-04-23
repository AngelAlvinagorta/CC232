#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        Stack st(s.length()); 
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if (st.isEmpty()) return false;
                
                char caracterTope = st.top();
                st.pop(); 
                
                if (c == ')' && caracterTope != '(') return false;
                if (c == '}' && caracterTope != '{') return false;
                if (c == ']' && caracterTope != '[') return false;
            }
        }
        
        return st.isEmpty();
    }
};

int main() {
    Solution sol;
    
    //Ejemplo propuestos
    string ejemplos[] = {"()", "()[]{}", "(]", "([])", "([)]"};

    cout << "\nEjemplos Propuestos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "- Input: \"" << ejemplos[i] << "\" -> Output: " 
             << (sol.isValid(ejemplos[i]) ? "true" : "false") << endl;
    }
    
    // Modo interactivo para casos propios
    cout << "\n=== Modo Interactivo ===" << endl;
    cout << "Ingresa una cadena a evaluar o escribe salir para terminar el programa." << endl;
    
    string entradaUsuario;
    
    while (true) {
        cout << "\nInput: ";
        cin >> entradaUsuario;
        
        // Salir del Programa
        if (entradaUsuario == "salir") {
            cout << "Saliendo del programa." << endl;
            break; 
        }
        
        // Evalua el caso ingresado y muestra el resultado
        bool esValida = sol.isValid(entradaUsuario);
        
        cout << "Output: " << (esValida ? "true" : "false") << endl;
    }

    return 0;
}