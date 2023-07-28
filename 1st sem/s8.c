#include<stdio.h>
#include<string.h>
int main(){

    char a[100],b[100];
    printf("Enter string 1-> ");
    gets(a);
    printf("Enter string 2-> ");
    gets(b);
    strcat(a,b);
    puts(a);
    return 0;
}