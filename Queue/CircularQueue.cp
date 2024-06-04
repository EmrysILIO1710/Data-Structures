#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct cqueue{
    int arr[max];
    int front;
    int rear;
} cqueue;

void insert(cqueue *, int);
void remove(cqueue *);
void display(cqueue);

int main(){
    int ch, n, flag;
    cqueue cq;
    cq.front = cq.rear = 0;
    flag = 1;
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
                    insert(&cq, n);
                    break;
            case 2: remove(&cq);
                    break;
            case 3: display(cq);
                    break;
            case 4: flag = 0;
                    break;
            default: printf("Invalid choice... \n");
        }
    }
    return 0;
}

void insert(cqueue *t, int val){
    if((t->rear + 1) % max == t->front){
        printf("Queue is full...\n");
    }
    else{
        t->arr[t->rear] = val;
        printf("%d added at %d\n", val, t->rear);
        t->rear = (t->rear + 1) % max;
    }
}

void remove(cqueue *t){
    if(t->rear == t->front){
        printf("Queue is empty...\n");
    }
    else{
        printf("%d deleted from queue\n", t->arr[t->front]);
        t->front = (t->front + 1) % max;
    }
}

void display(cqueue t){
    if(t.rear == t.front){
        printf("Queue is empty...\n");
    }
    else{
        for(int i = t.front; i != t.rear; i = (i + 1) % max){
            printf("%d\t", t.arr[i]);
        }
        printf("\n");
    }
}
