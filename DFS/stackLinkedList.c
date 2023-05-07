#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Node{
    int data;
    struct Node*next;
};


struct Node*TOP=NULL;

void printStack();
void pushStack(int value);
int popStack();
int peekStack();
int lengthOfStack();

int main()
 {
    
    int element =0;
    int choice=0;
    int size=-1;

   
  do{
    
    printf("\n----------------------------------------------------------\n\n");
    printf("1. Press 1 to print the stack.\n");
    printf("2. Press 2 to push onto stack.\n");
    printf("3. Press 3 to pop from stack.\n");
    printf("4. Press 4 to peek stack.\n");
    printf("5. Press 5 to find length of the stack:\n");

    printf("-1. Press -1 to exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
     {
       case 1: printf("\nStack is as follows from the top:\n");
               printStack();
               break;

       case 2: printf("\nEnter element to push onto stack: ");
               scanf("%d", &element);
               pushStack(element);
               break;

       case 3: element = popStack();
               if(element!=-1)
                printf("\nElement popped from top of stack. Value: %d", element);
               break;       
               
       case 4: printf("\nElement on top of stack. Value: %d", peekStack());
               break;

       case 5: size= lengthOfStack();
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

 void printStack()
  {
     struct Node*temp=TOP;

     if(TOP==NULL)
       {
         printf("\nLinked list is empty.\n");
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

 
 void pushStack(int value)
  {
      struct Node*newNode = (struct Node*)malloc(sizeof(struct Node)); 

      newNode->data=value;
      newNode->next=TOP;
      TOP=newNode;

      printf("\nNew node successfully pushed!");              
  }

  int popStack()
   {
      
      int val=0;
      if(TOP==NULL)
       {
         printf("\nStack is empty!\n");
         return -1;
       }

      struct Node*temp=NULL;
      temp=TOP;
      val=temp->data;
      TOP=TOP->next;
      free(temp);
      return val;
   }

 int peekStack()
  {
    if(TOP==NULL)
      {
        printf("\nStack is empty");
        return -1;
      }

    return TOP->data;
  }

  int lengthOfStack() 
   {
     struct Node*temp=TOP;
     int counter=0;
     if(TOP==NULL)
        return -1;

      
     while(temp!=NULL)
      {
        counter++;
        temp=temp->next;
      }

      return counter;
   }
   