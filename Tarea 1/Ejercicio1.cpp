#include <iostream>
#include <chrono>

using namespace std;
#define MAX 100

int main() {
    double A[MAX][MAX]; 
    double x[MAX];     
    double y[MAX] = {0}; 

    // Inicialización
    for (int i = 0; i < MAX; ++i) 
        for (int j = 0; j < MAX; ++j) 
            A[i][j] = 1;

    for (int i = 0; i < MAX; ++i)
        x[i] = i * 1.0;

    
    //1
    auto start1 = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];

    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;
    cout << "Tiempo de ejecución de //1: " << duration1.count() << " segundos" << endl;


    // Reinicio
    for (int i = 0; i < MAX; ++i)
        y[i] = 0;


    //2
    auto start2 = chrono::high_resolution_clock::now();
    
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];

    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    cout << "Tiempo de ejecución de //2: " << duration2.count() << " segundos" << endl;

    return 0;
}
