#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
void pop() {
    top--;
}
int value(char x) {
    switch(x) {
        case 'i': 
            return 0;
        case '+':
            return 1;
        case '*':
            return 2;
        case '$':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        default:
            return 0;
    }
}
char Matrix[][6] = {
    {' ', '>', '>', '>', ' ', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '<', '<', ' ', '<', ' '},
    {'<', '<', '<', ' ', '<', '='},
    {' ', '>', '>', '>', ' ', '>'}
};
void main() {
    int i = 0;
    char a, b, c;
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);
    stack[++top] = '$';
    int length = strlen(input);
    input[length] = '$';
    input[length + 1] = '\0';
    while (top != -1) {
         a = stack[top];
         b = input[i];
         c = Matrix[value(a)][value(b)];
         if (a == '$' && b == '$') {
            printf("The string is accepted!\n");
            break;
         } else if (c == '<' || c == '=') {
            push(c);
            push(b);
            i++;
         } else if (c == '>') {
            while (top != -1 && stack[top] != '<')  pop();
            if (stack[top] == '<')  pop();
         } else {
            printf("The string is not accepted.\n");
            break;
         }
    }
}