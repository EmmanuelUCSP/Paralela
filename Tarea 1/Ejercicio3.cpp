#include <iostream>
#include <chrono>

using namespace std;

void multiplyMatricesBlocked(int n, int blockSize) {
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

    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                
                // submatrices
                for (int i = ii; i < min(ii + blockSize, n); ++i) {
                    for (int j = jj; j < min(jj + blockSize, n); ++j) {
                        for (int k = kk; k < min(kk + blockSize, n); ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecución para tamaño " << n << "x" << n 
              << " con bloque de " << blockSize << "x" << blockSize 
              << ": " << duration.count() << " segundos" << endl;

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
    int blockSizes[] = {10, 20, 50};

    for (int size : sizes) {
        for (int blockSize : blockSizes) {
            multiplyMatricesBlocked(size, blockSize);
        }
    }

    return 0;
}
