#include <stdio.h>
#include <ctype.h>
#define max 100

int top = -1, a[max];

// Function to push an element onto the stack
void push(char x) {
    a[++top] = x;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1)
        return -1;
    else
        return a[top--];
}

// Function to determine the precedence of operators
int prcd(char c) {
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
}

// Function to reverse a string
void reverse(char str[]) {
    int length = 0, i;
    while (str[length] != '\0')
        length++;

    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixtopostfix(char infix[max], char postfix[max]) {
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        temp = infix[i];
        if (isalnum(temp)) {
            postfix[j++] = temp;
        }
        else if (temp == '(') {
            push(temp);
        }
        else if (temp == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            while (top != -1 && prcd(a[top]) >= prcd(temp)) {
                postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

// Function to convert infix to prefix
void infixtoprefix(char infix[max], char prefix[max]) {
    char postfix[max];
    int i;  // Declare 'i' here to fix the issue

    // Reverse the infix expression
    reverse(infix);

    // Modify the infix expression to change '(' to ')' and vice versa
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the reversed infix to postfix
    infixtopostfix(infix, postfix);

    // Reverse the postfix to get the prefix expression
    reverse(postfix);

    // Copy the postfix result to prefix
    for (i = 0; postfix[i] != '\0'; i++) {
        prefix[i] = postfix[i];
    }
    prefix[i] = '\0'; // Null terminate the prefix string
}

int main() {
    char infix[max], prefix[max];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    printf("The infix expression is: %s\n", infix);
    infixtoprefix(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);
    return 0;
}
