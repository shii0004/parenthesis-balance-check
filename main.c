#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
  int size;
  int top;
  char * arr;
};

struct Stack * s;

int isEmpty() { // checks if stack is empty
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void push(char c) { // pushes into stack
  s->top++;
  s->arr[s->top] = c;
}

void pop() { // pops out of stack
  s->arr[s->top] = '\0';
  s->top--;
}

int isMatched(char expression[]) {
  for (int i = 0; expression[i] != '\0'; i++) { // running loop till null character
    if (expression[i] == '(') {
      push(expression[i]);
    } else if (expression[i] == ')') {
        if (isEmpty()) {
          return 0;
        }
      pop();
    }

  }
  if (isEmpty()) {
    return 1;
  } else {
    return 0;
  }
}

int main () {
  // input having parentheses
  char expression[] = "(1+2)";
  // creating empty stack
  s = (struct Stack *) malloc(sizeof(struct Stack));
  s->size = strlen(expression); // preventing stack overflow
  s->top = -1;
  s->arr = (char *) malloc(s->size * sizeof(char));

  if (isMatched(expression)) {
    printf("Parentheses are matched.\n");
  } else {
    printf("Parentheses are not matched.\n");
  }
}
