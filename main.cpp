#include <iostream>
#include <ctime>
using namespace std;

int* allocateMemory(int M) {
    int* A = new int[M];
    return A;
}

void initializeArray(int* A, int M) {
    for (int i = 0; i < M; ++i) {
        A[i] = 0;
    }
}

void printArray(int* A, int M) {
    for (int i = 0; i < M; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* A) {
    delete[] A;
}

void add_to_end(int* A, int M, int* B_end, int N_end) {
    for (int i = 0; i < N_end; i++) {
        A[M + i] = B_end[i];
    }
}

void paste_elements(int* A, int M, int* B_paste, int N_paste, int index) {
    for (int i = M - 1; i >= index; i--) {
        A[i + N_paste] = A[i];
    }
    for (int i = 0; i < N_paste; i++) {
        A[index + i] = B_paste[i];
    }
}

void remove_elements(int* A, int& M, int index_remove, int N_remove) {
    for (int i = index_remove + N_remove; i < M; i++) {
        A[i - N_remove] = A[i];
    }
    M -= N_remove;
}

int main() {
    srand(time(0));

    int M;
    cout << "Enter size of array A: ";
    cin >> M;

    int* A = allocateMemory(M);

    initializeArray(A, M);

    for (int i = 0; i < M; i++) {
        A[i] = rand() % 10;
    }

    printArray(A, M);

    int N_end;
    cout << "Enter size of array B to add in end: ";
    cin >> N_end;
    int* B_end = new int[N_end];
    for (int i = 0; i < N_end; i++) {
        cout << "Enter element to add: ";
        cin >> B_end[i];
    }

    add_to_end(A, M, B_end, N_end);
    M += N_end;

    cout << "Combined array: ";
    printArray(A, M);

    int N_paste;
    cout << "Enter size of array B: ";
    cin >> N_paste;
    int* B_paste = new int[N_paste];

    for (int i = 0; i < N_paste; i++) {
        cout << "Enter element to add: ";
        cin >> B_paste[i];
    }
    int index;
    cout << "Enter index to insert elements: ";
    cin >> index;

    if (index < 0 || index > M) {
        cout << "Invalid index!" << endl;
        delete[] A;
        delete[] B_paste;
        return 1;
    }

    paste_elements(A, M, B_paste, N_paste, index);
    M += N_paste;

    cout << "New array: ";
    printArray(A, M);

    int N_remove;
    cout << "Enter number of elements to remove: ";
    cin >> N_remove;

    int index_remove;
    cout << "Enter index to start removal: ";
    cin >> index_remove;

    if (index_remove < 0 || index_remove + N_remove > M) {
        cout << "Invalid index or number of elements to remove!" << endl;
        delete[] A;
        delete[] B_paste;
        return 1;
    }

    remove_elements(A, M, index_remove, N_remove);

    cout << "New array: ";
    printArray(A, M);

    deleteArray(A);
    delete[] B_end;
    delete[] B_paste;

    return 0;
}
