/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-07-26
All rights reserved
**********************************/

#include <iostream>
#include <random>
#include <ctime>
#include <cstring>

typedef int Rank;
const Rank N = 10240000;

void countingSort(int* arr, Rank low, Rank high) {
	int* buf = (int*)malloc(sizeof(int) * 4 * N);
	if (buf == nullptr) {
		return;
	}
	memset(buf, 0, sizeof(int) * 4 * N);
	for (int i = low; i < high; i++) {
		buf[arr[i]]++;
	}
	for (int j = 0, i = low; j < 4 * N && i < high; j++) {
		while (buf[j] != 0) {
			arr[i] = j;
			buf[j]--;
			i++;
		}
	}
	free(buf);
}

int main(int argc, char** argv) {
	int *arr = new int[N];
	std::uniform_int_distribution<int> s(0, 4 * N);
	std::default_random_engine e(time(nullptr));
	for (int i = 0; i < N; i++) {
		arr[i] = s(e);
	}

	clock_t start = clock();
	countingSort(arr, 0, N);
	clock_t stop = clock();
	//std::cout << stop-start << std::endl;
	
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	delete[] arr;
	return 0;
}