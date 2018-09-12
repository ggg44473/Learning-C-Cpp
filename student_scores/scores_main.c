#include "scores_function.h"

#define FNAME "scores.bin"

int main(int argc, char const *argv[]) {
  Student *students;
  int studentsCount;
  char action;
  int is_continued;

  readFile(FNAME, &students, &studentsCount);

  system("cls");
  printf("Welcome! Please choose an action.\n");

  do {
    printf(
        "------------------------------------"
        "-----------------------------------\n"
        "[C]Create  [L]List  [I]IdSearch  [U]Update  "
        "[D]Delete  [S]Save  [E]Exit\n");
    scanf("%c", &action);
    fflush(stdin);

    switch (action) {
      case 'C':
      case 'c':
        create(&students, &studentsCount);
        break;
      case 'L':
      case 'l':
        list(students, studentsCount);
        break;
      case 'I':
      case 'i':
        idSearch(students, studentsCount);
        break;
      case 'U':
      case 'u':
        update(students, studentsCount);
        break;
      case 'D':
      case 'd':
        delete(&students, &studentsCount);
        break;
      case 'S':
      case 's':
        saveFile(FNAME, &students, studentsCount);
        readFile(FNAME, &students, &studentsCount);
        break;
      case 'E':
      case 'e':
        is_continued = askExit();
        break;
      default:
        printf("Wrong action!\n");
        break;
    }
    if (action != 'E' && action != 'e') {
      is_continued = askContinue();
    }
  } while (is_continued);

  if (students) {
    free(students);
  }

  printf("\nBYE BYE :)\n");

  return 0;
}
