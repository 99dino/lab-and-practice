#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//infix to postfix and validation(single char operand and binary operators)
int power(int x, int y)
{
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
        printf("Stack is empty.\n");return ' ';
    }
    return stack->array[stack->top];
}

void display(struct stack* stack){
    for(int i=0;i<=stack->top;i++){
       printf("%c",stack->array[i]); 
    }printf("\n");
}

int isalphabet(char a){
    return ((a>=65&&a<=90)||(a>=97&&a<=122)?1:0);
}

int isoperator(char a){
    return a=='*'||a=='+'||a=='-'||a=='/'||a=='^';
}

char * postfix_to_infix(char infix[]){
    int max_size=strlen(infix),ind=0;
    char *postfix=(char *)malloc(sizeof(char)*max_size);
    struct stack* operators =stack_create(max_size);
    int left_bracket=0,flag=1,operators_count=0,operands_count=0;;
    for(int i=0;i<max_size;i++){
        if(i>0&&(isalphabet(infix[i])&&isalphabet(infix[i-1])||isoperator(infix[i])&&isoperator(infix[i-1]))){
            printf("Incorrext Infix Expression.(two or more operator or operand)");return 0;
        }
        if(isalphabet(infix[i])){
            postfix[ind++]=infix[i];
            operands_count++;
        }
        else if(infix[i]==')'){
            if(left_bracket==0){
                printf("Incorrect Infix Expression.{wrong parenthesis}");return 0;
            }
            else{
                left_bracket--;
            }
            while(peek(operators)!='('){
                postfix[ind++]=pop(operators);
            }
            pop(operators);
        }
        else if(infix[i]=='('){
            push(operators,infix[i]);
            left_bracket++;
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
            else{
                printf("Incorrect Infix Expression.(invalid operator)");return 0;
            }
            operators_count++;
            push(operators,infix[i]);
        }
    }
    if(left_bracket!=0||operators_count+1!=operands_count){
        printf("Incorrect Infix Expression.{wrong parenthesis or operator and operand count");return 0;
    }
    while(!isempty(operators)){
        postfix[ind++]=pop(operators);
    }
    postfix[ind]='\0';
    return postfix;
}

int main(){
    char infix[100];printf("Enter an INFIX Expression\n-> ");
    scanf("%s",infix);
    char *postfix=postfix_to_infix(infix);
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