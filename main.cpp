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

int* appendElement(int* arr, int& size, int element) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    ++size;
    delete[] arr;
    return newArr;
}

int* insertElement(int* arr, int& size, int index, int element) {
    if (index < 0 || index > size) {
        cout << "Некоректний індекс для вставки!" << endl;
        return arr;
    }

    int* newArr = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index + 1; i <= size; ++i) {
        newArr[i] = arr[i - 1];
    }
    ++size;
    delete[] arr;
    return newArr;
}

int* removeElement(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Некоректний індекс для видалення!" << endl;
        return arr;
    }

    int* newArr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }
    --size;
    delete[] arr;
    return newArr;
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