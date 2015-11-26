/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-07-26
All rights reserved
**********************************/

#include <iostream>
#include <random>
#include <ctime>

#define LCR(i) ((i)*2+1)				//rank: left child
#define RCR(i) (((i)+1)*2)				//rank: right child
#define PAR(i) (((i)%2)?(((i)-1)/2):((i)/2-1))		//rank: parent

typedef int Rank;
const Rank N = 10240000;

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
Rank max_in_3(T* arr, Rank p, Rank end) {
	Rank l = LCR(p), r = RCR(p);
	if (r < end) {
		return arr[p] >= arr[l] ? (arr[p] >= arr[r] ? p : r) : (arr[l] >= arr[r] ? l : r);
	}
	else if (l < end) {
		return arr[p] >= arr[l] ? p : l;
	}
	else {
		return p;
	}
}

template <typename T>
Rank refresh_up(T* arr, Rank r) {
	Rank i = r;
	while (i != 0) {
		Rank p = PAR(i);
		if (arr[i] > arr[p]) {
			swap(arr[i], arr[p]);
			i = p;
		}
		else {
			break;
		}
	}
	return i;
}

template <typename T>
Rank refresh_down(T* arr, Rank r, Rank end) {
	Rank i = r, j;
	while (i != (j = max_in_3(arr, i, end))) {
		swap(arr[i], arr[j]);
		i = j;
	}
	return i;
}

template <typename T>
void compile_heap1(T* arr, Rank low, Rank high) {	//O(nlogn)
	for (Rank i = low + 1; i < high; i++) {
		refresh_up(arr, i);
	}
}

template <typename T>
void compile_heap2(T* arr, Rank low, Rank high) {	//O(n)
	for (Rank i = high / 2 - 1; i >= low; i--) {
		refresh_down(arr, i, high);
	}
}

template <typename T>
void heapSort(T* arr, Rank low, Rank high) {		//[low, high)
	arr += low, high -= low, low = 0;
	compile_heap2(arr, low, high);

	for (Rank i = high - 1; i > low; i--) {
		swap(arr[i], arr[low]);
		refresh_down(arr, low, i);
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
	heapSort(arr, 0, N);
	clock_t stop = clock();
	std::cout << stop-start << std::endl;

	// for (int i = 0; i < N; i++) {
		// std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	delete[] arr;
	return 0;
}