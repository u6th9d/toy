/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-07-26
All rights reserved
**********************************/

#include <iostream>
#include <random>
#include <ctime>

typedef int Rank;
const Rank N = 102400;

template <typename T>
bool cmp(T& a, T& b) {
	return (a > b);
}

template <typename T>
void insertionSort(T* arr, Rank low, Rank high) {		//[low, high)
	Rank i, j;
	for (i = low + 1; i < high; i++) {
		T tmp = arr[i];
		for (j = i - 1; j >= low; j--) {
			if (cmp(arr[j], tmp)) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = tmp;
	}
}

int main(int argc, char** argv) {
	int *arr = new int[N];
	std::uniform_int_distribution<int> s(0 - 2 * N, 2 * N);
	std::default_random_engine e(time(nullptr));
	for (int i = 0; i < N; i++) {
		arr[i] = s(e);
	}

	clock_t start = clock();
	insertionSort(arr, 0, N);
	clock_t stop = clock();
	//std::cout << stop-start << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	delete[] arr;
	return 0;
}