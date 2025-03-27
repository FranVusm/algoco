#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

deque<int> parsearLista(const string& input) {
    deque<int> resultado;
    if (input == "[]") return resultado; // Lista vacía

    string contenido = input.substr(1, input.length() - 2); // quita los corchetes
    stringstream ss(contenido);
    string numero;

    while (getline(ss, numero, ',')) {
        resultado.push_back(stoi(numero));
    }

    return resultado;
}



int main() {
 
    int T;
    cin >> T;
    cin.ignore();
    while (T--){
       
    string reglas, input;
    getline(cin, reglas);
    string lenghStr;
    getline(cin, lenghStr);
    int n = stoi(lenghStr);
    getline(cin, input); // Lee la línea con instrucciones
    deque<int> lista = parsearLista(input);
    if (lista.size() != n) {
        cout << "error" << endl;
        continue;
    }

    bool vuelta = false;
    bool error = false;
    // Procesar las reglas
    for (char c : reglas) {
        if (c == 'R') {
            vuelta = !vuelta; // Cambiar el estado de "vuelta"
        } else if (c == 'D') {
            if (lista.empty()) {
                cout << "error" << endl;
                error = true;
                break;
            }
            else{
            if (vuelta) {
                lista.pop_back();
            } else {
                lista.pop_front();
            }
        }
        }
    }
    

    // Imprimir el resultado
    if (!error) {
        cout << "[";
        if (!lista.empty()) {
            if (vuelta) {
                for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
                    if (it != lista.rbegin()) cout << ",";
                    cout << *it;
                }
            } else {
                for (auto it = lista.begin(); it != lista.end(); ++it) {
                    if (it != lista.begin()) cout << ",";
                    cout << *it;
                }
            }
        }
        cout << "]" << endl;
    }
}
    
    
    return 0;
}