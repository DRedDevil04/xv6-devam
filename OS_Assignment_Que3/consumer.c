#include "problem.h"

void consumer(int i)
{
	int n;
	MEM *S = memory();

	while(1)
	{

		sem_wait(&S->full); // Semaphore down operation
		sem_wait(&S->mutex); // Semaphore for mutual exclusion
		sem_getvalue(&S->full,&n); // Assign value of semphore full, to integer n
		printf("[CONSUMER %d ] Removed item [%d]\n",i, (S->buff)[n]);
		sem_post(&S->mutex); // Mutex up operation
		sem_post(&S->empty); // Semaphore up operation
		sleep(CONSUMER_SLEEP_SEC);

	}
}

int main(int argc,char *argv[])
{
	consumer(argv[1]-"0");
	return 0;
}
