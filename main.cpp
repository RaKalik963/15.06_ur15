#include <iostream>
#include <ctime>
using namespace std;



void sum_product(int* arr, int size, int* sum, int* product) {
	*sum = 0;
	*product = 1;
	for (int i = 0; i < size; i++) {
		*sum += *(arr + i);
		*product *= *(arr + i);
	}
	cout << "sum = " << *sum << endl;
	cout << "product = " <<* product << endl;
}
int main()
{
	srand(time(0));
	int* sum = new int;
	int* product = new int;
	int size;
	cout << "enter size of array ";
	cin >> size;
	int* arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
	cout << "Array ";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	sum_product(arr, size, sum, product);
	return 0;
	system("pause");
}