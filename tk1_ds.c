#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
  char product[50];
  int qty;
  struct data *next, *prev;
} * head, *tail, *curr;

void clear();
void menu();
void view();
void pushHead(char product[], int qty);
void pop();
void popAll();
void addOrder();
void deleteOrder();

int main() {
  int option;

  do {
    clear();
    menu();
    scanf("%d", &option);
    fflush(stdin);

    switch (option) {
    case 1:
      view();
      fflush(stdin);
      break;

    case 2:
      addOrder();
      break;
      
    case 3:
      deleteOrder();
      break;
    
    default:
      break;
    }
  } while (option != 4);

  popAll();
  
  return 0;
}

void clear() {
  printf("\n\n\n\n");
}

void menu() {
  printf("====================== STOCK-ing Budi ATK ======================\n\n\n");
  printf("====================== \n");
  printf("1. View Product List\n");
  printf("2. Add new Product\n");
  printf("3. Take Product\n");
  printf("4. Exit\n");
  printf("\n\n >> Input menu: ");

}

void view() {
  int i = 0;
  clear();
  printf("====================== Order list ======================\n\n");
  printf("  | No.    | Name of Product                 | Quantity    | \n");
  printf("---------------------------------------------------------------\n");

  curr = head;
  while (curr) {
    i++;
    printf("  | %3d.  | %-30s  | %8d  | \n", i, curr->product, curr->qty);
    curr = curr->next;
  }

  if (i == 0) printf("There is no Products\n\n\n");
  else printf("---------------------------------------------------------------\n");
}

void pushHead(char product[], int qty) {
  curr = (struct data*)malloc(sizeof(struct data));

  strcpy(curr->product, product);
  curr->qty = qty;

  if (head == NULL) head = tail = curr;
  else {
    curr->next = head;
    head->prev = curr;
    head = curr;
  }

  head->prev = NULL;
  tail->next = NULL;
}

void pop() {
  struct data *temp;

  if (head != NULL) {
    if (curr == head) {
      head = head->next;
      free(curr);

      if (head != NULL) head->prev = NULL;
    } else if (curr == tail) {
      curr = tail;
      tail = tail->prev;
      free(curr);
      tail->next = NULL;
    } else {
      temp = head;

      while (temp->next != curr) {
        temp = temp->next;
      }
      
      curr->next->prev = curr->prev;
      temp->next = curr->next;
      free(curr);
    }
  }
}

void popAll() {
  while (head != NULL) {
    curr = head;
    head = head->next;
    free(curr);
  }
}

void addOrder() {
  char product[51];
  int qty;
  printf("\n\n\n");

  do {
    printf("Input name of Stock [3..30]: ");
    scanf("%50s", product);
    fflush(stdin);
  } while (strlen(product) < 3 || strlen(product) > 30);
  
  printf("\n");

  do {
    printf("Input Quantity of Stock [1..20]: ");
    scanf("%d", &qty);
    fflush(stdin);
  } while (qty < 1 || qty > 20);

  pushHead(product, qty);

  printf("\n\n\n === Add new Order Success === \n\n\n");
  getchar();
}

void deleteOrder() {
  int total = 0, pos, i;

  if (head == NULL) printf("\n\n\n === There is no stock in the list === \n\n\n");
  else {
    popAll();

    printf("\n\n\n === Take Ordeer Success === \n\n\n");
  }

  getchar();
  fflush(stdin);
}
