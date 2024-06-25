#include <iostream>
#include <ctime>
using namespace std;



bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            count++;
        }
    }

    int* newArr = new int[count];
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newArr[index++] = arr[i];
        }
    }

    newSize = count;

    return newArr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20;
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    int newSize;
    int* result = removePrimes(arr, size, newSize);

    cout << "Array without prime numbers: ";
    for (int i = 0; i < newSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] result;

	return 0;
	system("pause");
}