/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-07-26
All rights reserved
**********************************/

/*Find the Kth large numbers*/

#include <iostream>

template<typename T>
int cmp(T& a, T& b) {
	return (a>b);
}

template<typename T>
T find(T* arr, int width, int (*pfunc)(T& a, T& b), int k) {		//O(n) or O(nlgn) ?
	int i = 0, j = width-1;
	T tmp = arr[0];
	if(k<1){
		k = 1;
	}else if(k>width){
		k = width;
	}
	while(i < j) {
		while(i<j && pfunc(tmp, arr[j])) {
			j--;
		}
		if(i < j){
			arr[i] = arr[j];
			i++;
		}
		while(i<j && !pfunc(tmp, arr[i])) {
			i++;
		}
		if(i < j){
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = tmp;
	
	if(i > k-1) {
		find(arr, i, pfunc, k);
	}
	else if(i < k-1) {
		find(arr+i+1, width-i-1, pfunc, k-i-1);
	}
	else{
		return arr[i];
	}
}

int main(int argc, char** argv){
	int array[] = {/*Complete*/};
	int ans = find(array, sizeof(array)/sizeof(int), cmp, /*Complete*/);
	
	printf("%d\n", ans);

	return 0;
}
