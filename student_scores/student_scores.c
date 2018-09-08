#include <stdio.h>
#include <stdlib.h>

struct _Student {
  int id;
  char name[10];
  int score_math;
  int score_english;
  float score_avrage;
};
typedef struct _Student Student;

void create();
void read();
void list(); //with sort
void update();
void delete();

int main(int argc, char const *argv[]) {
  Student *students;
  int s_number;

  students = (Student*)malloc(sizeof(Student)*s_number);
  free(students);

  // read

  // write
  return 0;
}
