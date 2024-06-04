#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct queue{
    int arr[max];
    int front;
    int rear;
} queue;

void insert(queue *, int);
void remove(queue *);
void display(queue);

int main(){
    queue q;
    q.front = q.rear = -1;
    int ch, n;
    int flag = 1;
    while(flag){
        printf("Enter choice: \n");
        printf("1. Enqueue\n");
        printf("2. Dqueue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter value to enqueue: \n");
                    scanf("%d", &n);
                    insert(&q, n);
                    break;
            case 2: remove(&q);
                    break;
            case 3: display(q);
                    break;
            case 4: flag = 0;
                    break;
            default: printf("Invalid choice... \n");
        }
    }
    return 0;
}

void insert(queue *t, int val){
    if(t->rear == max - 1){
        printf("Queue is full...\n");
    }
    else{
        t->rear += 1;
        t->arr[t->rear] = val;
        printf("Value added : %d\n", val);
    }
    printf("Top is at %d\n", t->rear);
}

void remove(queue *t){
    if(t->rear == t->front){
        printf("Queue is empty...\n");
    }
    else{
        int x = t->arr[t->front + 1];
        printf("Value removed : %d\n", x);
        t->front++;
    }
    printf("Top is at %d\n", t->rear);
}

void display(queue t){
    if(t.rear == t.front){
        printf("Queue is empty...\n");
    }
    else{
        for(int i = t.front + 1; i <= t.rear; i++){
            printf("%d\t", t.arr[i]);
        }
    }
    printf("\n");
}

