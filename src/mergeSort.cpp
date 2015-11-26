/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-08-12
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

//arr[low, mid) & arr[mid, high) => arr[low, high)
template <typename T>
void merge(T* arr, Rank low, Rank mid, Rank high) {
	int lsize = mid - low;
	T* buf = new T[lsize];
	for (Rank i = 0, j = low; j < mid; i++, j++) {
		buf[i] = arr[j];
	}
	Rank i = 0, j = mid, s = low;
	while (i < lsize && j < high) {
		if (cmp(arr[j], buf[i])) {
			arr[s++] = buf[i++];
		}
		else {
			arr[s++] = arr[j++];
		}
	}
	while (i < lsize) {
		arr[s++] = buf[i++];
	}
	while (j < high) {
		arr[s++] = arr[j++];
	}
	delete[] buf;
}

template <typename T>
void mergeSort(T* arr, Rank low, Rank high) {		//[low, high)
	if (high - low > 1) {
		Rank mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid, high);
		merge(arr, low, mid, high);
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
	mergeSort(arr, 0, N);
	clock_t stop = clock();
	//std::cout << stop-start << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	delete[] arr;
	return 0;
}

template <typename T>
void merge1(T* arr, Rank low, Rank mid, Rank high) {
	int lsize = mid - low, rsize = high - mid;
	T* lbuf = new T[lsize];
	T* rbuf = new T[rsize];
	assert(lbuf != nullptr && rbuf != nullptr);
	Rank i = 0, j = 0, s = low;
	for (int t = 0, n = low; t < lsize; t++, n++) {
		lbuf[t] = arr[n];
	}
	for (int t = 0, n = mid; t < rsize; t++, n++) {
		rbuf[t] = arr[n];
	}
	while (i < lsize && j < rsize) {
		if (cmp(rbuf[j], lbuf[i])) {
			arr[s++] = lbuf[i++];
		}
		else {
			arr[s++] = rbuf[j++];
		}
	}
	while (i < lsize) {
		arr[s++] = lbuf[i++];
	}
	while (j < rsize) {
		arr[s++] = rbuf[j++];
	}
	delete[] lbuf;
	delete[] rbuf;
}
