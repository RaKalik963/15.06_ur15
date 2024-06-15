#include <iostream>
#include <ctime>
using namespace std;


void count_pos_neg_zero(int* arr, int size, int* positive, int* negative, int* zero) {
	*positive = 0;
	*negative = 0;
	*zero = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) > 0) 
		{
			(*positive)+= 1;
		}
		if (*(arr + i) < 0) 
		{
			(*negative)+= 1;
		}
		if (*(arr + i) == 0)
		{
			(*zero)+= 1;
		}
	}
	cout << "positive = " << *positive << endl;
	cout << "negative = " << *negative << endl;
	cout << "zero = " << *zero << endl;

}
void sum_product(int* arr, int size, int *negative) {

}
int main()
{
	srand(time(0));
	int* positive = new int;
	int* negative = new int;
	int* zero = new int;
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
	count_pos_neg_zero(arr, size, negative, positive, zero);

	delete positive;
	delete negative;
	delete zero;
	return 0;
	system("pause");
}