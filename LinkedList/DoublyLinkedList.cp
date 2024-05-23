#include <stdio.h>
#include <stdlib.h>

typedef struct mynode{
    struct mynode* prev;
    int info;
    struct mynode* next;
} node;

node* start = NULL;
node* end = NULL;
int count = 0;

void insertAtBegining(int);
void insertAtEnd(int);
void insertAt(int, int);
void deleteFromBegining();
void deleteFromEnd();
void print();

void insertAtBegining(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL && end == NULL){
        start = end = newptr;
        // end = newptr;
        start->info = end->info = val;
    }
    else if(start == end){
        newptr->info = val;
        newptr->next = start;
        end->prev = newptr;
        start = newptr;
    }
    else{
        newptr->info = val;
        newptr->next = start;
        start->prev = newptr;
        start = newptr;
    }
    count++;
}

void insertAtEnd(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL && end == NULL){
        start = end = newptr;
        // end = newptr;
        start->info = end->info = val;
    }
    else if(start == end){
        newptr->info = val;
        newptr->prev = start;
        start->next = newptr;
        end = newptr;
    }
    else{
        newptr->info = val;
        newptr->prev = end;
        end->next = newptr;
        end = newptr;
    }
    count++;
}

void deleteFromBegining(){
    node *ptr = start;
    if(start == NULL && end == NULL){
        printf("Linked List is empty.");
    }
    else if(start->next == NULL){
        printf("Cannot delete, only one element present.");
    }
    else{
        start = ptr->next;
        start->prev = NULL;
        free(ptr);
    }
}

void deleteFromEnd(){
    node *ptr = end;
    if(start == NULL && end == NULL){
        printf("Linked List is empty.");
    }
    else if(start->next == NULL){
        printf("Cannot delete, only one element present.");
    }
    else{
        end = ptr->prev;
        end->next = NULL;
        free(ptr);
    }
}