#include "menu.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  student *classroom = NULL;
  student *class_student = NULL;
  int option;
  int status_ok;

  while (1) {
    option = main_menu();

    switch (option) {
    case 0:
      break;
    case 1:
      class_student = malloc(sizeof(student));
      if (class_student == NULL) {
        printf("Unable to add new student.\n");
        deallocate_class(classroom);
        return -1;
      }
      register_new_student(class_student);
      class_student->next = classroom;
      classroom = class_student;

      continue;
    case 2:
      option = get_student_menu();

      if (option == 1) {
        class_student = get_student_by_registration(classroom);

        if (class_student == NULL) {
          printf("The student does not exist.\n");
          continue;
        }

      } else {
        class_student = get_student_by_name(classroom);

        if (class_student == NULL) {
          printf("The student does not exist. Please try again.\n");
          continue;
        }
      }

      set_student_grade(class_student);

      continue;
    case 3:
      option = get_student_menu();

      if (option == 1) {
        class_student = get_student_by_registration(classroom);

        if (class_student == NULL) {
          printf("The student does not exist.\n");
          continue;
        }

      } else {
        class_student = get_student_by_name(classroom);

        if (class_student == NULL) {
          printf("The student does not exist. Please try again.\n");
          continue;
        }
      }

      show_student_status(class_student, 1);

      continue;
    case 4:
      if (classroom == NULL) {
        printf("No class student registered yet.\n");
        continue;
      }

      show_class_status(classroom);
      continue;
    }

    deallocate_class(classroom);
    return 0;
  }
}
