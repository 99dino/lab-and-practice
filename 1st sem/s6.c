#include<stdio.h>
int main(){

    char a[100];
    printf("Enter a string-> ");
    gets(a);
    int i=0,c=0;
    while(a[i]!='\0'){
        if(a[i]<=90&&a[i]>=65){c++;}i++;
    }
    printf("No. of uppercase letters in the given string is %d",c);
    return 0;
}