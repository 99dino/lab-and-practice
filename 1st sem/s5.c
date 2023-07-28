#include<stdio.h>
int main(){
    char a[100],b[100],c[100];
    printf("Enter string 1-> ");
    gets(a);
    printf("Enter string 2-> ");
    gets(b);
    char *x=a,*y=b,*z=c;
    while(*x!='\0'){
        *z=*x;//copying string 'a' into 'c'
        x++;z++;
    }
    while(*y!='\0'){
        *z=*y;//concatenating string 'b' in string 'c'
        y++;z++;
    }
    *z='\0';//making string 'c', a valid string, ending with null charcater
    puts(c);

    return 0;
}