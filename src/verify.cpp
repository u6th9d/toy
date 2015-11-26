/**********************************
Author: u6th9d
E-mail: u6th9d@outlook.com
Copyright (c) 2015-08-10
All rights reserved
**********************************/

#include <iostream>

template <typename T>
bool cmp(T& a, T& b) {
	return (a > b);
}

bool verify() {
	int i, j;
	std::cin >> i;
	while(std::cin >> j) {
		if(cmp(i, j)) {
			return false;
		}
		else {
			i = j;
		}
	}
	return true;
}

// ./sort | ./verify 
int main() {
	bool b = verify();
	if(b) {
		std::cout << "True" << std::endl;
	}else {
		std::cout << "False" << std::endl;
	}
	
	return 0;
}

