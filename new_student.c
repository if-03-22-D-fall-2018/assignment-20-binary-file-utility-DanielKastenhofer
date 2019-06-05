#include "stdio.h"

#define length 64

int main(int argc, char const *argv[]) {
  char first_name[length];
  char last_name[length];
  int age;

  printf("First Name: ");
  scanf("%s", first_name);

  printf("Last Name: ");
  scanf("%s", last_name);

  printf("Age: ");
  scanf("%d", &age);

  FILE* fd = fopen("students.dat", "rw");
  int id = 0;

  fread(&id, sizeof(int), 1, fd);


  fseek(fd, 0, SEEK_END);
  fwrite(&id, sizeof(int), sizeof(int), fd);
  fwrite(first_name, sizeof(char), sizeof(first_name), fd);
  fwrite(last_name, sizeof(char), sizeof(last_name), fd);
  fwrite(&age, sizeof(int), sizeof(int), fd);
  fseek(fd, 0, SEEK_SET);
  id++;
  fwrite(&id, sizeof(int), sizeof(int), fd);

  fclose(fd);

  return 0;
}
