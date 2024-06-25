#include <iostream>
#include <ctime>
using namespace std;

void remove_elements(int* A, int M, int index, int N, int* C) {
    for (int i = 0; i < index; i++) {
        C[i] = A[i];
    }
    for (int i = index + N; i < M; i++) {
        C[i - N] = A[i];
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

    cout << "Array A: ";
    for (int i = 0; i < M; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Enter number of elements to remove: ";
    cin >> N;

    cout << "Enter index to start removal: ";
    cin >> index;

    if (index < 0 || index + N > M) {
        cout << "Invalid index or number of elements to remove!" << endl;
        delete[] A;
        return 1;
    }

    cout << "Array A: ";
    for (int i = 0; i < M; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int* C = new int[M - N];
    remove_elements(A, M, index, N, C);

    cout << "New array: ";
    for (int i = 0; i < M - N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] C;

    return 0;
}
