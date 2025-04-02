#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Si hay menos de 3 montañas, no se puede construir puente
    if(n < 3){
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> left_max(n), right_max(n);
    left_max[0] = arr[0];
    for (int i = 1; i < n; i++){
        left_max[i] = max(left_max[i-1], arr[i]);
    }
    
    right_max[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--){
        right_max[i] = max(right_max[i+1], arr[i]);
    }
    
    int max_salto = 0;
    // Se recorre desde la segunda hasta la penúltima montaña
    for (int i = 1; i < n - 1; i++){
        int puente = min(left_max[i], right_max[i]);
        if (puente > arr[i]){
            max_salto = max(max_salto, puente - arr[i]);
        }
    }
    
    cout << max_salto << endl;
    return 0;
}
