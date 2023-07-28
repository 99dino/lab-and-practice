#include<stdio.h>

int main(){
    char a[100];
    printf("Enter a string-> ");
    gets(a);
    int i=0,v=0,c=0,d=0,s=0;
    while(a[i]!='\0'){
        if(a[i]=='a'||a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='i'||a[i]=='I'){v++;}
        else if(a[i]=='o'||a[i]=='O'||a[i]=='u'||a[i]=='U'){v++;}
        else if((a[i]<=90&&a[i]>=65)||(a[i]<=122&&a[i]>=97)){c++;}
        else if(a[i]>=48&&a[i]<=57){d++;}
        else{s++;}
        i++;
    }
    printf("NO of vowels = %d and consonants = %d\n",v,c);
    printf("NO of digits = %d\n",d);
    printf("NO of special character = %d\n",s);
    return 0;
}