#include <iostream>
#include <ctime>
using namespace std;

void paste_elements(int* A, int M, int* B, int N, int index, int* C) {
    for (int i = 0; i < index; i++) {
        C[i] = A[i];
    }
    for (int i = 0; i < N; i++) {
        C[index + i] = B[i];
    }
    for (int i = index; i < M; i++) {
        C[N + i] = A[i];
    }
}

int main() {
    srand(time(0));

    int M, N, index;
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

    cout << "Enter index to insert elements: ";
    cin >> index;

    if (index < 0 || index > M) {
        cout << "Invalid index!" << endl;
        delete[] A;
        delete[] B;
        return 1;
    }

    cout << "Array A: ";
    for (int i = 0; i < M; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int* C = new int[M + N];
    paste_elements(A, M, B, N, index, C);

    cout << "New array: ";
    for (int i = 0; i < M + N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
