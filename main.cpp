#include <iostream>
#include <ctime>
using namespace std;

int* allocateMemory(int size) {
    int* arr = new int[size];
    return arr;
}

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0; 
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

void add_to_end(int* A, int M, int* B, int N, int* C) {
    for (int i = 0; i < M; i++) {
        C[i] = A[i];
    }
    for (int i = 0; i < N; i++) {
        C[M + i] = B[i];
    }
}

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

    int M, N;
    cout << "Enter size of array A: ";
    cin >> M;
    int* A = new int[M];

    for (int i = 0; i < M; i++) {
        A[i] = rand() % 10;
    }

    cout << "Enter size of array B to add in end: ";
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






	return 0;
	system("pause");
}