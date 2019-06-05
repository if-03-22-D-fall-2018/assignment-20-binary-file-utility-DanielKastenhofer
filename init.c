#include <stdio.h>

int main(int argc, char const *argv[]) {

  FILE* fd=fopen("students.dat","w+");
  int id = 1;

  fwrite(&id, sizeof(int), sizeof(int), fd);
  fclose(fd);

  return 0;
}
