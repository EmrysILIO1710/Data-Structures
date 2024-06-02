//https://www.codechef.com/practice/course/linked-lists/LINKLISTF/problems/CRITLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *start = NULL;
node *tail = NULL;

void createList(int);
int countCrits();

int main(void) {
	// your code goes here
    int n, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        createList(x);
    }
    int res = countCrits();
    printf("%d", res);
}

void createList(int num){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL){
        newptr->data = num;
        newptr->next = NULL;
        newptr->prev = NULL;
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
        newptr->prev = tail;
        tail = newptr;
    }
}

int countCrits(){
    int count = 0;
    node *ptr = start->next;
    while(ptr->next != NULL){
        node *p = ptr->prev;
        node *n = ptr->next;
        if((ptr->data < p->data && ptr->data < n->data) || (ptr->data > p->data && ptr->data > n->data)){
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}
