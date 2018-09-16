#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Student {
  int id;
  char name[10];
  int math;
  int english;
  float average;
};
typedef struct _Student Student;

struct _CheckResult {
  int isExistedId;
  int idPosition;
};
typedef struct _CheckResult CheckResult;

int askExit();
int askContinue();
int getFileCount();
void readFile();
void saveFile();
CheckResult checkId();
void create();
void list(); // TODO sort
CheckResult idSearch();
void update();
void delete();

int askExit() {
  char answer;
  printf("Remember to SAVE!\nAre you sure to exit?[Y/N] ");
  scanf("%c", &answer);
  fflush(stdin);
  if (answer == 'Y' || answer == 'y') {
    return 0;
  } else {
    return 1;
  }
}

int askContinue() {
  char answer;
  printf("Continue?[Y/N] ");
  scanf("%c", &answer);
  fflush(stdin);
  if (answer == 'N' || answer == 'n') {
    return askExit();
  } else {
    return 1;
  }
}

int getFileCount(const char fname[]) {
  int count = 0;
  FILE *f = NULL;
  Student buffer[1];

  f = fopen(fname, "rb");
  if (f == NULL) {
    printf("\nFile open error.\n\n");
  } else {
    while (1) {
      fread(buffer, sizeof(Student), 1, f);
      // after read the eof, feof return true
      if (feof(f)) {
        break;
      }
      count++;
    }
  }
  fclose(f);
  return count;
}

void readFile(const char fname[], Student **pStudents, int *pCount) {
  FILE *f = NULL;

  *pCount = getFileCount(fname);

  f = fopen(fname, "rb");
  if (f == NULL) {
    printf("\nFile open error.\n\n");
  } else {
    // need not to typecasting in c
    *pStudents = malloc(sizeof(Student) * (*pCount));
    fread((*pStudents), sizeof(Student), *pCount, f);
  }
  fclose(f);
}

void saveFile(const char fname[], Student **pStudents, int studentsCount) {
  FILE *f = NULL;

  f = fopen(fname, "wb");
  if (f == NULL) {
    printf("\nFile open error.\n\n");
  } else {
    fwrite(*pStudents, sizeof(Student), studentsCount, f);
    printf("\nSaved!\n\n");
  }
  fclose(f);

  // It's dependent on readFile() with malloc().
  // How to improve it?
  free(*pStudents);
}

CheckResult checkId(int id, Student *students, int studentsCount) {
  CheckResult result;

  for (int i = 0; i < studentsCount; i++) {
    if (id == students[i].id) {
      result.isExistedId = 1;
      result.idPosition = i;
      return result;
    } else {
      result.isExistedId = 0;
    }
  }
  return result;
}

void create(Student **pStudents, int *pCount) {
  int id, math, english;
  char name[10];
  CheckResult result;
  Student *temp;

  do {
    printf("id = ? ");
    scanf("%d", &id);
    fflush(stdin);

    result = checkId(id, *pStudents, *pCount);

    if (result.isExistedId) {
      printf("The id has existed!\n");
    }
  } while (result.isExistedId);

  printf("name = ? ");
  scanf("%s", &name);
  fflush(stdin);
  printf("math = ? ");
  scanf("%d", &math);
  fflush(stdin);
  printf("english = ? ");
  scanf("%d", &english);
  fflush(stdin);

  temp = realloc(*pStudents, sizeof(Student) * (++*pCount));
  if (!temp) {
    printf("\nMemory ERROR!\n\n");
  } else {
    *pStudents = temp;

    (*pStudents)[*pCount - 1].id = id;
    strcpy((*pStudents)[*pCount - 1].name, name);
    (*pStudents)[*pCount - 1].math = math;
    (*pStudents)[*pCount - 1].english = english;
    (*pStudents)[*pCount - 1].average = (math + english) / 2.0f;
  }

  printf("\nCreated!\n\n");
}

void list(Student *students, int studentsCount) {
  printf("id\tname\tmath\tenglish\t\taverage\n");
  for (int i = 0; i < studentsCount; i++) {
    printf("%d\t%s\t%d\t%d\t\t%2.2f\n", students[i].id, students[i].name,
           students[i].math, students[i].english, students[i].average);
  }
  printf("\n");
}

CheckResult idSearch(Student *students, int studentsCount) {
  int id;
  CheckResult result;

  printf("id = ? ");
  scanf("%d", &id);
  fflush(stdin);

  result = checkId(id, students, studentsCount);

  if (result.isExistedId) {
    printf("id\tname\tmath\tenglish\t\taverage\n");
    printf("%d\t%s\t%d\t%d\t\t%2.2f\n", students[result.idPosition].id,
           students[result.idPosition].name, students[result.idPosition].math,
           students[result.idPosition].english,
           students[result.idPosition].average);
  } else {
    printf("No id found...\n");
  }

  return result;
}

void update(Student *students, int studentsCount) {
  CheckResult result;

  result = idSearch(students, studentsCount);

  if (result.isExistedId) {
    printf("name = ? ");
    scanf("%s", &students[result.idPosition].name);
    fflush(stdin);
    printf("math = ? ");
    scanf("%d", &students[result.idPosition].math);
    fflush(stdin);
    printf("english = ? ");
    scanf("%d", &students[result.idPosition].english);
    fflush(stdin);
    students[result.idPosition].average =
        (students[result.idPosition].math +
         students[result.idPosition].english) /
        2.0f;
    printf("\nUpdated!\n\n");
  }
}

void delete (Student **pStudents, int *pCount) {
  CheckResult result;
  char answer;
  Student *temp;

  result = idSearch(*pStudents, *pCount);

  if (result.isExistedId) {
    printf("Are you sure to DELETE? [Y/N] ");
    scanf("%c", &answer);
    fflush(stdin);
    if (answer == 'Y' || answer == 'y') {
      for (int i = result.idPosition; i < *pCount - 1; i++) {
        (*pStudents)[i] = (*pStudents)[i + 1];
      }
      temp = realloc(*pStudents, (*pCount - 1) * sizeof(Student));
      if (!temp) {
        printf("\nMemory ERROR!\n\n");
      } else {
        *pStudents = temp;
        --*pCount;
        printf("\nDeleted!\n\n");
      }
    }
  }
}