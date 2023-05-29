#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



struct Node{
    int data;
    struct Node*next;
};


struct Node*HEAD=NULL;
struct Node*TAIL=NULL;

void printQueue();
void enqueue(int value);
int dequeue();
int peek();
int searchElement(int);
int lengthOfQueue();

int main()
 {
   
    int element =0;
    int choice=0;
    int size=-1;
    int pos=0;

   
  do{
   
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the queue.\n");
    printf("2. Press 2 to enqueue onto queue.\n");
    printf("3. Press 3 to dequeue from queue.\n");
    printf("4. Press 4 to peek queue.\n");
    printf("5. Press 5 to find an element in queue.\n");
    printf("6. Press 6 to find length of the queue:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nqueue is as follows from the top:\n");
               printQueue();
               break;

       case 2: printf("\nEnter element to enqueue onto queue: ");
               scanf("%d", &element);
               enqueue(element);
               break;

       case 3: element = dequeue();
               if(element!=-1)
                printf("\nElement dequeued from top of queue. Value: %d", element);
               break;      
               
       case 4: printf("\nElement at the last. Value: %d", peek());
               break;      
     
       case 5: printf("\nEnter element to search in queue: ");
               scanf("%d", &element);
               pos = searchElement(element);
               if(pos==-1)
                printf("\nElement not found in queue");
               else
                printf("\nElement found at %dth node from the top(top node is 1st node)", pos);
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

 void printQueue()
  {
     struct Node*temp=HEAD;

     if(HEAD==NULL)
       {
         printf("\nQueueis empty.\n");
         return;
       }

     while(temp->next!=NULL) //usually it is temp->NULL as per standards, but change is to print -> effectively
      {
          printf("%d --> ",temp->data);
          temp=temp->next;
      }

     printf("%d",temp->data);
     temp=temp->next;
  }

 
 void enqueue(int value)
  {
      struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
     
      newNode->data=value;
      newNode->next = NULL;
     
      if(!HEAD)
       {
         HEAD = newNode;
         TAIL = newNode;
       }
      else
       { 
        TAIL->next = newNode;
        TAIL = newNode;
       }
      printf("\nNew node successfully enqueued!");              
  }

  int dequeue()
   {
     
      int val=0;
      if(HEAD==NULL)
       {
         printf("\nQueue is empty!\n");
         return -1;
       }

      struct Node*temp=NULL;
      temp=HEAD;
      val=temp->data;
      HEAD=HEAD->next;
      free(temp);
      return val;
   }

 int peek()
  {
    if(HEAD==NULL)
      {
        printf("\nQueue is empty");
        return -1;
      }

    return HEAD->data;
  }


 int searchElement(int value)
  {
    int i=1;
    struct Node*temp=HEAD;
    if(HEAD==NULL)
     return -1;

    while(temp!=NULL)
     {
       if(temp->data==value)
        {
          return i;
        }
        i++;
        temp=temp->next;
     }
  }

  int lengthOfQueue()
   {
     struct Node*temp=HEAD;
     int counter=0;
     if(HEAD==NULL)
        return -1;

     
     while(temp!=NULL)
      {
        counter++;
        temp=temp->next;
      }

      return counter;
   }

   