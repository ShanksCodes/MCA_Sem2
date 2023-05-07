#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    int coefficient;
    int exponent;
    struct Node*next;
};

struct Node*start1=NULL;
struct Node*start2=NULL;
struct Node*start3=NULL;

void deleteLists();
void traverseLinkedList(struct Node*);
void createPolynomial(struct Node**);
void addList();
void multiplyList();


int main()
 {
    
    int choice=0;

  do{
    
   // deleteLists();
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to create first polynomial expression.\n");
    printf("2. Press 2 to create second polynomial expression.\n");
    printf("3. Press 3 to add the linked lists.\n");
    printf("4. Press 4 to multiply the linked lists.\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {


       case 1: printf("\nFirst polynomial:\n");
               createPolynomial(&start1);
               break;
        
       case 2: printf("\nSecond polynomial:\n");
               createPolynomial(&start2);
               break;
             

       case 3: printf("\nFirst polynomial: ");
               traverseLinkedList(start1);
               printf("\nSecond polynomial: ");
               traverseLinkedList(start2);
               addList();
               printf("\nResultant: ");
               traverseLinkedList(start3);
               break;


       case 4: printf("\nFirst polynomial: ");
               traverseLinkedList(start1);
               printf("\nSecond polynomial: ");
               traverseLinkedList(start2);
               multiplyList();
               printf("\nResultant: ");
               traverseLinkedList(start3);
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

void deleteLists()
{
  struct Node*temp=start1;
  struct Node*temp2=start2;
  struct Node*temp3=start3;
  
  while(temp!=NULL)
   {
    start1=temp->next;
    free(temp);
    temp=start1;
   }

  while(temp2!=NULL)
   {
    start2=temp2->next;
    free(temp2);
    temp2=start2;
   }

  while(temp3!=NULL)
   {
    start3=temp3->next;
    free(temp3);
    temp3=start3;
   } 

  start1=NULL;
  start2=NULL;
  start3=NULL;
}

 void traverseLinkedList( struct Node*start)
  {
     struct Node*temp=start;

     if(start==NULL)
       {
         printf("\nLinked list is empty.\n");
         return;
       }

     while(temp->next!=NULL) //usually it is temp->NULL as per standards, but change is to print -> effectively
      {
          printf( "%dX^%d + ",temp->coefficient,temp->exponent);
          temp=temp->next;
      }

     printf( "%dX^%d\n",temp->coefficient,temp->exponent);
     temp=temp->next;
  }


 void createPolynomial(struct Node**start)
   {
      
    int coefficient=0,exponent=0;
    int choice=1;
    struct Node*tail=NULL;

    do
     {
      
       printf("\nEnter coefficient: ");
       scanf("%d",&coefficient);
       printf("\nEnter exponent: ");
       scanf("%d",&exponent);
       struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
       newNode->coefficient=coefficient;
       newNode->exponent=exponent;
       newNode->next=NULL;

       if(*start==NULL)
         {
          *start=newNode;
          tail=newNode;
         }

       else 
        {
          tail->next=newNode;
          tail=newNode;
        }  
      
      printf("\nEnter '1' to continue, other keys to exit: ");
      scanf("%d",&choice);
           
     } while (choice==1);
    
   }

void addList()
{
    struct Node*ptr1=start1;
    struct Node*ptr2=start2;
    struct Node*tail=NULL;

    while(ptr1!=NULL && ptr2!=NULL)
     {
        struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->next=NULL;

        if(ptr1->exponent > ptr2->exponent)
         {
            newNode->exponent=ptr1->exponent;
            newNode->coefficient=ptr1->coefficient;
            ptr1=ptr1->next;
         }

        else if(ptr1->exponent < ptr2->exponent)
         {
            newNode->exponent=ptr2->exponent;
            newNode->coefficient=ptr2->coefficient;
            ptr2=ptr2->next;
         }

        else //if both exponents are same
         {
            newNode->exponent=ptr1->exponent;
            newNode->coefficient=ptr1->coefficient+ptr2->coefficient;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
         }

        if(start3==NULL)
         {
            start3=newNode;
            tail=newNode;
         }
        else
         {
            tail->next=newNode;
            tail=newNode;
         }
    }

    //add the remaining terms of the longer polynomial
    while(ptr1!=NULL)
     {
        struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->exponent=ptr1->exponent;
        newNode->coefficient=ptr1->coefficient;
        newNode->next=NULL;

        tail->next=newNode;
        tail=newNode;

        ptr1=ptr1->next;
     }

    while(ptr2!=NULL)
     {
        struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->exponent=ptr2->exponent;
        newNode->coefficient=ptr2->coefficient;
        newNode->next=NULL;

        tail->next=newNode;
        tail=newNode;

        ptr2=ptr2->next;
     }
}

void multiplyList()
{
    struct Node* ptr1 = start1;
    struct Node* ptr2 = start2;
  //  struct Node* start3 = NULL;
    struct Node* tail = NULL;
    int exponent=0;
    int coefficient=0;

    while (ptr1 != NULL)
     {
        ptr2 = start2;
        while (ptr2 != NULL)
         {
             exponent = ptr1->exponent + ptr2->exponent;
             coefficient = ptr1->coefficient * ptr2->coefficient;

            // check if a node with the same exponent already exists
            struct Node* temp = start3;
            while (temp != NULL && temp->exponent != exponent)
                temp = temp->next;
            

            if (temp != NULL)
             {
                // node with the same exponent already exists, add the coefficient
                temp->coefficient += coefficient;
             }
           
            else
             {
                // create a new node
                struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
                newNode->exponent = exponent;
                newNode->coefficient = coefficient;
                newNode->next = NULL;

                if (start3 == NULL)
                 {
                    start3 = newNode;
                    tail = newNode;
                 }

                else
                 {
                    tail->next = newNode;
                    tail = newNode;
                 }
             }

            ptr2 = ptr2->next;
         }

        ptr1 = ptr1->next;
     }

}
