#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;

void print_matrix(int **nums, int matrix_size) {

	for (int i = 0; i < matrix_size; ++i, cout << endl) {
		for (int j = 0; j < matrix_size; ++j) {
			cout << nums[i][j] << "\t";
		}
	}
}

int main()
{
	srand(time(NULL));

	int counter = 0;
	int matrix_size;

	cout << "Choose array size(1-4): " << endl;
	cout <<"1. 10x10\n"
		<< "2. 50x50\n"
		<< "3. 100x100\n"
		<< "4. 500x500\n";

	cin >> matrix_size;
	
	if (matrix_size < 0 || matrix_size > 4) {
		cout << "Wrong value. Error";
		return 1;
	}

	switch (matrix_size)
	{
	case 1: matrix_size = 10; break;
	case 2: matrix_size = 50; break;
	case 3: matrix_size = 100; break;
	case 4: matrix_size = 500; break;
	}

	// Виділення пам'яті
	int** nums = new int* [matrix_size];

	for (int i = 0; i < matrix_size; ++i) {
		nums[i] = new int[matrix_size];
	}

	auto start = chrono::high_resolution_clock::now();

	// Заповнення матриці випадковими числами
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			nums[i][j] = rand() % 100;
		}
	}

	// Виведення початкової матриці
	cout << "Original matrix:" << endl;
	print_matrix(nums, matrix_size);

	cout << endl;

	// Транспонування верхнього трикутника матриці
	for (int i = 0; i < (matrix_size - 1) / 2; i++) {
		for (int j = i + 1; j < matrix_size - i - 1; j++) {
			swap(nums[i][j], nums[j][i]);
			counter++;
		}
	}

	// Виведення зміненої матриці
	cout << "After swapping:" << endl;
	print_matrix(nums, matrix_size);

	// Звільнення пам'яті
	for (int i = 0; i < matrix_size; ++i) {
		delete[] nums[i];
	}
	delete[] nums;

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;

	cout << "Execution time: " << duration.count() << " seconds" << endl;
	cout << "Total iterations: " << counter << endl;

	return 0;
}