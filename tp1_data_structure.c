#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct SMahasiswa
{
  unsigned long int nim;
  unsigned char name[30];
  unsigned char major[50];
  struct node *next;
};

void insert();
void display();
void deleted();

typedef struct SMahasiswa MAHASISWA;

MAHASISWA *head_node, *first_node, *temp_node = 0, *prev_node, next_node;

int main(void)
{
  int option = 0;

  printf("Single Linked List - Data Mahasiswa\n");

  while (option < 4)
  {
    printf("Options\n");
    printf("1: Insert Data\n");
    printf("2: Display Data\n");
    printf("3: Pop Data\n");
    printf("Other Number: Exit Program\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      insert();
      break;

    case 2:
      display();
      break;

    case 3:
      deleted();
      break;

    default:
      break;
    }
  }

  return 0;
}

// Insert Data
void insert()
{
  MAHASISWA dMahasiswa;
  printf("============== INSERT Data Mahasiswa ============= \n");
  printf("NOTE: for input NAME & MAJOR, use CamelCase or Snake_case (no space) \n");

  printf("NIM: ");
  scanf("%lu", &dMahasiswa.nim);
  printf("Nama: ");
  scanf("%s", dMahasiswa.name);
  printf("Jurusan: ");
  scanf("%s", dMahasiswa.major);

  int nNim = 0;                               // counted nim
  unsigned long int realNim = dMahasiswa.nim; // save nim;

  // Count NIM
  do
  {
    ++nNim;
    dMahasiswa.nim = dMahasiswa.nim / 10;
  } while (dMahasiswa.nim);

  if (nNim != 10)
  {
    printf("NIM must have 10 digits! \n");
  }
  else if (strlen(dMahasiswa.name) > 30)
  {
    printf("Name must only 30 char below! \n");
  }
  else if (strlen(dMahasiswa.major) > 50)
  {
    printf("Major must only 50 char below! \n");
  }
  else
  {
    temp_node = (MAHASISWA *)malloc(sizeof(MAHASISWA));
    temp_node->nim = realNim;
    *temp_node->name = *dMahasiswa.name;
    *temp_node->major = *dMahasiswa.major;

    if (first_node == 0)
      first_node = temp_node;
    else
      head_node->next = temp_node;

    temp_node->next = 0;
    head_node = temp_node;
  }
  fflush(stdin);
}

// Display Data
void display()
{
  int count = 0;
  temp_node = first_node;
  printf("\n Display Data : \n");

  if (temp_node == 0)
  {
    printf("-- Empty List --");
  }
  else
  {
    while (temp_node != 0)
    {
      printf("# NIM = %lu \n", temp_node->nim);
      printf("# Name = %s \n", temp_node->name);
      printf("# Major = %s \n", temp_node->major);
      printf("###################################");

      count++;
      temp_node = temp_node->next;
    }
  }

  printf("\nNo of Items In Linked List : %d\n", count);
}

// Pop Data
void deleted()
{
  printf("============== DELETE Data Mahasiswa ============= \n");

  struct SMahasiswa *ptr, *ptr1;

  if (first_node == NULL)
  {
    printf("\nList is Empty\n");
  }
  else if (first_node->next == NULL)
  {
    first_node = NULL;
    free(first_node);
    printf("\nOnly node of the list deleted ...\n");
  }
  else
  {
    ptr = first_node;
    while (ptr->next != NULL)
    {
      ptr1 = ptr;
      ptr = ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
    printf("Popped Data at Last Node...\n");
  }
}