#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//infix to postfix(single char operand and binary operators)
int power(int x, int y){
    int res = 1;
    for(int i=0;i<y;i++){
        res=res*x;
    }
    return res;
}

struct stack{
    int size;
    char *array;
    int top;
};

struct stack* stack_create(int size){
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->array=(char *)malloc((size)*sizeof(char));
    return stack;
}

int isfull(struct stack* stack){
    return (stack->size==stack->top+1?1:0);
}

int isempty(struct stack* stack){
    return (stack->top==-1?1:0);
}

void push(struct stack* stack,char data){
    if(isfull(stack)){
        printf("Stack is full.\n");return;
    }
    stack->array[++stack->top]=data;
}

char pop(struct stack* stack){
    if(isempty(stack)){
        printf("Stack is already empty.\n");return ' '; 
    }
    return stack->array[stack->top--];
}

char peek(struct stack* stack){
    if(isempty(stack)){
        printf("Stack is already empty.\n");return ' ';
    }
    return stack->array[stack->top];
}

int isalphabet(char a){
    return ((a>=65&&a<=90)||(a>=97&&a<=122)?1:0);
}

char * infix_to_postfix(char infix[]){
    int max_size=strlen(infix),ind=0;

    char *postfix=(char *)malloc(sizeof(char)*max_size);
    
    struct stack* operators =stack_create(max_size);
    
    int left_bracket=0,flag=1,operators_count=0,operands_count=0;;
    
    for(int i=0;i<max_size;i++){

        if(isalphabet(infix[i])){
            postfix[ind++]=infix[i];
        }
        else if(infix[i]=='('){
            push(operators,infix[i]);
        }
        else if(infix[i]==')'){
            while(!isempty(operators)&&peek(operators)!='('){
                postfix[ind++]=pop(operators);
            }
            pop(operators);
        }
        else{
            if(infix[i]=='^'){
                while(!isempty(operators)&&(peek(operators)=='^')){
                    postfix[ind++]=pop(operators);
                }
            }
            else if(infix[i]=='*'||infix[i]=='/'){
                while(!isempty(operators)&&(peek(operators)=='^'||peek(operators)=='*'||peek(operators)=='/')){
                    postfix[ind++]=pop(operators);
                }
            }
            else if(infix[i]=='+'||infix[i]=='-'){
                while(!isempty(operators)&&peek(operators)!='('){
                    postfix[ind++]=pop(operators);
                }
            }
            push(operators,infix[i]);
        }
    }
    while(!isempty(operators)){
        postfix[ind++]=pop(operators);
    }
    postfix[ind]='\0';
    return postfix;
}

int main(){
    char infix[100];
    printf("Enter an INFIX Expression\n-> ");
    scanf("%s",infix);
    // printf("%s",infix);
    char *postfix=infix_to_postfix(infix);
    printf("%s",postfix);
}
// some test cases

// a+b*c+d
// ((A+B)–C*(D/E))+F
// a+b*(c^d-e)^(f+g*h)-i
// a+b*c-(d/e+f*g*h)
// A*(B-(C+D))^F/G (6 operands, 5 operators )
// A+B
// A+B*C^D-E-F-G/H/J*K*L+M (12 operands, 11 operators )
// A*(B+C)/(D-(E-F^G-H)) (8 operands, 7 operators )
// (a-b-(c^d))/((e^(f*g-h))) (8 operands, 7 operators )
// ()
// A*((B-C/(D*(E+F))^G)
