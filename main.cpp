#include <iostream>
#include <ctime>
using namespace std;

void distributeElements(int* staticArr, int size, int*& positiveArr, int& positiveSize, int*& negativeArr, int& negativeSize, int*& zeroArr, int& zeroSize) {
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (staticArr[i] > 0) {
            positiveSize++;
        }
        else if (staticArr[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }

    positiveArr = new int[positiveSize];
    negativeArr = new int[negativeSize];
    zeroArr = new int[zeroSize];

    int posIndex = 0;
    int negIndex = 0;
    int zeroIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (staticArr[i] > 0) {
            positiveArr[posIndex++] = staticArr[i];
        }
        else if (staticArr[i] < 0) {
            negativeArr[negIndex++] = staticArr[i];
        }
        else {
            zeroArr[zeroIndex++] = staticArr[i];
        }
    }
}

int main() {
    srand(time(0));

    int size;
    cout << "Enter size of array A: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20 - 10;
    }

    cout << "Array A: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* positiveArr;
    int positiveSize;
    int* negativeArr;
    int negativeSize;
    int* zeroArr;
    int zeroSize;

    distributeElements(arr, size, positiveArr, positiveSize, negativeArr, negativeSize, zeroArr, zeroSize);

    cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; ++i) {
        cout << positiveArr[i] << " ";
    }
    cout << endl;

    cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; ++i) {
        cout << negativeArr[i] << " ";
    }
    cout << endl;

    cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; ++i) {
        cout << zeroArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;

    return 0;
}
