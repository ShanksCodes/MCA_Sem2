#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* TOP = NULL;

void pushStack(char value);
char popStack();

int main() 
 {

    printf("\n----------------------------------------------------------\n\n");
    char str[100];
    int i=0,j=0;
    char reversed_str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; 
  
    for (i = 0; i < strlen(str); i++) 
        pushStack(str[i]);
    
    while (TOP != NULL) 
    reversed_str[j++] = popStack();
    
    reversed_str[j] = '\0'; 

    printf("The reversed string is: %s\n", reversed_str);

    printf("\n----------------------------------------------------------\n\n");
    return 0;
 }



void pushStack(char value) 
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 

    newNode->data = value;
    newNode->next = TOP;
    TOP = newNode;
 }

char popStack() 
 {
    if (TOP == NULL) 
     {
        printf("Stack is empty!\n");
        return '\0';
     }

    struct Node* temp = TOP;
    char val = temp->data;
    TOP = TOP->next;
    free(temp);
    return val;
 }
