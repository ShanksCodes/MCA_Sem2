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
int isLeftAssociative(char op);
void infixToPrefix(char* infix, char* prefix);
void reverseString(char* str);
void swapParentheses(char* str);

int main() {
    printf("----------------------------------------------------------\n\n");
    /* 
    sample input: K + L - M * N + (O^P) * W/U/V * T + Q
    expected output: ++-+K  L * M  N *//* ^OP  WUV  T  Q  
    */
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    fgets(infix, 100, stdin);

    infix[strcspn(infix, "\n")] = '\0';
    infixToPrefix(infix, postfix);
    printf("The prefix expression is: %s\n", postfix);

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
    if (TOP == NULL) {
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
        return 4;

    else if (op == '*' || op == '/')
        return 2;

    else if (op == '+' || op == '-')
        return 1;

    return 0;
 }

int isLeftAssociative(char op) 
 {
    if (op == '^')
        return 0;  // Right associative

    return 1;      // Left associative
 }

void infixToPrefix(char* infix, char* prefix) 
 {
    int i, j;
    char ch;

    reverseString(infix);
    swapParentheses(infix);

    for (i = 0, j = 0; infix[i] != '\0'; i++) 
     {
        if (infix[i] == '(')
            pushStack(infix[i]);

        else if (infix[i] == ')') 
         {
            while (TOP != NULL && peekStack() != '(')
                prefix[j++] = popStack();

            if (TOP == NULL)
              {
                printf("Invalid expression: Unbalanced parentheses!\n");
                return;
              } 
            popStack();
        }

        else if (isOperator(infix[i])) 
         {
            while (TOP != NULL && peekStack() != '(' && (precedence(infix[i]) < precedence(peekStack()) ||
                  (precedence(infix[i]) == precedence(peekStack()) && (!isLeftAssociative(infix[i]))))) 
                prefix[j++] = popStack();
            

            pushStack(infix[i]);
         }

        else
            prefix[j++] = infix[i];
     }

    while (TOP != NULL) 
     {
        if (TOP->data == '(') 
         {
            printf("Invalid expression: Unbalanced parentheses!\n");
            return;
         }

        prefix[j++] = popStack();
    }

    prefix[j] = '\0';

    reverseString(prefix);
}

void reverseString(char* str) 
 {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) 
     {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
     }
}

void swapParentheses(char* str) 
 {
    int i;
    char ch;

    for (i = 0; str[i] != '\0'; i++) 
     {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
     }
}
