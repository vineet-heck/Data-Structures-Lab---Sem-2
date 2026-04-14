#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isMatching(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int isBalanced(char* s) {
    top = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else {
            char popped = pop();
            if (!isMatching(popped, s[i]))
                return 0;
        }
    }
    return isEmpty();
}

int main() {
    char s[MAX];
    scanf("%s", s);

    if (isBalanced(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
