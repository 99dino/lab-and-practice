// #include<stdio.h>

// int main(){
//     char a[100],b[100];
//     printf("Enter a string-> ");
//     gets(a);
//     //reversing into string b
//     char *p=a,*q=b;
//     while(*p!='\0'){
//         p++;
//     }
//     p--;int i=0;//reaching at the end of the string 'a' using pointer
//     while(a[i]!='\0'){
//         i++;
//         *q=*p;
//         q++;p--;
//     }
//     *q='\0';
//     printf("%s",b);
//     return 0;
// }

#include<stdio.h>

int main(){
    char a[100];
    printf("Enter a string-> ");
    gets(a);
    //reversing into string b
    char *p=a,*q=a;
    while(*p!='\0'){
        p++;
    }
    p--;int i=0;
    while(p>q){
        //swapping characters
        char w=*p;
        *p=*q;
        *q=w;
        q++;p--;
    }
    printf("%s",a);
    return 0;
}