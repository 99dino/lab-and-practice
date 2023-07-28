#include<stdio.h>

int main(){

    char a[100],b[100];
    printf("Enter a string-> ");
    gets(b);

    char *p=a,*q=b;int i=0;
    while(b[i]!='\0'){
        *p=*q;
        p++;q++;
        i++;
    }
    *p='\0';
    printf("copied string is '%s'",a);
    return 0;
}