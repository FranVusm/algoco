#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    std::list<char> texto;
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
    string linea;
    getline(cin, linea);
    auto cursor = texto.begin();
    for (char c: linea){
        if (c == '<') {
            if (cursor != texto.begin()) --cursor, cursor = texto.erase(cursor);
        }
        else if (c == '[') {
            cursor = texto.begin();
        }
        else if (c == ']') {
            cursor = texto.end();
        }
        else {
            texto.insert(cursor, c);
        }
    }
    
    cout << string(texto.begin(), texto.end()) << endl;
    texto.clear();
    }
    
   
    return 0;
}