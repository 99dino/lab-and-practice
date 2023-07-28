#include<stdio.h>

int  main(){
	FILE * file1=fopen("optimal.txt","r");
	FILE * file2=fopen("brute.txt","r");
	while(!feof(file1) && !feof(file2)){
		char a,b;
		fscanf(file1,"%c",&a);
		fscanf(file2,"%c",&b);
		if(a!=b){
			printf("%c %c\n",a,b);
			printf("Ans of brute force is not matching with the answer of optimal\n");
			return 0;
		}
	}
	printf("ALL OK\n");
}
