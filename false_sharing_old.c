#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void *worker_thread(void *arg)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	long* counter_to_inc = (long*)arg;

	int i;
	for(i = 0; i < 1000000000; i++){
		(*counter_to_inc)++;
		//printf("counter = %ld\n",*counter_to_inc);
	}
	printf("counter = %ld\n",*counter_to_inc);

	gettimeofday(&stop, NULL);
	printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

	pthread_exit(NULL);
}


struct Counter{
	long count1;
	long count2;
	};


int main(int argc, char *argv[])
{
	struct Counter counter1 __attribute__((aligned(64))), counter2 __attribute__((aligned(64))); //counter1 and counter2 will be on different cache lines if 64B aligned.
	struct Counter *counter1_p, *counter2_p;
	counter1.count1 = 0;
	counter1.count2 = 1;

	counter2.count1 = 2;
	counter2.count2 = 3;

	counter1_p = &counter1;
	//counter2_p = &counter2;
	counter2_p = &counter1; //Both point to counter1

	printf("counter1_p: %p, counter2_p: %p\n",counter1_p,counter2_p); //print address of counter1 and counter2
	
	pthread_t thread1;
	pthread_t thread2;
	int ret1;
	int ret2;

	printf("In main: creating thread\n");

	ret1 =  pthread_create(&thread1, NULL, &worker_thread, (void*)&counter1_p->count1); //both threads are writing to the same cache line but different bytes,
	ret2 =  pthread_create(&thread2, NULL, &worker_thread, (void*)&counter2_p->count2); //thus causing false sharing


	if(ret1 != 0) {

		printf("Error: pthread_create() failed for thread 1\n");
		exit(EXIT_FAILURE);
	}

	if(ret2 != 0) {

		printf("Error: pthread_create() failed for thread 2\n");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

}