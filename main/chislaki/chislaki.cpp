#include <iostream>
using namespace std;
int main(){
    int n = 6;
    int **y = new int*[n];
    for (int i = 0; i < n; i++)
        y[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[i][j] = 0;
    
    for (int i = 0; i < 2; i++, cout << "\n")
        for (int j = 0; j < n; j++)
            cout << "0 ";

    for (int i = 2; i < n; i++, cout << "0\n") {
        cout << "0 ";
        for (int j = 1; j < n - 1; j++) {
            if (i > j)
                y[i][j] = j * j * 5;
            cout << y[i][j] << " ";
        }
    }
    return 0;
}
