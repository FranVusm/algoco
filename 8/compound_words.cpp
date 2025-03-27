#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
int main(){
    string palabra;

    vector<string> palabras;
    while (cin >> palabra){
        palabras.push_back(palabra);
    }
    unordered_set<string> palabras_combinadas;
    for (int i = 0; i < palabras.size(); ++i){
        for (int j = 0; j < palabras.size(); ++j){
            if (i != j){
                string combinada = palabras[i] + palabras[j];
                palabras_combinadas.insert(combinada);
            }
        }
    }
    vector<string> palabras_ordenadas(palabras_combinadas.begin(), palabras_combinadas.end());
    sort(palabras_ordenadas.begin(), palabras_ordenadas.end());
    
    for (const auto& palabra : palabras_ordenadas) {
        cout << palabra << endl;
    }

    return 0;
}