#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Node{
    int data;
    struct Node*next;
};


struct Node*TOP1 = NULL;
struct Node*TAIL1 = NULL;
struct Node*TOP2 = NULL;

void enqueue(int value);
int dequeue();
void printQueue();
int peekQueue();
int lengthOfQueue();
int searchElement(int);
int isEmpty();
void pushStack(int value, struct Node**);
int popStack(struct Node**);

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the queue.\n");
    printf("2. Press 2 to enqueue.\n");
    printf("3. Press 3 to dequeue.\n");
    printf("4. Press 4 to peek queue.\n");
    printf("5. Press 5 to find an element in queue.\n");
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
               
       case 4: printf("\nElement at front of queue: %d", peekQueue());
               break;       
      
       case 5: printf("\nEnter element to search in queue: ");
               scanf("%d", &element);
               pos = searchElement(element);
               if(pos==-1)
                printf("\nElement not found in queue");
               else
                printf("\nElement found at %dth node from the top(front node is 1st node)", pos);
               break;

       case 6: size= lengthOfQueue();
               if(size==-1)
                  printf("\nqueue is empty!");
               else
                printf("\nLength of the queue: %d",size);
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

void printQueue() {
    struct Node* temp = TOP1;

    if (temp == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void enqueue(int value) {

    while (TOP1 != NULL) {
        int element = popStack(&TOP1);
        pushStack(element, &TOP2);

    }
   pushStack(value, &TOP1);
   TAIL1 = TOP1;

    while (TOP2 != NULL) {
        int element = popStack(&TOP2);
        pushStack(element, &TOP1);
    }  
}

int dequeue() {
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return -1;
    }

    int front = TOP1->data;
    struct Node* temp = TOP1;
    TOP1 = TOP1->next;
    free(temp);

    return front;
}

int isEmpty() {
    return (TOP1 == NULL);
}

int lengthOfQueue() {
    if (isEmpty()) 
      return -1;

    int length = 0;
    struct Node* temp = TOP1;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;      
} 

int peekQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return -1;
      
    } else 
        return TOP1->data;    
}    


int searchElement(int value) {
    int pos=1;
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return -1;

    } else {
        struct Node* temp = TOP1;
        while (temp != NULL) {
            if (temp->data == value) 
                return pos;  
            temp = temp->next;
            pos++;
        }
        return -1;
    }
}   

void pushStack(int value, struct Node**TOP) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *TOP;
    *TOP = newNode;
}

int popStack(struct Node**TOP) {
    int val = -1;

    if (TOP != NULL) {
        struct Node* temp = *TOP;
        val = temp->data;
        *TOP = (*TOP)->next;
        free(temp);
    }

    return val;
}
