#include<stdio.h>
int main(){

    char a[100];
    printf("Enter a string-> ");
    scanf("%s",a);
    int i=0;//string is a null terminated character array
    while(a[i]!='\0'){
        i++;
    }
    printf("length of the entered string is %d\n",i);
    return 0;
}