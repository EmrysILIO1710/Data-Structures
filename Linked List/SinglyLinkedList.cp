#include <stdio.h>
#include <stdlib.h>

typedef struct mynode{
    int info;
    struct mynode* link;
} node;

node* start = NULL;
int count = 0;

void insertAtBegining(int);
void insertAtEnd(int);
void insertAt(int, int);
void deleteFromBegining();
void deleteFromEnd();
void print();

void insertAtBegining(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL){
        start = newptr;
        start->info = val;
    }
    else{
        newptr->info = val;
        newptr->link = start;
        start = newptr;
    }
    count++;
    printf("%d elements present.");
}

void insertAtEnd(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL){
        start = newptr;
        start->info = val;
    }
    else{
        node *ptr = start;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newptr;
        newptr->info = val;
    }
    count++;
    printf("%d elements present.");
}

void insertAt(int pos, int val){
    node *newptr = (node *)malloc(sizeof(node));
    node *ptr = start;
    node *prev;
    int i = 1;
    while(i < pos - 1){
        ptr = ptr->link;
        i++;
    }
    newptr->link = ptr->link;
    ptr->link = newptr;
    newptr->info = val;
    count++;
    printf("%d elements present.");
}

void deleteFromBegining(){
    node *ptr = start;
    if(start == NULL){
        printf("Linked list od empty.");
    }
    else if(start->link == NULL){
        printf("Cannot delete, only one element present.");
    }
    else{
        printf("%d deleted.", ptr->info);
        start = ptr->link;
    }
}

void deleteFromEnd(){
    node *ptr = start;
    node *prev;
    if(start == NULL){
        printf("Linked list od empty.");
    }
    else if(start->link == NULL){
        printf("Cannot delete, only one element present.");
    }
    else{
        while(ptr->lint != NULL){
            prev = ptr;
            ptr = ptr->link;
        }
        free(ptr);
        prev->link = NULL;
    }
}

void print(){
    if(start == NULL){
        printf("The linked list is empty.");
    }
    else{
        node *ptr = start;
        while(ptr != NULL){
            printf("%d\t", ptr->info);
            ptr = ptr->link;
        }
        // printf("%d", ptr->info);
    }
}