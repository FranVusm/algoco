#include <iostream>
#include <string>
#include <unordered_set>
 
using namespace std;

int main(){
    int X,Y;
    cin >> X >> Y;
    cin.ignore();
unordered_set<int> obstaculos;
for (int i = 0; i < Y; ++i) {
    string location;
    getline(cin, location);
    obstaculos.insert(stoi(location));
}
int count = 0;
for (int i = 0; i < X; ++i) {

    if (obstaculos.find(i) == obstaculos.end()) {
        cout << i << endl;
    }
    else {
        count++;
    }
}
cout << "Mario got " << count << " of the dangerous obstacles." << endl;
}