#include <iostream>
#include <ctime>
using namespace std;


int* remove_negative(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) >= 0) {
            count++;
        }
    }
    int* new_arr = new int[size];
    int index = 0;
	for (int i = 0; i < size; i++) {
		if (i >= count) {
			new_arr[i] =0;
		}
	}
	cout << "Changed array ";
	for (size_t i = 0; i < size; i++)
	{
		cout << new_arr[i] << " ";
	}
    return new_arr;

}

int main()
{
	srand(time(0));
	int* new_arr = new int;
	int size;
	cout << "enter size of array ";
	cin >> size;
	int* arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 20 - 10;
	}
	cout << "Array ";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	remove_negative(arr, size);
	return 0;
	system("pause");
}