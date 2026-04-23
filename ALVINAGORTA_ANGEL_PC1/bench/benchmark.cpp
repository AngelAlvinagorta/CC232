#include <iostream>
#include <string>
#include <chrono> 
#include "Stack.h" 

using namespace std;
using namespace std::chrono;

// SOLUCIÓN OPTIMA O(n)
class Solution {
public:
    bool isValid(string s) {
        Stack st(s.length()); 
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
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

// SOLUCIÓN INGENUA O(n^2)
class SolutionNaive {
public:
    bool isValid(string s) {
        bool encontrada = true;
        
        while (encontrada) {
            encontrada = false;
            size_t pos;
            
            // Buscamos y borramos parejas contiguas
            if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                encontrada = true;
            } else if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                encontrada = true;
            } else if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                encontrada = true;
            }
        }
        
        return s.empty(); 
    }
};

int main() {
    Solution solOptima;
    SolutionNaive solIngenua;
    
    // CASO LÍMITE
    string pruebaPesada = string(5000, '(') + string(5000, ')');
    int repeticiones = 1000;
    
    cout << "=== INICIANDO COMPETICION DE ALGORITMOS ===" << endl;
    cout << "Longitud de cadena: " << pruebaPesada.length() << " caracteres." << endl;
    cout << "Iteraciones: " << repeticiones << "\n" << endl;
    
    // EVALUANDO SOLUCION INGENUA
    cout << "===REALIZANDO EVALUACIONES TENGA PACIENCIA===" << endl;
    cout << "-Evaluando Solucion Ingenua (Busqueda y Reemplazo O(n^2))..." << endl;
    auto inicioIngenua = high_resolution_clock::now();
    bool resIngenua = false;
    for(int i = 0; i < repeticiones; i++) {
        resIngenua = solIngenua.isValid(pruebaPesada);
    }
    auto finIngenua = high_resolution_clock::now();
    auto duracionIngenua = duration_cast<milliseconds>(finIngenua - inicioIngenua);
    
    // EVALUANDO SOLUCION OPTIMA
    cout << "-Evaluando Solucion Optima (Stack O(n))..." << endl;
    auto inicioOptima = high_resolution_clock::now();
    bool resOptima = false;
    for(int i = 0; i < repeticiones; i++) {
        resOptima = solOptima.isValid(pruebaPesada);
    }
    auto finOptima = high_resolution_clock::now();
    auto duracionOptima = duration_cast<milliseconds>(finOptima - inicioOptima);

    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Correctitud Ingenua: " << (resIngenua ? "true" : "false") << " | Tiempo: " << duracionIngenua.count() << " ms" << endl;
    cout << "Correctitud Optima : " << (resOptima ? "true" : "false") << "  | Tiempo: " << duracionOptima.count() << " ms" << endl;
    
    return 0;
}