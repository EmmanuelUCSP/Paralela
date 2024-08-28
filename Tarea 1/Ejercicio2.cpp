#include <iostream>
#include <chrono>

using namespace std;

void multiplyMatrices(int n) {
    double** A = new double*[n];
    double** B = new double*[n];
    double** C = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        B[i] = new double[n];
        C[i] = new double[n];
    }

    // Inicialización
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = i + j * 0.5;
            B[i][j] = i - j * 0.5;
            C[i][j] = 0; // matriz resultante C a 0
        }
    }

    // Multiplicación
    auto start = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecución para tamaño " << n << "x" << n << ": " 
              << duration.count() << " segundos" << endl;

    // Liberar la memoria dinámica
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

int main() {

    int sizes[] = {100, 200, 500, 1000};
    for (int size : sizes) {
        multiplyMatrices(size);
    }

    return 0;
}
