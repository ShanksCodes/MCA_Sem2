#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 50


int TOP1 = -1; // becomes rear for queue
int TOP2 = -1;
int FRONT = -1;
int REAR = -1;

struct Node {
    int data;
};

struct Node stack1[MAX_SIZE];
struct Node stack2[MAX_SIZE];

void printQueue();
void enqueue(int value);
int dequeue();
int peekQueue();
int searchElement(int);
int lengthOfQueue();

void pushStack1(int value);
int popStack1();
void pushStack2(int value);
int popStack2();


int main()
 {
    
    int element =0;
    int choice=0;
    int pos=-1;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the queue.\n");
    printf("2. Press 2 to enqueue.\n");
    printf("3. Press 3 to dequeue.\n");
    printf("4. Press 4 to peek queue.\n");
    printf("5. Press 5 to search an element in queue\n");
    printf("6. Press 6 to find length of the queue:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nQueue is as follows:\n");
               printQueue();
               break;

       case 2: printf("\nEnter element to enqueue: ");
               scanf("%d", &element);
               enqueue(element);
               break;

       case 3: element = dequeue();
               if(element!=-1)
                printf("\nElement dequeued. Value: %d", element);
               break;       
               
       case 4: printf("\nElement in front of queue. Value: %d", peekQueue());
               break;
               
       case 5: printf("\nEnter element to search in queue: ");
               scanf("%d", &element);
               pos = searchElement(element);
              
               if(pos==-1)
                printf("\nElement not found in queue");
               else  
               printf("\nElement found at array index(0 based) %d ", searchElement(element));
               break;

       case 6: printf("\nLength of the queue: %d",lengthOfQueue());
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

void pushStack1(int value) {

    stack1[++TOP1].data = value;
}

int popStack1() {
    int val = -1;
    if (TOP1 == -1) {
        printf("\nStack 1 is empty");
        return -1;
    } else {
        val = stack1[TOP1--].data;
        return val;
    }
}

void pushStack2(int value) {
    stack2[++TOP2].data = value;
}

int popStack2() {
    int val = -1;
    if (TOP2 == -1) {
        printf("\nStack 2 is empty");
        return -1;
    } else {
        val = stack2[TOP2--].data;
        return val;
    }
}

int isEmpty() {
    return (TOP1 == -1);
}

void printQueue() {
    int i = FRONT;

    if(isEmpty()) {
        printf("\nQueue is empty");
        return;
    }

    while (i<REAR) {
        printf("%d->", stack1[i].data);
        ++i;
    }

    printf("%d", stack1[i].data);
}

void enqueue(int value) {
    if (REAR == MAX_SIZE - 1) {
        printf("\nQueue overflow. Cannot enqueue!");
        return;
    }

    if (isEmpty())
        FRONT++;

    pushStack1(value);
    REAR++;

    printf("\nSuccessfully enqueued!");
}

int dequeue() {
    int val = -1;
    int dequeuedVal = -1;
    int i = FRONT;

    if (isEmpty()) {
        printf("\nQueue is empty");
        return -1;
    }

    if (FRONT == REAR) {
        val = popStack1();
        TOP1 = -1;
        FRONT = -1;
        REAR = -1;
        return val;
    }

    while (i<=REAR) {
        val = popStack1();
        pushStack2(val);
        i++;
    }

    dequeuedVal = popStack2(); // from stack 2

    while (TOP2!=-1) {
        val = popStack2();
        pushStack1(val);
    }

    --REAR;

    return dequeuedVal;
}

int peekQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty");
        return -1;
    }

    return stack1[FRONT].data;
}

int searchElement(int value) {
    int i = FRONT;
    while (i <= REAR) {
        if (stack1[i].data == value)
            return i;

        i++;
    }

    return -1;
}

int lengthOfQueue() {
    return REAR-FRONT + 1;
}


