#include<stdio.h>

//Stack is maintained using ARRAY
void Push(char a[],int* top,char x){
    a[++(*top)]=x;
}

int main(){
    char stack[100];int top=-1;
    char s[100];printf("Enter a Expression -> ");scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            Push(stack,&top,s[i]);
        }
        else if(s[i]==')'){
            if(top>-1&&stack[top]=='(')
                top--;
            else if(stack[top]!='(')
                Push(stack,&top,s[i]);
        }
    }
    if(top!=-1)
        printf("Given EXPRESSION is NOT correctly PARENTHESIZED.\n");
    else
        printf("Yes,It is is Correctly Paraenthesized.\n");
}