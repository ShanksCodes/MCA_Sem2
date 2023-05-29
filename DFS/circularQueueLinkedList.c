#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*tail=NULL;
struct Node*head=NULL;

void traverseCircularQueue();
void cEnqueue(int value);
void cDequeue();

int lengthOfCircularQueue();


int main()
 {
    
    int element =0;
    int position = -1;
    int choice=0;
   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to traverse the circular queue.\n");
    printf("2. Press 2 to insert a new node at the end (enqueue).\n");
    printf("3. Press 3 to delete a node from the front (dequeue).\n");
    printf("4. Press 4 to find length of the queue:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nTraversing the circular linked list...\n");
               traverseCircularQueue();
               break;

       case 2: printf("\nInsertion from end(enqueue)\nEnter element to insert at the end: ");
               scanf("%d", &element);
               cEnqueue(element);
               break;

       case 3: printf("\nDeletion from front(dequeue)\n");
               cDequeue();
               break;
         
       case 4: printf("\nLength of the linked list: %d\n",lengthOfCircularQueue());
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

 void traverseCircularQueue()
  {
     struct Node*temp=head;
     struct Node*firstNode = head;

     if(tail==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

     while(temp->next!=firstNode) //usually it is temp->NULL as per standards, but change is to print -> effectively
      {
          printf("%d --> ",temp->data);
          temp=temp->next;
      }

     printf("%d",temp->data);
     
  }


  void cEnqueue(int value)
   {
    
      struct Node*newNode = NULL; 

      newNode=(struct Node*)malloc(sizeof(struct Node));
      newNode->data=value;
   
      if(tail==NULL)
        {
          newNode->next = newNode;
          tail= newNode;
          head= newNode;
          printf("\nNew node successfully inserted!");
          return;
        }
    
      newNode->next=head;
      tail->next=newNode;
      tail=newNode;
   }


  void cDequeue()
    {
      
      if(tail==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

      struct Node*temp=NULL;
      temp=head;
      tail->next = temp->next;
      head = temp->next;
      free(temp);
      printf("Node deleted from end successfully.");

    }

  
int lengthOfCircularQueue()
 {
   
   if(tail==NULL)
    return 0;
   
    struct Node*temp=head;
    struct Node*firstNode=head;

    int i=0;
    do
     {
        i++;
        temp=temp->next;
     }while(temp!=firstNode);

    return i;
 }
