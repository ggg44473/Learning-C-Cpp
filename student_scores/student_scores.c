#include <stdio.h>
#include <stdlib.h>

struct _Student {
  int id;
  char name[10];
  int score_math;
  int score_english;
  float score_average;
};
typedef struct _Student Student;

int getTotal();
void create();
void pre_create();
void read();
void list();  // TODO sort
void update();
void delete ();
int askContinue();

int main(int argc, char const *argv[]) {
  Student *students;
  int total;
  char action;
  int is_continued;
  char answer;

  total = getTotal("scores.bin");

  printf("Welcome! Please choose an action.\n");
  is_continued = 1;
  while (is_continued) {
    printf("[A]create [B]read [C]list [D]update [E]delete [F]exit\n");
    fflush(stdin);
    action = getchar();
    fflush(stdin);

    if (action == 'A') {
      pre_create(students, "scores.bin");
      is_continued = askContinue();

    } else if (action == 'B') {
      read(students, "scores.bin", total);
      is_continued = askContinue();

    } else if (action == 'C') {
      list(students, total, "scores.bin");
      is_continued = askContinue();

    } else if (action == 'D') {
      is_continued = askContinue();

    } else if (action == 'E') {
      is_continued = askContinue();

    } else if (action == 'F') {
      is_continued = 0;

    } else {
      printf("Command not found.\n");
      is_continued = 1;
    }
  }

  printf("BYE BYE :)");
  return 0;
}

int askContinue() {
  char answer;
  printf("Continue?[Y/N] ");
  fflush(stdin);
  scanf("%c", &answer);
  if (answer == 'N') {
    return 0;
  } else {
    return 1;
  }
}
int getTotal(char file[]) {
  FILE *f;
  Student student[1];
  int total = 0;

  f = fopen(file, "rb");
  if (f == NULL) {
    printf("File open error.\n");
  } else {
    while (!feof(f)) {
      fread(student, sizeof(Student), 1, f) == 1;
      total++;
    }
  }
  fclose(f);
  return total;
}

void create(Student *students, int s_number, char file[]) {
  FILE *f = NULL;

  f = fopen(file, "ab");
  if (f == NULL) {
    printf("File open error.\n");
  }

  fwrite(students, sizeof(Student), s_number, f);

  fclose(f);
}

void pre_create(Student *students, char file[]) {
  int s_number;
  printf("How many students do you want to create? ");
  scanf("%d", &s_number);

  students = (Student *)malloc(sizeof(Student) * s_number);

  for (int i = 0; i < s_number; i++) {
    printf("id = ? ");
    scanf("%d", &students[i].id);
    fflush(stdin);
    printf("name = ? ");
    scanf("%s", students[i].name);
    fflush(stdin);
    printf("math = ? ");
    scanf("%d", &students[i].score_math);
    fflush(stdin);
    printf("english = ? ");
    scanf("%d", &students[i].score_english);
    fflush(stdin);
    students[i].score_average =
        (students[i].score_math + students[i].score_english) / 2.0f;
  }

  create(students, s_number, file);

  free(students);
}

void read(Student *students, char file[], int total) {
  int s_number;
  int *ids;
  FILE *f = NULL;

  printf("How many students do you want to read? ");
  scanf("%d", &s_number);

  ids = (int *)malloc(sizeof(int) * s_number);

  printf(
      "Which id do you want to read?\nInput one and press enter for the "
      "next\n");

  printf("First? ");
  scanf("%d", &ids[0]);
  for (int i = 1; i < s_number; i++) {
    printf("Next? ");
    scanf("%d", &ids[i]);
  }

  f = fopen(file, "rb");
  if (f == NULL) {
    printf("File open error.\n");
  }
  students = (Student *)malloc(sizeof(Student) * total);
  fread(students, sizeof(Student), total, f);

  printf("id\tname\tmath\tenglish\taverage\n");
  for (int i = 0; i < s_number; i++) {
    for (int j = 0; j < total; j++) {
      if (ids[i] == students[j].id) {
        printf("%d\t%s\t%d\t%d\t%f\n", students[j].id, students[j].name,
               students[j].score_math, students[j].score_english,
               students[j].score_average);
      }
    }
  }

  fclose(f);
  free(ids);
  free(students);
}

void list(Student *students, int total, char file[]) {
  FILE *f = NULL;

  f = fopen(file, "rb");
  if (f == NULL) {
    printf("File open error.\n");
  }
  students = (Student *)malloc(sizeof(Student) * total);

  fread(students, sizeof(Student), total, f);

  printf("id\tname\tmath\tenglish\taverage\n");
  for (int i = 0; i < total; i++) {
    printf("%d\t%s\t%d\t%d\t%f\n", students[i].id, students[i].name,
           students[i].score_math, students[i].score_english,
           students[i].score_average);
  }

  fclose(f);
  free(students);
}

void update(Student *students, int s_number, char file[]) {
  FILE *f = NULL;

  f = fopen(file, "ab");
  if (f == NULL) {
    printf("File open error.\n");
  }

  fwrite(students, sizeof(Student), s_number, f);

  fclose(f);
}

void delete (Student *students, int s_number, char file[]) {
  FILE *f = NULL;

  f = fopen(file, "ab");
  if (f == NULL) {
    printf("File open error.\n");
  }

  fwrite(students, sizeof(Student), s_number, f);

  fclose(f);
}