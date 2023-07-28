#include<stdio.h>
#include<string.h>

int main(){
    char a[1000000];
    int l=0,u=0,n=0,s=0;
    printf("enter a string-> ");
    gets(a);
    while(strlen(a)<=8){
        printf("String is smaller than 8 characters, Kindly re-enter the string\n");
        gets(a);
    }
    for(int i=0;a[i]!='\0';i++){
        if(a[i]<=90&&a[i]>=65){u++;}//upper case 65-90
        else if(a[i]<=122&&a[i]>=97){l++;}//lower case 97-122
        else if(a[i]<=57&&a[i]>=48){n++;}//digits 48-57
        else{s++;}//rest are special character
    }
    if(l>0&&u>0&&n>0&&s>0){
        printf("true\n");
    }
    else{
        printf("false\n");
        if(!l){printf("small letter alphabet is missing\n");}
        if(!u){printf("capital letter alphabet is missing\n");}
        if(!n){printf("number is missing\n");}
        if(!s){printf("special charcater is missing\n");}
        //space is a special charcater.......😂🤣
    }

    return 0;
}