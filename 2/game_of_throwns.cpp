#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int numero1, numero2;
    cin >> numero1 >> numero2;
    cin.ignore();

    string line;
    getline(cin, line);

    istringstream iss(line);
    vector<string> comandos;
    string palabra;

    // Leer los comandos, juntando "undo X"
    while (iss >> palabra) {
        if (palabra == "undo") {
            string steps;
            if (iss >> steps) {
                comandos.push_back("undo " + steps);
            }
        } else {
            comandos.push_back(palabra);
        }
    }

    vector<int> historial;

    for (const string& cmd : comandos) {
        if (cmd.substr(0, 4) == "undo") {
            int pasos = stoi(cmd.substr(5));
            while (pasos-- && !historial.empty()) {
                historial.pop_back();
            }
        } else {
            historial.push_back(stoi(cmd));
        }
    }

    // Calcular la posición final
    int niño = 0;
    for (int paso : historial) {
        niño = (niño + paso) % numero1;
        if (niño < 0) niño += numero1;
    }

    cout << niño << endl;

    return 0;
}
