/***************************************************************************
Implementing Stack using Arrays
***************************************************************************/
// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   
    if(stack == NULL)
    {
        printf("\n\n\n****************************************\n");    
        printf("output : \n");
        printf("The stack is empty \n");
        printf("****************************************\n");
        return INT_MIN;
    }

    return stack->top == stack->capacity - 1; 
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    if(stack == NULL)
    {
        printf("\n\n\n****************************************\n");
        printf("output : \n");
        printf("The stack is empty \n");
        printf("****************************************\n");
        return INT_MIN;
    }
   
    return stack->top == -1;  
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack)
{
    int data;

    if (isFull(stack))
        return;
    
    printf("\n\n\n****************************************\n");    
    printf("\nEnter the data to push : ");
    scanf("%d",&data);
    printf("****************************************\n");

    stack->array[++stack->top] = data;

    printf("\n\n\n****************************************\n");    
    printf("output : \n");
    printf("%d pushed to stack\n", data);
    printf("****************************************\n");
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;

    printf("\n\n\n****************************************\n");
    printf("output : \n");
    printf("%d popped from stack\n",stack->array[stack->top]);
    printf("****************************************\n");

    return stack->array[stack->top--];
}
 
// Function to get top item from stack
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;

    printf("\n\n\n****************************************\n");
    printf("output : \n");
    printf("%d peeked from stack\n",stack->array[stack->top]);
    printf("****************************************\n");

    return stack->array[stack->top];
}

// Function to get top item from stack
int print(struct Stack* stack)
{
    int i;
    if(stack == NULL)
    {
        printf("\n\n\n****************************************\n");
        printf("output : \n");
        printf("The stack is empty \n");
        printf("****************************************\n");
        return INT_MIN;
    }

    if (isEmpty(stack))
        return INT_MIN;

    printf("\n\n\n****************************************\n");    
    printf("output : \n");
    for(i = 0; i <= stack->top; i++)
       printf("%d\t", stack->array[i]);
    printf("\n");

    printf("****************************************\n");
}

// Driver program to test above functions
int main()
{
    struct Stack* stack = NULL;
    int choice = 1;
    int data,size;
    char newStack;
    while(choice != 0){
        printf("\n\n\n****************************************\n");
        printf(" 1 - Create stack\n");
        printf(" 2 - Push\n");
        printf(" 3 - Pop \n");
        printf(" 4 - Peek\n");
        printf(" 5 - Print\n");
        printf(" 6 - Delete stack\n");
        printf(" 99 - Exit\n");
        printf("****************************************\n");
        scanf("%d",&choice);
        switch(choice){
            case 99 : 
            if(stack != NULL){
                free(stack->array);           
                free(stack);
                stack = NULL;
            }
            else{
                printf("\n\n\n****************************************\n");    
                printf("output : \n");
                printf("The stack is not created\n");
                printf("****************************************\n");    
            }
            break;
            case 1 : 
            if(stack == NULL){
            printf("Enter the size of stack : ");
            scanf("%d",&size);
            stack = createStack(size);
            }
            else{
                printf("Do you want to delete old stack and create new  (Y/N) : ");    
                scanf("%c",&newStack);
                if(newStack == 'N' || newStack == 'n'){ 
                     printf("continuing with old stack\n");
                     printf("****************************************\n");    
                }
                else if(newStack == 'Y' || newStack == 'y'){
                     printf("Enter the size of stack : ");
                     scanf("%d",&size);
                     stack = createStack(size);
                }
                else{
                     printf("wrong input so continuing with old stack\n");
                     printf("****************************************\n");    
                }
            }

            break;
            case 2 :
            push(stack);
            break;
            case 3 : 
            pop(stack);
            break;
            case 4 :
            peek(stack);
            break;
            case 5 :
            print(stack);
            break;
            case 6:
            if(stack != NULL){
                free(stack->array);           
                free(stack);
                stack = NULL;
            }
            else{
                printf("\n\n\n****************************************\n");    
                printf("output : \n");
                printf("The stack is not created\n");
                printf("****************************************\n");    
            }
            break;
            default :
            break;
        }
    }

    return 0;
}
