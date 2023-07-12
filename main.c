#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int A = 0;

void* thread_calc(void* args) {
	
	int* ptr = (int*)args;
	
	for (; *ptr < 100; *ptr += 1) {
		A++;
		printf("%d\n", A);
	}
	
	return NULL;

}

int main() {

	pthread_t thread[1000];
	int* index = (int*)calloc( 1000, sizeof(int));
	int* s;


	for (int i = 0; i < 1000; i++) {
		index[i] = 0;
		pthread_create(&thread[i], NULL, thread_calc, (void*)&index[i]);
	}
	for (int i = 0; i < 1000; i++) {
		pthread_join(thread[i], (void**)&s);
	}
	printf("|| %d ||\n", A);

	return 0;
}