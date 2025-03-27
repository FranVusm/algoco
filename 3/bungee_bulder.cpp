#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    int maxJumpingDistance = 0;
    
    // Probamos cada par posible de montañas para el puente
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Altura máxima permitida para el puente (la más baja de las dos montañas)
            int bridgeHeight = min(heights[i], heights[j]);
            
            // Verificamos si el puente es válido (más alto que todas las montañas intermedias)
            bool valid = true;
            int lowestPoint = bridgeHeight;
            
            for (int k = i + 1; k < j; k++) {
                if (heights[k] >= bridgeHeight) {
                    valid = false;
                    break;
                }
                lowestPoint = min(lowestPoint, heights[k]);
            }
            
            // Si el puente es válido, calculamos la distancia de salto
            if (valid && i + 1 < j) {  // Aseguramos que hay al menos una montaña entre ellas
                int jumpingDistance = bridgeHeight - lowestPoint;
                maxJumpingDistance = max(maxJumpingDistance, jumpingDistance);
            }
        }
    }
    
    cout << maxJumpingDistance << endl;
    
    return 0;
}