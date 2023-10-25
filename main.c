#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

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

char pop() { // pops out of stack
  if (isEmpty()) {
    return '\0';
  }
  char popped = s->arr[s->top];
  s->top--;
  return popped;
}

int isMatched(char exp[]) {
  for (int i = 0; exp[i] != '\0'; i++) { // running loop till null character
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      push(exp[i]);
    } else if ((exp[i] == ')' && s->arr[s->top] == '(') || (exp[i] == '}' && s->arr[s->top] == '{') || (exp[i] == ']' && s->arr[s->top] == '['))  {
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
  char exp[MAX_SIZE];
  printf("Write expression: ");
  scanf("%s", &exp);
  // creating empty stack
  s = (struct Stack *) malloc(sizeof(struct Stack));
  s->size = strlen(exp); // preventing stack overflow
  s->top = -1;
  s->arr = (char *) malloc(s->size * sizeof(char));

  if (isMatched(exp)) {
    printf("Parentheses are matched.\n");
  } else {
    printf("Parentheses are not matched.\n");
  }
}
