#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* FRONT = NULL;
struct Node* REAR = NULL;


void push(int value);
int pop();
int peekStack();
void printStack();
int searchElement(int value);
int lengthOfStack();
int isEmpty();

void enqueue(int value);
int dequeue();

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push.\n");
    printf("3. Press 3 to pop.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to find an element in queue.\n");
    printf("6. Press 6 to find length of the stack:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nstack is as follows:\n");
               printStack();
               break;

       case 2: printf("\nEnter element to push: ");
               scanf("%d", &element);
               push(element);
               break;

       case 3: element = pop();
               if(element!=-1)
                printf("\nElement popped. Value: %d", element);
               break;       
               
       case 4: printf("\nElement at top of stack: %d", peekStack());
               break;       
      
       case 5: printf("\nEnter element to search in stack: ");
               scanf("%d", &element);
               pos = searchElement(element);
               if(pos==-1)
                printf("\nElement not found in queue");
               else
                printf("\nElement found at %dth node from the top(front node is 1st node)", pos);
               break;

       case 6: size= lengthOfStack();
               if(size==-1)
                  printf("\nStack is empty!");
               else
                printf("\nLength of the stack: %d",size);
               break;

       case -1: break;
       default: printf("\nInvalid entry!");    
                             
     }

       if(choice!=-1)
        {
          printf("\n\nPress any key to continue...");
          getch();
        }

   }while(choice!=-1);

   
    printf("\n----------------------------------------------------------\n\n");
    return 0;
 }

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (FRONT == NULL) {
        FRONT = newNode;
        REAR = newNode;
    } else {
        REAR->next = newNode;
        REAR = newNode;
    }
}

int dequeue() {
    int val = -1;
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return val;
    }

    struct Node* temp = FRONT;
    val = temp->data;
    FRONT = FRONT->next;
    free(temp);

    return val;
}

void printStack(){
    struct Node* temp = FRONT;

    if (temp == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

void push(int value) {
    // Dequeue all elements from the queue and enqueue them again
    int size = lengthOfStack();
    enqueue(value);
    for (int i = 0; i < size; i++) {
        int element = dequeue();
        enqueue(element);
    }
}

int pop() {
    return dequeue();
}

int peekStack() {
    if (isEmpty()) {
        printf("\nStack is empty!\n");
        return -1;
    }
    return FRONT->data;
}

int searchElement(int value) {
    int pos = 1;
    if (isEmpty()) {
        printf("\nStack is empty!\n");
        return -1;
    } else {
        struct Node* temp = FRONT;
        while (temp != NULL) {
            if (temp->data == value) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }
}

int lengthOfStack() {
    int count = 0;
    struct Node* temp = FRONT;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty() {
    return (FRONT == NULL);
}