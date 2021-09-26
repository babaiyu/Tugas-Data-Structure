#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY 0

typedef struct node
{
  int value;
  struct node *next;
} node;

typedef struct
{
  node *head;
  node *tail;
} queue;

struct Node *head = NULL;

void init_queue(queue *q)
{
  q->head = NULL; //head pertama empty
  q->tail = NULL; //tail pertama empty
}

bool enqueue(queue *q, int value)
{
  // Membuat node baru
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL)
    return false;
  newnode->value = value;
  newnode->next = NULL;

  // Jika ada tail, connect tail ke node baru
  if (q->tail != NULL)
  {
    q->tail->next = newnode;
  }
  q->tail = newnode;

  // Cek apakah head valid
  if (q->head == NULL)
  {
    q->head = newnode;
  }
  return true;
}

int dequeue(queue *q)
{
  //Cek apakah queue kosong/empty
  if (q->head == NULL)
    return QUEUE_EMPTY;

  //simpan head queue
  node *tmp = q->head;

  //simpan hasil yang akan kita return
  int result = tmp->value;
  q->head = q->head->next;
  if (q->head == NULL)
  {
    q->tail = NULL;
  }
  free(tmp);
  return result;
}

int main()
{

  queue q1, q2, q3;

  init_queue(&q1);
  init_queue(&q2);
  init_queue(&q3);

  enqueue(&q1, 56);
  enqueue(&q2, 78);
  enqueue(&q2, 23);
  enqueue(&q2, 988);
  enqueue(&q3, 13);

  int t, count = 0;
  while ((t = dequeue(&q2)) != QUEUE_EMPTY)
  {
    printf("t = %d\n", t);
    count++;
  }

  printf("Panjang antrian nya adalah : %d\n", count);
}