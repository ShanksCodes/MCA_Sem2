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
char peekStack();
int isOperator(char ch);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);

int main() {
    printf("----------------------------------------------------------\n\n");
    /* 
    sample input: ((A+B)*C-D)*E^F/G+H
    expected output: AB+C*D-E^F/G*+H+
    */
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    fgets(infix, 100, stdin);

    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);

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

char peekStack() 
 {
    if (TOP == NULL) 
     {
        printf("Stack is empty!\n");
        return '\0';
     }
    return TOP->data;
 }

int isOperator(char ch) 
  {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
     return 1;
    
    return 0;
  }

int precedence(char op) 
 {
    if (op == '^') 
        return 3;
    
    else if (op == '*' || op == '/') 
        return 2;
    
    else if (op == '+' || op == '-') 
        return 1;

    return 0;
 }


void infixToPostfix(char* infix, char* postfix) 
 {
    int i, j;
    char ch;
    
    for (i = 0, j = 0; infix[i] != '\0'; i++) 
     {
        if (infix[i] == '(') 
         pushStack(infix[i]);
        

        else if (infix[i] == ')') 
         {
            while (TOP != NULL && peekStack() != '(') 
                postfix[j++] = popStack();
            
            if (TOP == NULL) 
             {
                printf("Invalid expression: Unbalanced parentheses!\n");
                return;
             }
            popStack();
         }


        else if (isOperator(infix[i])) 
         {
            while (TOP != NULL && peekStack() != '(' && precedence(infix[i]) <= precedence(peekStack())) 
                postfix[j++] = popStack();
            
            pushStack(infix[i]);
         }


        else 
         postfix[j++] = infix[i];
        
    }

    while (TOP != NULL) 
     {
        if (TOP->data == '(') 
         {
            printf("Invalid expression: Unbalanced parentheses!\n");
            return;
         }

        postfix[j++] = popStack();
     }

    postfix[j] = '\0';
 }
