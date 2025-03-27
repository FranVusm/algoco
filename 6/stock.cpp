#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <map>
using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        int numOrders;
        cin >> numOrders;
        cin.ignore();
        map<int, int> sell_orders;
        map<int, int, greater<int>> buy_orders;
        int stock_price = -1;
        while (numOrders--){
        string tipo, basura, precio;
        int cantidad;
        string linea;
        getline(cin, linea);
        stringstream ss(linea);
        ss >> tipo >> cantidad >> basura >> basura >> precio;
        int precio_int = stoi(precio);
        
        if(tipo == "buy"){
            buy_orders[precio_int] += cantidad; 
           
        } 
        else{
                sell_orders[precio_int] += cantidad; 
            }
    
        // 1. Agrega orden al mapa

// 2. PROCESA TODAS LAS TRANSACCIONES POSIBLES:
while (!sell_orders.empty() && !buy_orders.empty() && sell_orders.begin()->first <= buy_orders.begin()->first) {
    auto sell_it = sell_orders.begin();
    auto buy_it = buy_orders.begin();
    
    int trans_price = sell_it->first;
    int trans_qty = min(sell_it->second, buy_it->second);
    
    sell_it->second -= trans_qty;
    buy_it->second -= trans_qty;
    
    stock_price = trans_price;

    if (sell_it->second == 0) sell_orders.erase(sell_it);
    if (buy_it->second == 0) buy_orders.erase(buy_it);
}
if (!sell_orders.empty())
cout << sell_orders.begin()->first << " ";
else
cout << "- ";

// bid
if (!buy_orders.empty())
cout << buy_orders.begin()->first << " ";
else
cout << "- ";

// stock
if (stock_price != -1)
cout << stock_price << endl;
else
cout << "-" << endl;
        }
    // ask


    }
    
    return 0;
}