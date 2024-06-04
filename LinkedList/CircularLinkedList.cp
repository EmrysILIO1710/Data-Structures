#include <stdio.h>
#include <stdlib.h>

typedef struct mynode{
    int info;
    struct mynode* link;
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
                    insertAt(pos, num);
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
    if(start == NULL){
        start = newptr;
        start->info = val;
        start->link = newptr;
        end = start;
    }
    else{
        newptr->info = val;
        newptr->link = start;
        start = newptr;
        end->link = start;
    }
    count++;
    // printf("%d elements present.\n");
    // printf("%d %d", start->info, start->link);
}

void insertAtEnd(int val){
    node *newptr = (node *)malloc(sizeof(node));
    if(start == NULL){
        start = newptr;
        start->info = val;
        start->link = NULL;
    }
    else{
        node *ptr = start;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newptr;
        newptr->info = val;
        newptr->link = start;
    }
    count++;
    // printf("%d elements present.\n");
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
    // printf("%d elements present.\n");
}

void deleteFromBegining(){
    node *ptr = start;
    if(start == NULL){
        printf("Linked list is empty.\n");
    }
    else if(start->link == NULL){
        printf("Cannot delete, only one element present.\n");
    }
    else{
        printf("%d deleted.\n", ptr->info);
        start = ptr->link;
        free(ptr);
    }
}

void deleteFromEnd(){
    node *ptr = start;
    node *prev;
    if(start == NULL){
        printf("Linked list is empty.\n");
    }
    else if(start->link == NULL){
        printf("Cannot delete, only one element present.\n");
    }
    else{
        while(ptr->link != NULL){
            prev = ptr;
            ptr = ptr->link;
        }
        printf("%d deleted.\n", ptr->info);
        free(ptr);
        prev->link = start;
    }
}

void print(){
    if(start == NULL){
        printf("The linked list is empty.\n");
    }
    else{
        printf("The linked list is: \n");
        node *ptr = start;
        while(ptr->link != start){
            printf("%d\t", ptr->info);
            ptr = ptr->link;
        }
        printf("%d\t", ptr->info);
        // printf("%d", ptr->info);
    }
}