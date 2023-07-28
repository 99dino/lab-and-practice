#include<stdio.h>

int main(){

    char a[100];
    printf("enter a string-> ");
    gets(a);
    int i=0,c=0;
    while(a[i]!='\0'){
        if(a[i]=='A'){
            c++;
        }
        i++;
    }
    printf("no of times 'A' appears in the given string is %d",c);
    return 0;
}