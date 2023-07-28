#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

void Push(char a[],int* top,char x){
    a[++(*top)]=x;
}

char Pop(char a[],int* top){
    return a[(*top)--];
}

char* getPostfix(char *a){
    char b[100];char *c=malloc(sizeof(100));int l=-1;int top=-1,k=1;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]<=122&&a[i]>=97)
            *(c+(++l))=a[i];
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
                        *(c+(++l))=b[top--];
                    }
                    Push(b,&top,a[i]);
                }
                else if(a[i]=='$'){
                    while((b[top]=='*'||b[top]=='/'||b[top]=='^')&&top>-1){
                        *(c+(++l))=b[top--];
                    }
                    Push(b,&top,a[i]);
                }
                else if(a[i]=='+'||a[i]=='-'){
                    while((b[top]=='*'||b[top]=='/'||b[top]=='^'||a[i]=='$')&&top>-1){
                        *(c+(++l))=b[top--];
                    }
                    Push(b,&top,a[i]);
                }
                else if(a[i]==')'){
                    while(b[top]!='('&&top>-1){
                        *(c+(++l))=b[top--];
                    }
                    if(b[top]=='('&&top>-1)
                    top--;
                }
            }
        }
    }
    for(int i=top;i>=0;i--){
        *(c+(++l))=b[i];
    }
    c[++l]='\0';
    return c;
}

char* InfixtoPrefix(char *exp){
    strrev(exp);
    brackets(exp);
    exp=getPostfix(exp);
    strrev(exp);
    return exp;
}
int main(){    
    printf("Infix: ");
    char exp[]="a^(b*c)+d/e^f";
    char *expression = exp; 
    printf("%s\n",expression);
    expression=InfixtoPrefix(&expression[0]); 
    printf("Prefix: ");
    printf("%s\n",expression);
    return 0; 
}