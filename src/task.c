#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

bool isBalanced( char* s)
{
    Stack* st = newStack();

    for (int i = 0; s[i] != '\0'; ++i) {
        char c = s[i];
        if ((c == '(' || c == '[' || c == '{')) {
            push(st, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(st)) {
                deleteStack(st);
                return false;
            }
            char t = pop(st);
            if ((c == ')' && t != '(') || (c == ']' && t != '[') || (c == '}' && t != '{')) {
                deleteStack(st);
                return false;
            }
        }
    }

    bool res = isEmpty(st);
    deleteStack(st);
    return res;
}

int main(void)
{
    char str[100];

    printf("строка: ");
    scanf("%s", str);

    if (isBalanced(str))
        printf("верно\n");
    else
        printf("неверно\n");

    return 0;
}