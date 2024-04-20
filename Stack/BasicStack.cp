#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct myStack{
    int a[max];
    int top;
} stack;

void push(stack *, int);
void pop(stack *);
void display(stack);
int main(){
    int ch, n, flag;
    stack s;
    s.top = -1;
    flag = 1;
    while(flag){
        printf("Enter choice: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter value to push: \n");
                    scanf("%d", &n);
                    push(&s, n);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(s);
                    break;
            case 4: flag = 0;
                    break;
            default: printf("Invalid choice... \n");
        }
    }
    return 0;
}

void push(stack *p, int val){
    if(p->top == max - 1){
        printf("Stack is full...\n"); //overflow
    }
    else{
        p->top++;
        p->a[p->top] = val;
        printf("Value added : %d\n", val);
    }
    printf("Top is at %d\n", p->top);
}

void pop(stack *p){
    if(p->top == -1){
        printf("Stack is empty...\n"); //underflow
    }
    else{
        int x = p->a[p->top];
        printf("Value removed : %d\n", x);
        p->top--;
    }
    printf("Top is at %d\n", p->top);
}

void display(stack p){
    if(p.top == -1){
        printf("Stack is empty...\n"); //empty stack
    }
    else{
        for(int i = 0; i <= p.top; i++){
            printf("%d\t", p.a[i]);
        }
    }
    printf("\nTop is at %d\n", p.top);
}