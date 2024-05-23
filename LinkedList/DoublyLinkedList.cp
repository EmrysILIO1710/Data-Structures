#include <stdio.h>
#include <stdlib.h>

typedef struct mynode{
    struct mynode* prev;
    int info;
    struct mynode* next;
} node;

node *start = NULL;
node *end = NULL;
int count = 0;

void insertAtBegining(int);
void insertAtEnd(int);
void insertAt(int, int);
void deleteFromBegining();
void deleteFromEnd();
void print();

int main(){
    int flag = 1;
    int num, pos, ch;
    while(flag){
        printf("\nEnter choice: \n");
        printf("1. Insert at begining\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from begining\n");
        printf("5. Delete from end\n");
        printf("6. Print\n");
        printf("7. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter a no.: \n");
                    scanf("%d", &num);
                    insertAtBegining(num);
                    break;
            case 2: printf("Enter a no.: \n");
                    scanf("%d", &num);
                    insertAtEnd(num);
                    break;
            case 3: printf("Enter a no.: \n");
                    scanf("%d", &num);
                    printf("Enter the position: \n");
                    scanf("%d", &pos);
                    insertAt(num, pos);
                    break;
            case 4: 
                    deleteFromBegining();
                    break;
            case 5: 
                    deleteFromEnd();
                    break;
            case 6: 
                    print();
                    break;
            case 7: flag = 0;
                    break;
            default: printf("Invalid choice...\n");
        }
    }
    return 0;
}

void insertAtBegining(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL && end == NULL){
        start = end = newptr;
        // end = newptr;
        start->info = end->info = val;
        start->next = end->next = NULL;
        start->prev = end->prev = NULL;
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
        start->next = end->next = NULL;
        start->prev = end->prev = NULL;
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

void insertAt(int val, int pos){
    node *newptr = (node *)malloc(sizeof(node));
    node *ptr = start;
    int i = 1;
    while(i < pos - 1){
        ptr = ptr->next;
        i++;
    }
    newptr->next = ptr->next;
    newptr->prev = ptr;
    ptr->next = newptr;
    newptr->info = val;
}


void deleteFromBegining(){
    node *ptr = start;
    if(start == NULL && end == NULL){
        printf("\nLinked List is empty.");
    }
    else if(start->next == NULL){
        printf("\nCannot delete, only one element present.");
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
        printf("\nLinked List is empty.");
    }
    else if(start->next == NULL){
        printf("\nCannot delete, only one element present.");
    }
    else{
        end = ptr->prev;
        end->next = NULL;
        free(ptr);
    }
}

void print(){
    if(start == NULL){
        printf("The linked list is empty.\n");
    }
    else{
        printf("The linked list is: \n");
        node *ptr = start;
        while(ptr != NULL){
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}