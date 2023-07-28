#include<stdio.h>
#include<string.h>

int main(){

    char s[100000],ss[100000]="akad bakad";

    printf("enter a string-> ");
    gets(s);
    
    for(int i=0;s[i]!='\0';){
        //founding the word "akad bakad"
        //strncimp - it compares first n character of two strings 
        //without regards to case
        if(strnicmp(&s[i],ss,strlen(ss))==0){
            for(int j=0;j<strlen(ss);j++){
                printf("%c",s[i+j]);//printing "akad bakad" of the string
            }i+=strlen(ss);//going to the index after "akad bakad"
            printf(" bambe bo");
        }
        else{
            printf("%c",s[i]);
            i++;
        }
    
    }
    return 0;
}