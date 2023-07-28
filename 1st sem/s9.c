#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[100];
    printf("Enter string 1-> ");
    gets(a);
    printf("Enter string 2-> ");
    gets(b);
    strcat(b,a);
    strcpy(a,b);
    puts(a);
    return 0;
}
// char *p=a,*q=b,*n=a;
    // while(*p!='\0'){
    //     p++;n++;
    // }
    // while(*q!='\0'){
    //     p++;q++;
    // }q--;
    // int i=0;
    // while(a[i]!='\0'){
    //     *p=*n;
    //     i++;
    //     p--;n--;
    // }
    // *p=*n;p--;i=0;
    // while(b[i]!='\0'){
    //     i++;
    //     *p=*q;
    //     p--;q--;
    // }
// 1 2 3 4 5 \0