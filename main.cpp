#include <iostream>
#include <ctime>
using namespace std;

void add_to_end(int* A, int M, int* B, int N, int* C) {
    for (int i = 0; i < M; i++) {
        C[i] = A[i];
    }
    for (int i = 0; i < N; i++) {
        C[M + i] = B[i];
    }
}

int main() {
    srand(time(0));

    int M, N;
    cout << "Enter size of array A: ";
    cin >> M;
    int* A = new int[M];

    for (int i = 0; i < M; i++) {
        A[i] = rand() % 10;
    }

    cout << "Enter size of array B: ";
    cin >> N;
    int* B = new int[N];

    for (int i = 0; i < N; i++) {
        cout << "Enter element to add: ";
        cin >> B[i];
    }

    cout << "Array A: ";
    for (int i = 0; i < M; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int* C = new int[M + N];
    add_to_end(A, M, B, N, C);

    cout << "Combined array: ";
    for (int i = 0; i < M + N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
