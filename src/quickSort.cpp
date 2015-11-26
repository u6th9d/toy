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
const Rank N = 10240000;

template <typename T>
bool cmp(T& a, T& b) {
	return (a > b);
}

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
Rank partition1(T* arr, Rank low, Rank high) {	//[low, high)
	Rank i = low, j = high - 1;
	T tmp = arr[i];
	while (i < j) {
		while (i < j) {
			if (cmp(arr[j], tmp)) {
				j--;
			}
			else {
				arr[i++] = arr[j];
				break;
			}
		}
		while (i < j) {
			if (cmp(arr[i], tmp)) {
				arr[j--] = arr[i];
				break;
			}
			else {
				i++;
			}
		}
	}
	arr[i] = tmp;
	return i;
}

template <typename T>
Rank partition2(T* arr, Rank low, Rank high) {	//[low, high)
	Rank mid = low;
	for (Rank i = low + 1; i < high; i++) {
		if (cmp(arr[low], arr[i])) {
			swap(arr[++mid], arr[i]);
		}
	}
	swap(arr[low], arr[mid]);
	return mid;
}

template <typename T>
void quickSort(T* arr, Rank low, Rank high) {		//[low, high)
	if (high - low <= 1) {
		return;
	}
	Rank mid = partition2(arr, low, high);
	quickSort(arr, low, mid);
	quickSort(arr, mid + 1, high);
}

int main(int argc, char** argv) {
	int *arr = new int[N];
	std::uniform_int_distribution<int> s(0 - 2 * N, 2 * N);
	std::default_random_engine e(time(nullptr));
	for (int i = 0; i < N; i++) {
		arr[i] = s(e);
	}

	clock_t start = clock();
	quickSort(arr, 0, N);
	clock_t stop = clock();
	std::cout << stop-start << std::endl;
	
	// for (int i = 0; i < N; i++) {
		// std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	delete[] arr;
	return 0;
}