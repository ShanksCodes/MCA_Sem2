#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 50

int FRONT=-1;
int REAR=-1;

struct Node{
    int data;
};


struct Node queueNode[MAX_SIZE];

void printQueue();
void enqueue(int value);
int dequeue();
int peekQueue();
int searchElement(int);
int lengthOfQueue();


int main()
 {
    
    int element =0;
    int choice=0;
    int pos=-1;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the queue.\n");
    printf("2. Press 2 to enque.\n");
    printf("3. Press 3 to dequeue.\n");
    printf("4. Press 4 to peek queue.\n");
    printf("5. Press 5 to search an element in queue\n");
    printf("6. Press 6 to find length of the queue:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nQueue:\n");
               printQueue();
               break;

       case 2: printf("\nEnter element to enqueue: ");
               scanf("%d", &element);
               enqueue(element);
               break;

       case 3: element = dequeue();
               if(element!=-1)
                printf("\nElement dequeue. Value: %d", element);
               break;       
               
       case 4: printf("\nElement in the front of queue: %d", peekStack());
               break;
               
       case 5: printf("\nEnter element to search in queue: ");
               scanf("%d", &element);
               pos = searchElement(element);
              
               if(pos==-1)
                printf("\nElement not found in queue");
               else  
               printf("\nElement found at array index(0 based) %d ", searchElement(element));
               break;

       case 6: printf("\nLength of queue: %d",lengthOfStack());
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

 void printQueue()
  {
     int i=TOP;

     while(i>=1)
       {
        printf("%d->", stackNode[i].data);
        --i;
       }
     printf("%d",stackNode[i].data);     
  }

 
 void enqueue(int value)
  {
     if(TOP==MAX_SIZE-1) 
        printf("\nStack overflow. Cannot push onto stack!");
               
     else
       {
        stackNode[++TOP].data = value;
        printf("\nSuccessfullly inserted onto stack!");
       }
   
  }

  int dequeue()
   {
     int val=-1;
     if(TOP==-1)
      {
        printf("\nStack is empty");
        return -1;
      }

     else
      val= stackNode[TOP--].data;
     return val;
   }

 int peekQueue()
  {
    if(TOP==-1)
      {
        printf("\nStack underflow. Cannot pop from stack");
        return -1;
      }

     else
      return stackNode[TOP].data;
  }

 int searchElement(int value)
  {
    int i=TOP;
    while(i-->=0)
     {
       if(stackNode[i].data==value)
        return i;       
     }

     return -1;
  } 

  int lengthOfQueue() 
   {
     return TOP+1;
   }
   

