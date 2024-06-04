#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct node{
    int data;
    struct node* next;
} node;

node *end = NULL;

typedef struct stack{
    int top;
    node* start;
} stack;

void push(stack *, int);
// void pop(stack *);
// void print(stack *);

int main(){
    stack s;
    s.top = 0;
    s.start = NULL;
    int ch, n, flag;
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
            // case 2: pop(&s);
            //         break;
            // case 3: print(&s);
            //         break;
            case 4: flag = 0;
                    break;
            default: printf("Invalid choice... \n");
        }
    }
    return 0;
}

void push(stack *s, int val){
    if(s->top == max){
        printf("\nStack is full...");
    }
    else{
        node *newptr = (node *)malloc(sizeof(node));
        if(s->start == NULL){
            newptr->data = val;
            newptr->next = NULL;
            s->start = newptr;
            end = s->start;
        }
        else{
            newptr->data = val;
            newptr->next = end;
            end = newptr;
        }
        s->top++;
    }
}