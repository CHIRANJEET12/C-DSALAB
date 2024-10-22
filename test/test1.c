#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char ch) {
    switch (ch) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void infixToPostfix(char infix[], char postfix[]) {
    int n = strlen(infix);
    char stack[100];
    int top = -1, k = 0;
    
    for (int i = 0; i < n; i++) {
        if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = '(';
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; 
        } else {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';  
}

void infixToPrefix(char infix[], char prefix[]) {
    int n = strlen(infix);
    
    for (int i = 0; i < n / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char postfix[100];
    infixToPostfix(infix, postfix);

    int m = strlen(postfix);
    for (int i = 0; i < m; i++) {
        prefix[i] = postfix[m - i - 1];
    }
    prefix[m] = '\0';  
}

int main() {
    char infix[] = "a*(b+c+d)";
    char prefix[100];

    infixToPrefix(infix, prefix);

    printf("Infix expression : %s\n", infix);
    printf("Prefix expression : %s\n", prefix);

    return 0;
}
