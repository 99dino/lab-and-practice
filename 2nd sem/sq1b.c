#include<stdio.h>
//Stack is maintained using ARRAY
void Push(char a[],int* top,char x){
    a[++(*top)]=x;
}

void Pop(char a[],int* top){
    printf("%c",a[(*top)--]);
}

int main(){
    char a[100];char b[100];int top=-1,k=1;
    printf("Write a Infix Expression (Operands should be in CAPITAL, Operator should be valid.\n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]<=90&&a[i]>=65)
            printf("%c",a[i]);
        else{
            if(k){
                k=0;
                Push(b,&top,a[i]);
            }
            else{
                if(a[i]=='^'||a[i]=='('){
                    Push(b,&top,a[i]);
                }
                else if(a[i]=='*'||a[i]=='/'){
                    while(b[top]=='^'&&top>-1){
                        Pop(b,&top);
                    }
                    Push(b,&top,a[i]);
                }
                else if(a[i]=='+'||a[i]=='-'){
                    while((b[top]=='*'||b[top]=='/'||b[top]=='^')&&top>-1){
                        Pop(b,&top);
                    }
                    Push(b,&top,a[i]);
                }
                else if(a[i]==')'){
                    while(b[top]!='('&&top>-1){
                        Pop(b,&top);
                    }
                    if(b[top]=='('&&top>-1)
                    top--;
                }
            }
        }
    }
    for(int i=top;i>=0;i--){
        Pop(b,&top);
    }
}