#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

char stack[MAX];
int top = -1;

// Push ke Stack
void push(char x) {
  stack[++top] = x;
}

// Pop Stack
char pop() {
  if (top == -1)
    return -1;
  else
    return stack[top--];
}

// Check aritmatika dari string yang diinput
int priority(char x) {
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  return 0;
}

// Convert Infix ke Postfix
int infixToPostfix(char *exp) {
  char *e, x;
  e = exp;

  printf("Infix to Postfix = ");

  while (*e != '\0') {
    // Menampilkan output pertama jika char berupa angka
    if (isalnum(*e))
      printf("%c", *e);

    // Mengambil prefix aritmatika
    else
    {
      while (priority(stack[top]) >= priority(*e))
        printf("%c", pop());
      push(*e);
    }
    e++;
  }

  // Menampilkan output terakhir untuk prefix aritmatika
  while (top != -1) {
    printf("%c", pop());
  }

  printf("\n");
  return 0;
}

// Convert Infix ke Prefix (Reverse dari Postfix)
int infixToPrefix(char *stack, char *exp) {
  int len, temp;
  char *e;

  len = strlen(stack);
  e = exp;

  // Mengambil output prefix aritmatika untuk pertama
  for (int i = 0; i < len / 2; i++) {
    temp = stack[i];
    stack[i] = stack[len - i - 1];
    stack[len - i - 1] = temp;
  }

  printf("Infix to Prefix = %s", stack);

  // Mengambil output prefix angka
  while (*e != '\0') {
    if (isalnum(*e))
      printf("%c", *e);

    e++;
  }

  printf("\n");
  return 0;
}

// Main Program
int main() {
  char exp[MAX];

  printf("Enter the expression : ");
  scanf("%s", exp);
  printf("\n");

  infixToPostfix(exp);
  infixToPrefix(stack, exp);

  return 0;
}