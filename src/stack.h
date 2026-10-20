#pragma once

typedef struct Stack Stack;

// создать стек
Stack* newStack();

//добавить значение наи вершину стека
int push(Stack* stack, int value); 

/*бирает из стека элемент и возвращает его
 нужно проверять isEmpty перед вызовом */
int pop(Stack* stack); 

//проверка наличия значений в стеке 
int isEmpty(Stack* stack);

// удаление стека
void deleteStack(Stack* stack); 
