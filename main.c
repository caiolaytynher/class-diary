#include "menu.h"
#include "student.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  student classroom[MAX_STUDENTS];
  student *class_student;
  int class_size = 0;
  int option;

  while (1) {
    option = main_menu();

    switch (option) {
    case 0:
      break;
    case 1:
      if (class_size == MAX_STUDENTS) {
        printf("The max amount of students is %d, and is already satisfied.\n",
               MAX_STUDENTS);
        continue;
      }

      classroom[class_size] = create_new_student();
      class_size++;

      continue;
    case 2:
      option = get_student_menu();

      if (option == 1) {
        class_student = get_student_by_registration(classroom, class_size);

        if (class_student == NULL) {
          printf("The student does not exist.\n");
          continue;
        }

      } else {
        class_student = get_student_by_name(classroom, class_size);

        if (class_student == NULL) {
          printf("The student does not exist. Please try again.\n");
          continue;
        }
      }

      print_student(class_student);
      set_student_grade(class_student);
      print_student(class_student);

      continue;
    case 3:
      option = get_student_menu();

      if (option == 1) {
        class_student = get_student_by_registration(classroom, class_size);

        if (class_student == NULL) {
          printf("The student does not exist.\n");
          continue;
        }

      } else {
        class_student = get_student_by_name(classroom, class_size);

        if (class_student == NULL) {
          printf("The student does not exist. Please try again.\n");
          continue;
        }
      }

      show_student_status(class_student, 1);

      continue;
    case 4:
      if (class_size == 0) {
        printf("No class student registered yet.\n");
        continue;
      }

      show_class_status(classroom, class_size);
      continue;
    }

    return 0;
  }
}
