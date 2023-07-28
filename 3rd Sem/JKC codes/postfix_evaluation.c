// postfix evaluation (single digit operand and binary operator)
// (no validation) 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int power(int x, int y){
    int res = 1;
    for(int i=0;i<y;i++){
        res=res*x;
    }
    return res;
}
struct stack{
    int size;
    float *array;
    int top;
};

struct stack* stack_create(int size){
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->array=(float *)malloc((size)*sizeof(float));
    return stack;
}

int isfull(struct stack* stack){
    return (stack->size==stack->top+1?1:0);
}

int isempty(struct stack* stack){
    return (stack->top==-1?1:0);
}

void push(struct stack* stack,float data){
    if(isfull(stack)){
        printf("Stack is full.\n");return;
    }
    stack->array[++stack->top]=data;
}

float pop(struct stack* stack){
    if(isempty(stack)){
        printf("Stack is already empty.\n");return ' '; 
    }
    return stack->array[stack->top--];
}

float result(struct stack* stack){
    if(isempty(stack)){
        printf("Stack is empty.\n");return ' ';
    }
    return stack->array[stack->top];
}

float postfix_evaluation(char postfix[]){
    int max_size=strlen(postfix);
    struct stack* infix=stack_create(max_size);
    for(int i=0;i<max_size;i++){
        if(postfix[i]<=57&&postfix[i]>=48){
            push(infix,(int)(postfix[i]-48));
        }
        else{
            float b=pop(infix);
            float a=pop(infix);
            float result;
            switch (postfix[i]){
                case '*':
                    result=a*b;
                    break;
                case '/':
                    result=a/b;
                    break;
                case '+':
                    result=a+b;
                    break;
                case '-':
                    result=a-b;
                    break;
                case '^':
                    result=power(a,b);
                    break;
                default:
                    printf("Invalid expression.");return 0;
            }
            push(infix,result);
        }
    }
    return result(infix);
}

int main(){
    char postfix[100];
    printf("Enter a Postifx EXpression\n(Operators should be binary and Operands having single digit)\n-> ");
    scanf("%s",postfix);
    float value=postfix_evaluation(postfix);
    printf("Evaluated Postfix Value: %f\n",value);
}
// some sample test case
// 231*+9-
// 234^-6+
// 84/
// 48-9*4*
// 5678--*
// 3721^^+5+
// 93+0*
// 9