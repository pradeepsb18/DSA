#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 100
char  infix[size];
void push(char value);
int top=-1;
char pop();
int preced(char  symbol);
char post[size];
char stack[size];
void intopost(char infix[]);

void push(char value){
    stack[++top]=value;
}
char pop(){
    return stack[top--];
}
int preced(char symbol){
    int p;
    switch(symbol){
        case '^':p=3;
                break;
        case '*':
        case '/':
        case '%':
                 p=2;
                 break;
        case '+':
        case '-':p=1;
                break;
        default:p=0;
                break;
    }
    return p;
}
void intopost(char infix[]){
    char symbol,temp;
    int j=0;
    for(int i=0;i<strlen(infix);i++){
            symbol=infix[i];
        switch(symbol){
            case '(':push(symbol);
                    break;
            case ')':temp=pop();
                     while(stack[top]!='('){
                           post[j++]=temp;
                           temp=pop();
                           }
                           break;
            case '*':
            case '/':
            case '%':
            case '^':
            case '+':
            case '-':
                while(preced(stack[top])>=preced(symbol)){
                    post[j++]=pop();
                }
                push(symbol);
                break;
            default:post[j++]=symbol;
        }
    }
    while(top>=0){
        post[j++]=pop();
    }

}
int main(){
    printf("enter the infix expression : \n ");
    gets(infix);
    intopost(infix);
    printf("the postfix expression is : %s ",post);
    return 0;
}
