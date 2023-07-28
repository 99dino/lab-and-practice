#include<stdio.h>
#include<string.h>
//Stack is maintained using ARRAY
char Push(char a[],int top,char x){
    a[top]=x;
}

char Pop(char a[],int top){
    return a[top];
    // printf("%c",a[(*top)--]);
}

int main(){
    char s[100];char stack1[50];char stack2[50];
    scanf("%s",s);int top=-1,n=strlen(s);
    for(int i=0;i<strlen(s)/2;i++){
        top++;
        Push(stack1,top,s[i]);Push(stack2,top,s[n-i-1]);
    }
    // for(int i=0;i<n/2;i++){
        
    // }
    n/=2;
    while(n--){
        if(Pop(stack1,top)!=Pop(stack2,top)){
            printf("It is NOT Palindrome.\n");return 0;
        }
    }
    printf("It is Palindrome.\n");
}