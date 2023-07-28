#include<semaphore.h>
//#include<sys/sem.h>
#include<stdio.h>
#include<pthread.h>

sem_t m;
pthread_mutex_t mutex;

void* producer(int* data){
	sem_wait(&m);
	pthread_mutex_lock(&mutex);
	int a=*data;
	a=a+1;
	*data=a;
	printf("producer : %d\n",*data);
	pthread_mutex_unlock(&mutex);
	sem_post(&m);
}

void* consumer(int* data){
	sem_wait(&m);
	pthread_mutex_lock(&mutex);
	int b=*data;
	b=b-1;
	*data=b;
	printf("consumer : %d\n",*data);
	pthread_mutex_unlock(&mutex);
	sem_post(&m);
}


int main(){
	pthread_t pro,con;
	pthread_mutex_init(&mutex,NULL);
	sem_init(&m,0,1);
	int data=5;
	
	//pthread_attr_t attr;
	//pthread_attr_init(&attr);
	//pthread_attr_setscope (&attr, PTHREAD_SCOPE_SYSTEM);
	pthread_create(&con,NULL,(void *)consumer,&data);
	pthread_create(&pro,NULL,(void *)producer,&data);
	
	
	pthread_join(con,NULL);
	pthread_join(pro,NULL);
	
	pthread_mutex_destroy(&mutex);
	
	sem_destroy(&m);
	
	return 0;
}
