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
               
       case 4: element = peekQueue();
               if(element!=-1)
                printf("\nElement in the front of queue: %d", element);
               break;
               
       case 5: printf("\nEnter element to search in queue: ");
               scanf("%d", &element);
               pos = searchElement(element);
              
               if(pos==-1)
                printf("\nElement not found in queue");
               else  
               printf("\nElement found at array index(0 based) %d ", searchElement(element));
               break;

       case 6: printf("\nLength of queue: %d",lengthOfQueue());
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
     int i=FRONT;

     if(FRONT==-1 || FRONT>REAR)
      {
        printf("\nQueue is empty");
        return;
      }

     while(i<REAR)
       {
        printf("%d->", queueNode[i].data);
        ++i;
       }

     printf("%d", queueNode[i].data);     
  }

 
 void enqueue(int value)
  {
     if(REAR==MAX_SIZE-1) 
        printf("\nQueue overflow. Cannot enqueue!");

     else if(FRONT==-1 && REAR==-1)
       {
        FRONT=0;
        REAR=0;
        queueNode[FRONT].data = value;
       }
               
     else
       {
        queueNode[++REAR].data = value;
        printf("\nSuccessfullly enqued!");
       }
   
  }

  int dequeue()
   {
     int val=-1;
     if(FRONT==-1 || FRONT>REAR)
      {
        printf("\nQueue is empty");
        return -1;
      }

     else if(FRONT==REAR)
      {
        val = queueNode[FRONT].data;
        FRONT=-1;
        REAR=-1;
      } 
      

     else
      val= queueNode[FRONT++].data;
     return val;
   }

 int peekQueue()
  {
    if(FRONT==-1 || FRONT>REAR)
      {
        printf("\nQueue underflow. Cannot peek from queue");
        return -1;
      }

     else
      return queueNode[FRONT].data;
  }

 int searchElement(int value)
  {
    int i=FRONT;
    while(i++<=REAR)
     {
       if(queueNode[i].data==value)
        return i;       
     }

     return -1;
  } 

  int lengthOfQueue() 
   {
     if(FRONT==-1 || FRONT>REAR)
      return 0;

     return REAR-FRONT+1;
   }
   

