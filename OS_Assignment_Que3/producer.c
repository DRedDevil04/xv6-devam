#include "problem.h"

void producer(int w)
{
	int i=0,n;
	MEM *S = memory();

	while(1)
	{
		i++;
		sem_wait(&S->empty); // Semaphore down operation
		sem_wait(&S->mutex);
		sem_getvalue(&S->full,&n);
		(S->buff)[n] = i; // Place value to BUFFER
		printf("[PRODUCER %d ] Placed item [%d]\n",w, i);
		sem_post(&S->mutex);
		sem_post(&S->full); // Semaphore up operation
		sleep(PRODUCER_SLEEP_SEC);

	}
}

int main(int argc,char *argv[])
{
	init();
	producer(argv[1][0]-'0');
	return 0;
}
