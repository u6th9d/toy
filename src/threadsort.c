#include <pthread.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000l
#define THREADS 4

static long int num[N];
static long int snum[N];
pthread_barrier_t b;

int cmp(const void* a, const void* b) {
	return (*(long int*)(a) - *(long int*)(b));
}

void* task(void* args) {
	int i = (int)args;
	qsort(num + i * N / THREADS, N / THREADS, sizeof(long int), &cmp);
	pthread_barrier_wait(&b);
	return NULL;
}

void merge() {
	long int index[THREADS];
	long int r, min, rmin;
	for(int i = 0; i < THREADS; i++) {
		index[i] = N / THREADS * i;
	}
	for(long int i = 0; i < N; i++) {
		min = LONG_MAX;
		for(int j = 0; j < THREADS; j++) {
			if((index[j] < N / THREADS * (j + 1)) && (num[index[j]] < min)) {
				min = num[index[j]];
				rmin = j;
			}
		}
		snum[i] = num[index[rmin]];
		index[rmin]++;
	}

}

void test() {
	pthread_t tid;
	pthread_barrier_init(&b, NULL, THREADS + 1);
	for(long int i = 0; i < THREADS; i++) {
		pthread_create(&tid, NULL, task, (void*)(i));
	}
	pthread_barrier_wait(&b);
	merge();
}

int main() {
	srandom(time(NULL));
	for(long int i = 0; i < N; i++) {
		num[i] = random();
	}
	test();
	for(long int i = 0; i < N; i++) {
		printf("%ld\n", snum[i]);
	}
}
