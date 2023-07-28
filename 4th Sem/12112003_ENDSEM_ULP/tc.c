#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	time_t t;
	srand((int) time(&t));
	printf("%d %d %d\n",(rand()%10),(rand()%10),(rand()%10));
}
