#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

typedef struct Stack Stack_def;

struct data{
int a;
char b;
int c;
};

struct data1{
int a;
char b;
};
struct Stack {
int position;
unsigned int capacity;
int *array;
};

struct Stack *createStack(unsigned int size) {
#if DEBUG == 1
printf("the size of struct Stack = %lu\n",sizeof(struct Stack));
printf("the size of struct Stack * = %lu\n",sizeof(struct Stack*));
#endif
struct Stack *stack = (struct Stack *) malloc (sizeof(struct Stack ));
stack->capacity = size;
stack->array = (int *)malloc(sizeof(stack->capacity * sizeof(int)));
stack->position = -1;
return stack;
}

int isFull(struct Stack *stack){
return ((stack->position == stack->capacity -1));
}

void push(struct Stack *stack,int data) {
if(isFull(stack)){
return;
}
stack->array[++stack->position] = data;
printf("pushed data : %d\n",data);
}

int isEmpty(struct Stack* stack){
return (stack->position == -1);
}
int pop(struct Stack* stack){
if(isEmpty(stack))
return -1;

printf("poped data : %d\n",stack->array[stack->position]);
return stack->array[stack->position--];
}

int peek(struct Stack* stack) {
printf("peeked data : %d\n",stack->array[stack->position]);
return stack->array[stack->position];
}
int main(){
struct Stack *stack = createStack(5);
struct Stack obj1;
struct Stack *obj2;
struct data1 d[10];
push(stack,10);
push(stack,20);
push(stack,30);
pop(stack);
peek(stack);
#if 0
obj2 = (struct Stack *)malloc(sizeof(struct Stack));
obj1.capacity = 10;
obj2->capacity = 30;
printf("obj1 = %d\n",obj1.capacity);
//*(obj2 + 4) = 30;
printf("obj2 = %d\n",obj2->capacity);
printf("addr obj2 = %d\n",obj2);
printf("addr obj2 cap = %d\n",&obj2->capacity);
printf("obj2 = %d\n",*(obj2+sizeof(int)));
printf("obj2 * = %p\n",obj2);
printf("data = %d\n",sizeof(struct data));
#endif
printf("data = %d\n",sizeof(struct data));
return 0;
}

