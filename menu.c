#include <stdio.h>

int main_menu() {
  int option;

  printf("Main Menu.\n");
  printf("1) Register student.\n");
  printf("2) Register existent student grades.\n");
  printf("3) Check student status.\n");
  printf("4) View report.\n");
  printf("Choose an option: ");
  scanf("%d", &option);

  while (option < 0 || option > 5) {
    printf("Not a valid option, please choose again: ");
    scanf("%d", &option);
  }

  return option;
}

int get_student_menu() {
  int option;

  while (1) {
    printf("1) Registration.\n");
    printf("2) Name.\n");
    printf("Get student by?: ");
    scanf("%d", &option);

    if (option > 0 && option < 3)
      break;

    printf("Not a valid option, please try again.\n");
  }

  return option;
}
