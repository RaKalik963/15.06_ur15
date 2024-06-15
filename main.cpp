#include <iostream>
#include <ctime>
using namespace std;


int* removeNegative(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) >= 0) {
            count++;
        }
    }
    int* newArr = new int[count];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) >= 0) {
            *(newArr + index) = *(arr + i);
            index++;
        }
    }
    return newArr;

}

int main()
{

	return 0;
	system("pause");
}