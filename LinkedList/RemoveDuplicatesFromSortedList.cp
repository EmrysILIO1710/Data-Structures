//https://www.codechef.com/practice/course/linked-lists/LINKLISTF/problems/PREP55?tab=statement

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *start = NULL;
node *tail = NULL;

void createList(int);
void removeDuplicates();
void print();

int main(void) {
	// your code goes here
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        while(n--){
            scanf("%d", &x);
            createList(x);
        }
        removeDuplicates();
        print();
        printf("\n");
        start = NULL;
    }
}

void createList(int num){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL){
        newptr->data = num;
        newptr->next = NULL;
        start = newptr;
        tail = start;
    }
    else{
        // node *ptr = start;
        // while(ptr->next != NULL){
        //     ptr = ptr->next;
        // }
        tail->next = newptr;
        newptr->data = num;
        newptr->next = NULL;
        tail = newptr;
    }
}

void removeDuplicates(){
    node *ptr = start;
    node *ptr2 = start->next;
    while(ptr2 != NULL){
        if(ptr->data == ptr2->data){
            ptr->next = ptr2->next;
            ptr2 = ptr2->next;
        }
        else{
            ptr = ptr2;
            ptr2 = ptr2->next;
        }
    }
}

void print(){
    node *ptr = start;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
