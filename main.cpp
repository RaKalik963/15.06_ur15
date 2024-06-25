#include <iostream>
#include <ctime>
using namespace std;

int* remove_negatives(int* arr, int size, int* new_size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            count++;
        }
    }

    *new_size = count;
    int* new_arr = new int[count];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            new_arr[j++] = arr[i];
        }
    }

    return new_arr;
}

int main() {
    srand(time(0));

    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20 - 10;
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int new_size;
    int* new_arr = remove_negatives(arr, size, &new_size);

    cout << "Array without negatives: ";
    for (int i = 0; i < new_size; i++) {
        cout << new_arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] new_arr;

    return 0;
}
